#include "Birds.h"

Birds::Birds():Animal() {};

Birds::Birds(const char *color, int childs, float avgLifetime, float incubation):Animal(color, childs, avgLifetime), m_incubationTime(incubation) {};

Birds::Birds(ifstream &in_file) : Animal(in_file) {

}

Birds::~Birds() {

}

float Birds::GetIncubationTime() const {
    return m_incubationTime;
}
