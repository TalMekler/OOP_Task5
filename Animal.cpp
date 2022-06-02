#include "Animal.h"

Animal::Animal() : m_color(nullptr) {
    setColor("GRAY");
    m_childCount = 0;
    m_avgLifetime = 0;
}

Animal::Animal(const char *color, int childs, float avgLifetime) : m_color(nullptr) {
    setColor(color);
    m_childCount = childs;
    m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream &in_file) : m_color(nullptr), m_avgLifetime(0), m_childCount(0) {
    Animal::LoadBin(in_file);
}

Animal::~Animal() {
    delete[] m_color;
}

const char *Animal::GetColor() const {
    return m_color;
}

int Animal::GetChildCount() const {
    return m_childCount;
}

float Animal::GetLifetime() const {
    return m_avgLifetime;
}

void Animal::setColor(const char *color) {
    delete[] m_color;
    m_color = strdup(color);
}

void Animal::Save(ofstream &out_file) const {
    saveType(out_file);
    out_file << endl;
    out_file << m_color << endl;
    out_file << m_childCount << endl;
    out_file << m_avgLifetime << endl;
}

void Animal::Load(ifstream &in_file) {
    char buff[200];
    in_file >> buff;
    setColor(buff);
    in_file >> m_childCount;
    in_file >> m_avgLifetime;
}

void Animal::SaveBin(ofstream &out_file) const {
    saveType(out_file);
    int len = strlen(m_color);
    out_file.write((char *) &len, sizeof(len));
    out_file.write(m_color, len);
    out_file.write((char *) &m_childCount, sizeof(m_childCount));
    out_file.write((char *) &m_avgLifetime, sizeof(m_avgLifetime));
}

void Animal::LoadBin(ifstream &in_file) {
    int len;
    char buff[200];
    in_file.read((char *) &len, sizeof(len));
    in_file.read(buff, len);
    setColor(buff);
    in_file.read((char *) &m_childCount, sizeof(m_childCount));
    in_file.read((char *) &m_avgLifetime, sizeof(m_avgLifetime));
}

void Animal::saveType(ofstream &out_file)const {
    out_file.write((char *) typeid(*this).name() + 1, 2);
}