#ifndef TRIGO_H
#define TRIGO_H

#include "fonction.h"

class Trigo: public Fonction
{
private:
    std::string nom;
public:
    Trigo(std::string _nom);
    float operator ()(float x) const;
    Fonction* derivee() const;
};

#endif // TRIGO_H
