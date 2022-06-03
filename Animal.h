#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal {
protected:
    Animal();//set the default color to GRAY and other params to 0
    Animal(const char *color, int childs, float avgLifetime);//init the Animal with a given attributes
//    Animal(Animal& a); // copy CTOR
    Animal(ifstream &in_file);//init the Animal from a binary file

public:
    virtual ~Animal();

public:
    const char *GetColor() const;//return the color of the animal
    int GetChildCount() const;//return the child count of the animal
    float GetLifetime() const;//return the life time of the animal
    void setColor(const char *color);

    virtual void Save(ofstream &out_file) const;

    virtual void Load(ifstream &in_file);

    virtual void SaveBin(ofstream &out_file) const;

    virtual void LoadBin(ifstream &in_file);

    virtual void saveAddition(ofstream &out_file) const = 0;

    virtual void saveAdditionBin(ofstream &out_file) const = 0;

    virtual void loadAddition(ifstream &in_file) = 0;

    virtual void loadAdditionBin(ifstream &in_file) = 0;

    virtual void saveType(ofstream &out_file) const = 0;

    // OPERATORS
    Animal &operator=(Animal &animal);

protected:
    char *m_color;
    int m_childCount;
    float m_avgLifetime;
};

#endif // ifndef