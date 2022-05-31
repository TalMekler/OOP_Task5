#include "Animal.h"

Animal::Animal() {
    m_color = strdup("GRAY");
    m_childCount = 0;
    m_avgLifetime = 0;
}

Animal::Animal(const char *color, int childs, float avgLifetime) {
    m_color = strdup(color);
    m_childCount = childs;
    m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream &in_file) {

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
