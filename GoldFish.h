#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL );//init the GoldFish with a given attributes
	GoldFish( ifstream& in_file );//init the GoldFish from a binary file
	virtual ~GoldFish();

public:
	float		GetWeight() const;//return the avg weight of the gold fish
	float		GetLength() const;//return the avg length of the gold fish

protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef