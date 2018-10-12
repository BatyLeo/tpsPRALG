#include "trigo.h"

Trigo::Trigo(std::string _nom)
{
    assert(_nom == "cos" || _nom == "sin" || _nom == "tan");
    nom = _nom;
}

float Trigo::operator ()(float x) const
{

    if (nom == "cos")
        return std::cos(x);
    if (nom == "sin")
        return std::sin(x);
    // else (nom == "tan")
    return std::tan(x);
}

Fonction* Trigo::derivee() const
{
    if (nom == "sin")
        return new Trigo("cos");

    // else
    Trigo* integralE = new Trigo(nom);
    Fonction* derivee = new Fonction(integralE);

    return derivee;
}
