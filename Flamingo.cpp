#include "Flamingo.h"

Flamingo::Flamingo() : Birds(), m_avgHeight(0) {};

Flamingo::Flamingo(const char *color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color,
                                                                                                                childs,
                                                                                                                avgLifetime,
                                                                                                                incubation),
                                                                                                          m_avgHeight(
                                                                                                                  avgLifetime) {};

Flamingo::Flamingo(ifstream &in_file) : Birds(in_file) {
    Flamingo::loadAdditionBin(in_file);
}

Flamingo::~Flamingo() {

}

float Flamingo::GetHeight() const {
    return m_avgHeight;
}

void Flamingo::Save(ofstream &out_file) const {
    Birds::Save(out_file);
    saveAddition(out_file);
}

void Flamingo::Load(ifstream &in_file) {
    Birds::Load(in_file);
    loadAddition(in_file);
}

void Flamingo::SaveBin(ofstream &out_file) const {
    Birds::SaveBin(out_file);
    saveAdditionBin(out_file);
}

void Flamingo::LoadBin(ifstream &in_file) {
    Birds::LoadBin(in_file);
    loadAdditionBin(in_file);
}

void Flamingo::saveAddition(ofstream &out_file) const {
    out_file << m_avgHeight << endl;
}

void Flamingo::saveAdditionBin(ofstream &out_file) const {
    out_file.write((char *) &m_avgHeight, sizeof(m_avgHeight));
}

void Flamingo::loadAddition(ifstream &in_file) {
    in_file >> m_avgHeight;
}

void Flamingo::loadAdditionBin(ifstream &in_file) {
    in_file.read((char *) &m_avgHeight, sizeof(m_avgHeight));
}
