#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();

public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;//return the gills count of the animal

    virtual void Save(ofstream &out_file) const;
    virtual void Load(ifstream &in_file);
    virtual void SaveBin(ofstream &out_file) const;
    virtual void LoadBin(ifstream &in_file);
    virtual void saveAddition(ofstream &out_file) const;
    virtual void saveAdditionBin(ofstream &out_file) const;
    virtual void loadAddition(ifstream &in_file);
    virtual void loadAdditionBin(ifstream &in_file);
protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef