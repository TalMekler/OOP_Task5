#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Horse.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Mermaid.h"

class Zoo
{
public:
	Zoo();//default c'tor  - all to 0 or null
	Zoo( const char* name, const char* address, float ticket, const char* open, const char* close );//c'tor with data - init class
	Zoo( ifstream& in_file );//c'tor that gets a binary file and loads the data of the zoo from the file
	virtual ~Zoo();//d'tor

public:
	const char*		GetName() const;//return the name of the zoo
	const char*		GetAddress() const;//return the address of the zoo
	float			GetTicketPrice() const;//return the ticket price of the zoo
	const char*		GetOpenHour() const;//return the open hour of the zoo
	const char*		GetCloseHour() const;//return the close hour of the zoo
	int				GetNumOfAnimals() const;//return the num of animals in the zoo
	Animal**		GetAnimals() const;//return the animals array of the zoo

public:
	void AddAnimal( Animal* an );//creates a copy of "an" (deep copy) and adds an animal to the array

public:
	Zoo& operator+( Animal* an );//adds an animal (only pointer, no copy needed) to the class and returns this with the change
	Zoo operator+( const Zoo& other ) const; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
    Zoo& operator+=( Animal* an);

public:
	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
	friend ifstream& operator >> ( ifstream& in, Zoo& z );//operator to read the zoo from a text file

public:
	void Save( ofstream& ofs ) const;//method to save the info to a text file
	void Load( ifstream& ifs );//method to load the info from a text file
	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file
    void LoadBin( ifstream& ifs );

    char* loadTypeTxt(ifstream& ifs);
    Animal* makeObject(ifstream& ifs);
    Animal* makeObjectBin(ifstream& ifs);

private:
	char*		m_name;
	char*		m_address;
	float		m_ticketPrice;
	char*		m_openHours;
	char*		m_closeHours;
	int			m_numOfAnimals;
	Animal**	m_animals;
};

ofstream& operator<<( ofstream& out, const Zoo& z ) {
    z.Save(out);
    return out;
}
ifstream& operator >> ( ifstream& in, Zoo& z ) {
    z.Load(in);
    return in;
}

#endif // ifndef