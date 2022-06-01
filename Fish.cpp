#include "Fish.h"

Fish::Fish() : Animal(), m_finCount(0), m_gillsCount(0) {};

Fish::Fish(const char *color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime),
                                                                                   m_gillsCount(gills),
                                                                                   m_finCount(fin) {};

Fish::Fish(ifstream &in_file) : Animal(in_file) {
    Fish::loadAdditionBin(in_file);
}

Fish::~Fish() {

}

int Fish::GetFinCount() const {
    return m_finCount;
}

int Fish::GetGillsCount() const {
    return m_gillsCount;
}

void Fish::Save(ofstream &out_file) const {
    Animal::Save(out_file);
    saveAddition(out_file);
}

void Fish::Load(ifstream &in_file) {
    Animal::Load(in_file);
    loadAddition(in_file);
}

void Fish::SaveBin(ofstream &out_file) const {
    Animal::SaveBin(out_file);
    saveAdditionBin(out_file);
}

void Fish::LoadBin(ifstream &in_file) {
    Animal::LoadBin(in_file);
    loadAdditionBin(in_file);
}

void Fish::saveAddition(ofstream &out_file) const {
    out_file << m_finCount << " " << m_gillsCount << endl;
}

void Fish::saveAdditionBin(ofstream &out_file) const {
    out_file.write((char *) &m_finCount, sizeof(m_finCount));
    out_file.write((char *) &m_gillsCount, sizeof(m_gillsCount));
}

void Fish::loadAddition(ifstream &in_file) {
    in_file >> m_finCount;
    in_file >> m_gillsCount;
}

void Fish::loadAdditionBin(ifstream &in_file) {
    in_file.read((char *) &m_finCount, sizeof(m_finCount));
    in_file.read((char *) &m_gillsCount, sizeof(m_gillsCount));
}
