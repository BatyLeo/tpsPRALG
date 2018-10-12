#include "fonction.h"

Fonction::Fonction(Fonction *_integrale)
{
    integrale = _integrale;
}

float Fonction::operator()(float x) const
{
    // Cette fonction n'est appelee que si integrale != Null
    assert(integrale);
    // On calcule la derivee de integrale evaluee en x par difference finie
    return ((*integrale)(x + epsilon)-(*integrale)(x - epsilon))/2/epsilon;
}

float Fonction::inverse(float y) const
{
    // On calcule inverse(y) par methode de Newton
    float inverse = 1;
    Fonction* derive = derivee();
    // 100 iterations maximum
    for (int i = 0; i < 100; ++i)
    {
        float dx = (y - (this->operator ()(inverse)))/(*derive)(inverse);
        inverse = inverse + dx;
        // si inverse a ete modifie de moins de epsilon, on s'arrete
        if (std::abs(dx) <= epsilon)
            return inverse;
    }
    return inverse;
}
