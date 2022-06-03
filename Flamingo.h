#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds {
public:
    Flamingo();//set the default color to GRAY and other params to 0
    Flamingo(const char *color, int childs, float avgLifetime, float incubation,
             float avgHeight);//init the Flamingo with a given attributes
    Flamingo(ifstream &in_file);//init the Flamingo from a binary file
    Flamingo(const Flamingo& other);
    virtual ~Flamingo();

public:
    float GetHeight() const;//return the avg height of the flamingo

    virtual void Save(ofstream &out_file) const;
    virtual void Load(ifstream &in_file);
    virtual void SaveBin(ofstream &out_file) const;
    virtual void LoadBin(ifstream &in_file);
    virtual void saveAddition(ofstream &out_file) const;
    virtual void saveAdditionBin(ofstream &out_file) const;
    virtual void loadAddition(ifstream &in_file);
    virtual void loadAdditionBin(ifstream &in_file);

protected:
    float m_avgHeight;
};

#endif // ifndef