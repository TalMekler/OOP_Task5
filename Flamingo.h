#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo( const char* color, int childs, float avgLifetime, float incubation, float avgHeight );//init the Flamingo with a given attributes
	Flamingo( ifstream& in_file );//init the Flamingo from a binary file
	virtual ~Flamingo();

public:
	float		GetHeight() const;//return the avg height of the flamingo

protected:
	float m_avgHeight;
};

#endif // ifndef