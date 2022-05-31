#include "GoldFish.h"

GoldFish::GoldFish() : MammalsFish(), m_avgWeight(0), m_avgLength(0) {};

GoldFish::GoldFish(const char *color, int childs, float avgLifetime, float preg, float milk, int fin, int gills,
                   float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills),
                                             m_avgLength(avgL), m_avgWeight(avgW) {};

GoldFish::GoldFish(ifstream &in_file) : MammalsFish(in_file) {

}

GoldFish::~GoldFish() {

}

float GoldFish::GetWeight() const {
    return m_avgWeight;
}

float GoldFish::GetLength() const {
    return m_avgLength;
}
