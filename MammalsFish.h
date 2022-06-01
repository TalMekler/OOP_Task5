#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills );//init the MammalsFish with a given attributes
	MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
	virtual ~MammalsFish();

    virtual void Save(ofstream &out_file) const;
    virtual void Load(ifstream &in_file);
    virtual void SaveBin(ofstream &out_file) const;
    virtual void LoadBin(ifstream &in_file);
    virtual void saveAddition(ofstream &out_file) const = 0;
    virtual void saveAdditionBin(ofstream &out_file) const = 0;
    virtual void loadAddition(ifstream &in_file) = 0;
    virtual void loadAdditionBin(ifstream &in_file) = 0;
};

#endif // ifndef