#include "Mermaid.h"

Mermaid::Mermaid() : MammalsFish(), m_firstName(nullptr), m_lastName(nullptr) {

}

Mermaid::Mermaid(const char *color, int childs, float avgLifetime, float preg, float milk, int fin, int gills,
                 const char *firstName, const char *lastName) :Animal(color, childs, avgLifetime) ,MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_lastName(
        nullptr),m_firstName(nullptr) {
    setFirstName(firstName);
    setLastName(lastName);
}

Mermaid::Mermaid(ifstream &in_file) : MammalsFish(in_file) {
    Mermaid::loadAdditionBin(in_file);
}

Mermaid::~Mermaid() {
    delete[] m_firstName;
    delete[] m_lastName;
}

const char *Mermaid::GetFirstName() const {
    return m_firstName;
}

const char *Mermaid::GetLastName() const {
    return m_lastName;
}

void Mermaid::setFirstName(const char *firstName) {
    delete[] m_firstName;
    m_firstName = strdup(firstName);
}

void Mermaid::setLastName(const char *lastName) {
    delete[] m_lastName;
    m_lastName = strdup(lastName);
}

void Mermaid::Save(ofstream &out_file) const {
    MammalsFish::Save(out_file);
    Mermaid::saveAddition(out_file);
}

void Mermaid::Load(ifstream &in_file) {
    MammalsFish::Load(in_file);
    Mermaid::loadAddition(in_file);
}

void Mermaid::SaveBin(ofstream &out_file) const {
    MammalsFish::SaveBin(out_file);
    Mermaid::saveAdditionBin(out_file);
}

void Mermaid::LoadBin(ifstream &in_file) {
    MammalsFish::LoadBin(in_file);
    Mermaid::loadAdditionBin(in_file);
}

void Mermaid::saveAddition(ofstream &out_file) const {
    out_file << m_firstName << " "<<m_lastName<<endl;
}

void Mermaid::saveAdditionBin(ofstream &out_file) const {
    int len = strlen(m_firstName);
    out_file.write((char*)&len, sizeof (len));
    out_file.write(m_firstName, len);
    len = strlen(m_lastName);
    out_file.write((char*)&len, sizeof (len));
    out_file.write(m_lastName, len);
}

void Mermaid::loadAddition(ifstream &in_file) {
    char buff[200];
    in_file >> buff;
    setFirstName(buff);
    in_file >> buff;
    setLastName(buff);
}

void Mermaid::loadAdditionBin(ifstream &in_file) {
    int len;
    char buff[200];
    in_file.read((char*)&len, sizeof (len));
    in_file.read(buff, len);
    setFirstName(buff);
    in_file.read((char*)&len, sizeof (len));
    in_file.read(buff, len);
    setLastName(buff);
}
