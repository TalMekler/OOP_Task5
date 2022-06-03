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

Zoo::Zoo(const Zoo &z) {
    m_name = strdup(z.GetName());
    m_address = strdup(z.GetAddress());
    m_ticketPrice = z.GetTicketPrice();
    m_openHours = strdup(z.GetOpenHour());
    m_closeHours = strdup(z.GetCloseHour());
    m_numOfAnimals = 0;
    for (int i = 0; i < z.GetNumOfAnimals(); ++i) {
        AddAnimal(z.m_animals[i]);
    }
}

Zoo::Zoo(ifstream &in_file) : m_numOfAnimals(0) {
    Zoo::LoadBin(in_file);
}

Zoo::~Zoo() {
    delete[] m_name;
    delete[] m_address;
    delete[] m_openHours;
    delete[] m_closeHours;
//    for (int i = 0; i < m_numOfAnimals; ++i) {
//        delete m_animals[i];
//    }
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
    *this += an;
}

Zoo &Zoo::operator+(Animal *an) {
    Animal **tmp = new Animal *[m_numOfAnimals + 1];
    for (int i = 0; i < m_numOfAnimals; ++i) {
        tmp[i] = m_animals[i];
    }
    tmp[m_numOfAnimals] = an;
    m_animals = tmp;
    tmp = nullptr;
    m_numOfAnimals++;
    return *this;
}

Zoo Zoo::operator+(const Zoo &other) const {
    Zoo newZ(*this); // Using copy CTOR
    //Copy m_animals -> deep copy
    for (int i = 0; i < other.m_numOfAnimals; ++i) {
        newZ.AddAnimal(other.m_animals[i]);
    }
//    newZ.m_numOfAnimals = other.GetNumOfAnimals();
    return newZ;
}

void Zoo::Save(ofstream &ofs) const {
    ofs << m_name << endl;
    ofs << m_address << endl;
    ofs << m_ticketPrice << endl;
    ofs << m_openHours << endl;
    ofs << m_closeHours << endl;
    ofs << m_numOfAnimals; ///TODO: changed here
    // Save each animal and his type
    for (int i = 0; i < m_numOfAnimals; ++i) {
        m_animals[i]->Save(ofs);
    }
}

void Zoo::Load(ifstream &ifs) {
    char buff[200];
    ifs.getline(buff, 200);
    m_name = strdup((buff));

    ifs.getline(buff, 200);
    m_address = strdup((buff));
    ifs >> m_ticketPrice;
    ifs.read(buff, 1);
    ifs.getline(buff, 200);
    m_openHours = strdup(buff);
    ifs.getline(buff, 200);
    m_closeHours = strdup(buff);
    ifs >> m_numOfAnimals;
    char *type;
    m_animals = new Animal *[m_numOfAnimals];
    for (int i = 0; i < m_numOfAnimals; ++i) {
        /// TODO: load each animal
        m_animals[i] = makeObject(ifs);
    }

}

void Zoo::SaveBin(ofstream &ofs) const {
    // save name : char*
    int len = strlen(m_name);
    ofs.write((char *) &len, sizeof(len));
    ofs.write(m_name, len);
    // save address : char*
    len = strlen(m_address);
    ofs.write((char *) &len, sizeof(len));
    ofs.write(m_address, len);
    // save ticketPrice
    ofs.write((char *) &m_ticketPrice, sizeof(m_ticketPrice));
    // save open hours : char*
    len = strlen(m_openHours);
    ofs.write((char *) &len, sizeof(len));
    ofs.write(m_openHours, len);
    // save close hours : char*
    len = strlen(m_closeHours);
    ofs.write((char *) &len, sizeof(len));
    ofs.write(m_closeHours, len);
    // save num of animals : int
    ofs.write((char *) &m_numOfAnimals, sizeof(m_numOfAnimals));
    // save each animal
    for (int i = 0; i < m_numOfAnimals; ++i) {
        m_animals[i]->SaveBin(ofs);
    }
}

