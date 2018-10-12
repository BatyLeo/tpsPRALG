#ifndef POLYNOME_H
#define POLYNOME_H

#include "fonction.h"


class Polynome: public Fonction
{
protected:
    std::vector<float> coefs; // liste des coefficients (dans l'ordre croissant des puissances)
public:
    Polynome(){}
    Polynome(std::vector<float> _coefs);

    virtual float operator()(float x) const;
    virtual Fonction* derivee() const;
};

#endif // POLYNOME_H
