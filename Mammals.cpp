#include "Mammals.h"

Mammals::Mammals() : Animal(), m_milkLiters(0), m_pregnancyTime(0) {};

Mammals::Mammals(const char *color, int childs, float avgLifetime, float preg, float milk) : Animal(color, childs, avgLifetime), m_pregnancyTime(preg), m_milkLiters(milk) {};

Mammals::Mammals(ifstream &in_file) : Animal(in_file) {
    Mammals::loadAdditionBin(in_file);
}

Mammals::~Mammals() {

}

float Mammals::GetPregnanceTime() const {
    return m_pregnancyTime;
}

float Mammals::GetMilk() const {
    return m_milkLiters;
}

void Mammals::Save(ofstream &out_file) const {
    Animal::Save(out_file);
    Mammals::saveAddition(out_file);
}

void Mammals::Load(ifstream &in_file) {
    Animal::Load(in_file);
    Mammals::loadAddition(in_file);
}

void Mammals::SaveBin(ofstream &out_file) const {
    Animal::SaveBin(out_file);
    Mammals::saveAdditionBin(out_file);
}

void Mammals::LoadBin(ifstream &in_file) {
    Animal::LoadBin(in_file);
    Mammals::loadAdditionBin(in_file);
}

void Mammals::saveAddition(ofstream &out_file) const {
    out_file << m_pregnancyTime<<" "<<m_milkLiters<<endl;
}

void Mammals::saveAdditionBin(ofstream &out_file) const {
    out_file.write((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
    out_file.write((char*)&m_milkLiters, sizeof(m_milkLiters));
}

void Mammals::loadAddition(ifstream &in_file) {
    in_file >> m_pregnancyTime;
    in_file >> m_milkLiters;
}

void Mammals::loadAdditionBin(ifstream &in_file) {
    in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
    in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
}
