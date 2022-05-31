#include "Zoo.h"
#include "Horse.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Mermaid.h"

Zoo::Zoo() : m_name(nullptr), m_address(nullptr), m_ticketPrice(0), m_animals(nullptr), m_closeHours(nullptr),
             m_numOfAnimals(0), m_openHours(
                nullptr) {};

Zoo::Zoo(const char *name, const char *address, float ticket, const char *open, const char *close) {
    m_name = strdup(name);
    m_address = strdup(address);
    m_ticketPrice = ticket;
    m_openHours = strdup(open);
    m_closeHours = strdup(close);
    m_numOfAnimals = 0;
    m_animals = nullptr;
}

Zoo::Zoo(ifstream &in_file) {
    int len;
    // m_name
    in_file.read((char *) &len, sizeof(len));
    m_name = new char[len + 1];
    in_file.read(m_name, len);
    // m_address
    in_file.read((char *) &len, sizeof(len));
    m_address = new char[len + 1];
    in_file.read(m_address, len);
    // m_ticketPrice
    in_file.read((char *) &m_ticketPrice, sizeof(m_ticketPrice));
    // m_openHours
    in_file.read((char *) &len, sizeof(len));
    m_openHours = new char[len + 1];
    in_file.read(m_openHours, len);
    // m_closeHours
    in_file.read((char *) &len, sizeof(len));
    m_closeHours = new char[len + 1];
    in_file.read(m_closeHours, len);
    // m_numOfAnimals
    in_file.read((char *) &m_numOfAnimals, sizeof(m_numOfAnimals));
    // m_animals
    in_file.read((char *) &len, sizeof(len));
    m_animals = new Animal *[len];
}

Zoo::~Zoo() {
    delete[] m_name;
    delete[] m_address;
    delete[] m_openHours;
    delete[] m_closeHours;
    for (int i = 0; i < m_numOfAnimals; ++i) {
        delete m_animals[i];
    }
    delete[] m_animals;
}

const char *Zoo::GetName() const {
    return m_name;
}

const char *Zoo::GetAddress() const {
    return m_address;
}

float Zoo::GetTicketPrice() const {
    return m_ticketPrice;
}

const char *Zoo::GetOpenHour() const {
    return m_openHours;
}

const char *Zoo::GetCloseHour() const {
    return m_closeHours;
}

int Zoo::GetNumOfAnimals() const {
    return m_numOfAnimals;
}

Animal **Zoo::GetAnimals() const {
    return m_animals;
}

void Zoo::AddAnimal(Animal *an) {
    Animal **tmpArr = new Animal *[m_numOfAnimals + 1];
    for (int i = 0; i < m_numOfAnimals; ++i) {
        tmpArr[i] = m_animals[i];
    }

    if (typeid(*an) == typeid(Horse)) {
        Horse* h = dynamic_cast<Horse*>(an);
        tmpArr[m_numOfAnimals] = new Horse(*h);
    }else if (typeid(*an) == typeid(Flamingo)) {
        Flamingo* f = dynamic_cast<Flamingo*>(an);
        tmpArr[m_numOfAnimals] = new Flamingo(*f);
    } else if(typeid(*an) == typeid(GoldFish)) {
        GoldFish* gf = dynamic_cast<GoldFish*>(an);
        tmpArr[m_numOfAnimals] = new GoldFish(*gf);
    } else if(typeid(*an) == typeid(Mermaid)) {
        Mermaid* m = dynamic_cast<Mermaid*>(an);
        tmpArr[m_numOfAnimals] = new Mermaid(*m);
    }

    m_animals = tmpArr;
    tmpArr=nullptr;
    m_numOfAnimals++;
}

Zoo &Zoo::operator+(Animal *an) {
    AddAnimal(an); // add animal to the animals arr (deep copy)
    return *this;
}

Zoo Zoo::operator+(const Zoo &other) const {
    Zoo newZ(other.GetName(), other.GetAddress(), other.GetTicketPrice(), other.GetOpenHour(), other.GetCloseHour());
    newZ.m_numOfAnimals = 0;
    //Copy m_animals -> deep copy
    for (int i = 0; i < m_numOfAnimals; ++i) {
        newZ.AddAnimal(m_animals[i]);
    }
    newZ.m_numOfAnimals = other.GetNumOfAnimals();
    return Zoo();
}
