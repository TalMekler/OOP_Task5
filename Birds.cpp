#include "Birds.h"

Birds::Birds() : Animal(), m_incubationTime(0) {};

Birds::Birds(const char *color, int childs, float avgLifetime, float incubation) : Animal(color, childs, avgLifetime),
                                                                                   m_incubationTime(incubation) {};

Birds::Birds(ifstream &in_file) : Animal(in_file) {
    Birds::loadAdditionBin(in_file);
}

Birds::~Birds() {

}

float Birds::GetIncubationTime() const {
    return m_incubationTime;
}

void Birds::Save(ofstream &out_file) const {
    Animal::Save(out_file);
    saveAddition(out_file);
}

void Birds::Load(ifstream &in_file) {
    Animal::Load(in_file);
    loadAddition(in_file);
}

void Birds::SaveBin(ofstream &out_file) const {
    Animal::SaveBin(out_file);
    saveAdditionBin(out_file);
}

void Birds::LoadBin(ifstream &in_file) {
    Animal::LoadBin(in_file);
    loadAdditionBin(in_file);
}

void Birds::saveAddition(ofstream &out_file) const {
    out_file << m_incubationTime << endl;
}

void Birds::saveAdditionBin(ofstream &out_file) const {
    out_file.write((char *) &m_incubationTime, sizeof(m_incubationTime));
}

void Birds::loadAddition(ifstream &in_file) {
    in_file >> m_incubationTime;
}

void Birds::loadAdditionBin(ifstream &in_file) {
    in_file.read((char *) &m_incubationTime, sizeof(m_incubationTime));
}
