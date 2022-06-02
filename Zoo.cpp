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
        Horse *h = dynamic_cast<Horse *>(an);
        tmpArr[m_numOfAnimals] = new Horse(*h);
    } else if (typeid(*an) == typeid(Flamingo)) {
        Flamingo *f = dynamic_cast<Flamingo *>(an);
        tmpArr[m_numOfAnimals] = new Flamingo(*f);
    } else if (typeid(*an) == typeid(GoldFish)) {
        GoldFish *gf = dynamic_cast<GoldFish *>(an);
        tmpArr[m_numOfAnimals] = new GoldFish(*gf);
    } else if (typeid(*an) == typeid(Mermaid)) {
        Mermaid *m = dynamic_cast<Mermaid *>(an);
        tmpArr[m_numOfAnimals] = new Mermaid(*m);
    }

    m_animals = tmpArr;
    tmpArr = nullptr;
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

void Zoo::Save(ofstream &ofs) const {
    ofs << m_name << endl;
    ofs << m_address << endl;
    ofs << m_ticketPrice << endl;
    ofs << m_openHours << endl;
    ofs << m_closeHours << endl;
    ofs << m_numOfAnimals << endl;
    // Save each animal and his type
    for (int i = 0; i < m_numOfAnimals; ++i) {
        m_animals[i]->Save(ofs);
    }
}

void Zoo::Load(ifstream &ifs) {
    char buff[200];
    ifs >> buff;
    m_name = strdup((buff));
    ifs >> buff;
    m_address = strdup((buff));
    ifs >> m_ticketPrice;
    ifs >> buff;
    m_openHours = strdup(buff);
    ifs >> buff;
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
    ofs.write((char *) &len, len);
    ofs.write(m_address, len);
    // save ticketPrice
    ofs.write((char *) &m_ticketPrice, sizeof(m_ticketPrice));
    // save open hours : char*
    len = strlen(m_openHours);
    ofs.write((char *) &len, len);
    ofs.write(m_openHours, len);
    // save close hours : char*
    len = strlen(m_closeHours);
    ofs.write((char *) &len, len);
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
    m_address = strdup(buffer);
    // load ticket price : float
    ifs.read((char *) &m_ticketPrice, sizeof(m_ticketPrice));
    // load open hours : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
    m_openHours = strdup(buffer);
    // load close hours : char*
    ifs.read((char *) &len, sizeof(len));
    ifs.read(buffer, len);
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
    ifs.read(type, 2);
    return type;
}

Animal *Zoo::makeObject(ifstream &ifs) {
    char *type;
    type = loadTypeTxt(ifs);

    if (strcmp(type, "Ho")) {
        Horse *h = new Horse();
        h->Load(ifs);
        delete[] type;
        return h;
    }
    if (strcmp(type, "Me")) {
        Mermaid *m = new Mermaid();
        m->Load(ifs);
        delete[] type;
        return m;
    }
    if (strcmp(type, "Go")) {
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

    if (strcmp(type, "Ho")) {
        Horse *h = new Horse(ifs);
        delete[] type;
        return h;
    }
    if (strcmp(type, "Me")) {
        Mermaid *m = new Mermaid(ifs);
        delete[] type;
        return m;
    }
    if (strcmp(type, "Go")) {
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
    return *this;
}
