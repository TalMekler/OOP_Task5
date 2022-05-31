#include "MammalsFish.h"

MammalsFish::MammalsFish() :Mammals(), Fish() {};

MammalsFish::MammalsFish(const char *color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) : Mammals(color, childs, avgLifetime,preg, milk),
                                                                                                                         Fish(color, childs, avgLifetime,fin, gills) {};

MammalsFish::MammalsFish(ifstream &in_file) : Mammals(in_file) {

}

MammalsFish::~MammalsFish() {

}
