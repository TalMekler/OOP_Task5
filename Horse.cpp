#include "Horse.h"

Horse::Horse() : Mammals(), m_type(nullptr) {};

Horse::Horse(const char *color, int childs, float avgLifetime, float preg, float milk, const char *type): Mammals(color, childs, avgLifetime, preg, milk) {
    m_type = strdup(type);
}

Horse::Horse(ifstream &in_file) : Mammals(in_file) {

}

Horse::~Horse() {
    delete[] m_type;
}

const char *Horse::GetType() const {
    return m_type;
}
