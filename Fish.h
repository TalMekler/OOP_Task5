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

protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef