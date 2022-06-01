#include "MammalsFish.h"

MammalsFish::MammalsFish() :Mammals(), Fish() {};

MammalsFish::MammalsFish(const char *color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) : Mammals(color, childs, avgLifetime,preg, milk),
                                                                                                                         Fish(color, childs, avgLifetime,fin, gills) {};

MammalsFish::MammalsFish(ifstream &in_file) : Mammals(in_file), Fish(in_file) {

}

MammalsFish::~MammalsFish() {

}

void MammalsFish::Save(ofstream &out_file) const {
    Animal::Save(out_file);
    Mammals::saveAddition(out_file);
    Fish::saveAddition(out_file);
}

void MammalsFish::Load(ifstream &in_file) {
    Animal::Load(in_file);
    Mammals::loadAddition(in_file);
    Fish::loadAddition(in_file);
}

void MammalsFish::SaveBin(ofstream &out_file) const {
    Fish::SaveBin(out_file);
}

void MammalsFish::LoadBin(ifstream &in_file) {
    Mammals::LoadBin(in_file);
}
