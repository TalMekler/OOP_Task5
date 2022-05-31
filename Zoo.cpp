#include "Zoo.h"

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
    delete [] m_name;
    delete [] m_address;
    delete [] m_openHours;
    delete [] m_closeHours;
    for (int i = 0; i < m_numOfAnimals; ++i) {
        delete m_animals[i];
    }
    delete [] m_animals;
}