void Zoo::LoadBin(ifstream &ifs) {
    int len;
    char buffer[200];
    // load name : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
    m_name = strdup(buffer);
    // load address : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
    buffer[len] = '\0';
    m_address = strdup(buffer);
    // load ticket price : float
    ifs.read((char *) &m_ticketPrice, sizeof(m_ticketPrice));
    // load open hours : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
    buffer[len] = '\0';
    m_openHours = strdup(buffer);
    // load close hours : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
    buffer[len] = '\0';
    m_closeHours = strdup(buffer);
    // load num of animals : int
    ifs.read((char *) &m_numOfAnimals, sizeof(m_numOfAnimals));
    // load each animal
    m_animals = new Animal *[m_numOfAnimals];
    for (int i = 0; i < m_numOfAnimals; ++i) {
        m_animals[i] = makeObjectBin(ifs);
    }

}

char *Zoo::loadTypeTxt(ifstream &ifs) {
    char *type = new char[3];
    ///TODO: CMD here
//    ifs.read(type, 1); ///
    ifs.read(type, 2);
    return type;
}

Animal *Zoo::makeObject(ifstream &ifs) {
    char *type;
    type = loadTypeTxt(ifs);

    if (strcmp(type, "Ho") == 0) {
        Horse *h = new Horse();
        h->Load(ifs);
        delete[] type;
        return h;
    }
    if (strcmp(type, "Me") == 0) {
        Mermaid *m = new Mermaid();
        m->Load(ifs);
        delete[] type;
        return m;
    }
    if (strcmp(type, "Go") == 0) {
        GoldFish *g = new GoldFish();
        g->Load(ifs);
        delete[] type;
        return g;
    }

    Flamingo *f = new Flamingo();
    f->Load(ifs);
    delete[] type;
    return f;

}

Animal *Zoo::makeObjectBin(ifstream &ifs) {
    char *type;
    type = loadTypeTxt(ifs);

    if (strcmp(type, "Ho") == 0) {
        Horse *h = new Horse(ifs);
        delete[] type;
        return h;
    }
    if (strcmp(type, "Me") == 0) {
        Mermaid *m = new Mermaid(ifs);
        delete[] type;
        return m;
    }
    if (strcmp(type, "Go") == 0) {
        GoldFish *g = new GoldFish(ifs);
        delete[] type;
        return g;
    }
    Flamingo *f = new Flamingo(ifs);
    delete[] type;
    return f;

}

Zoo &Zoo::operator+=(Animal *an) {
    Animal **tmp = new Animal *[m_numOfAnimals + 1];
    for (int i = 0; i < m_numOfAnimals; ++i) {
        tmp[i] = m_animals[i];
    }
    if (typeid(*an) == typeid(Horse)) {
        Horse *h = dynamic_cast<Horse *>(an);
        tmp[m_numOfAnimals] = new Horse(*h);
    } else if (typeid(*an) == typeid(Mermaid)) {
        Mermaid *m = dynamic_cast<Mermaid *>(an);
        tmp[m_numOfAnimals] = new Mermaid(*m);
    } else if (typeid(*an) == typeid(GoldFish)) {
        GoldFish *gl = dynamic_cast<GoldFish *>(an);
        tmp[m_numOfAnimals] = new GoldFish(*gl);
    } else if (typeid(*an) == typeid(Flamingo)) {
        Flamingo *fl = dynamic_cast<Flamingo *>(an);
        tmp[m_numOfAnimals] = new Flamingo(*fl);
    }

    m_animals = tmp;
    tmp = nullptr;
    m_numOfAnimals++;
    return *this;
}

ofstream &operator<<(ofstream &out, const Zoo &z) {
    z.Save(out);
    return out;
}

ifstream &operator>>(ifstream &in, Zoo &z) {
    z.Load(in);
    return in;
}