#include "Fish.h"

Fish::Fish() : Animal(), m_finCount(0), m_gillsCount(0) {};

Fish::Fish(const char *color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime),
                                                                                   m_gillsCount(gills),
                                                                                   m_finCount(fin) {};

Fish::Fish(ifstream &in_file) : Animal(in_file) {

}

Fish::~Fish() {

}

int Fish::GetFinCount() const {
    return m_finCount;
}

int Fish::GetGillsCount() const {
    return m_gillsCount;
}
