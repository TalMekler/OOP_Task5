#include "Horse.h"

Horse::Horse() : Mammals(), m_type(nullptr) {};

Horse::Horse(const char *color, int childs, float avgLifetime, float preg, float milk, const char *type) : Animal(color,
                                                                                                                  childs,
                                                                                                                  avgLifetime),
                                                                                                           Mammals(
                                                                                                                   color,
                                                                                                                   childs,
                                                                                                                   avgLifetime,
                                                                                                                   preg,
                                                                                                                   milk) {
    m_type = strdup(type);
}

Horse::Horse(ifstream &in_file) :Animal(in_file) ,Mammals(in_file) {
    Horse::loadAdditionBin(in_file);
}

Horse::Horse(const Horse &other) : Animal(other.GetColor(), other.m_childCount, other.m_avgLifetime),
                                    Mammals(other.GetColor(), other.m_childCount, other.m_avgLifetime, other.m_pregnancyTime, other.m_milkLiters),
                                    m_type(nullptr) {
    setType(other.m_type);
}

Horse::~Horse() {
    delete[] m_type;
}

const char *Horse::GetType() const {
    return m_type;
}

void Horse::Save(ofstream &out_file) const {
    Mammals::Save(out_file);
    Horse::saveAddition(out_file);
}

void Horse::Load(ifstream &in_file) {
    Mammals::Load(in_file);
    Horse::loadAddition(in_file);
}

void Horse::SaveBin(ofstream &out_file) const {
    Mammals::SaveBin(out_file);
    Horse::saveAdditionBin(out_file);
}

void Horse::LoadBin(ifstream &in_file) {
    Mammals::LoadBin(in_file);
    Horse::loadAdditionBin(in_file);
}

void Horse::saveAddition(ofstream &out_file) const {
    out_file << m_type << endl;
}

void Horse::saveAdditionBin(ofstream &out_file) const {
    int len = strlen(m_type);
    out_file.write((char *) &len, sizeof(len));
    out_file.write(m_type, len);
}

void Horse::loadAddition(ifstream &in_file) {
    char buff[200];
    in_file.getline(buff, 200);
    in_file.getline(buff, 200);
    setType(buff);
}

void Horse::loadAdditionBin(ifstream &in_file) {
    int len;
    char buff[200];
    in_file.read((char *) &len, sizeof(len));
    in_file.read(buff, len);
    setType(buff);
}

void Horse::setType(const char *type) {
//    delete[] m_type;
    m_type = strdup(type);
}

void Horse::saveType(ofstream &out_file) const {
//    cout<<"Horse saveType: "<<typeid(this).name();
    out_file.write((char*)"Ho", 2);
}
