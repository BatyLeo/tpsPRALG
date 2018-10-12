#include "polynome.h"

Polynome::Polynome(std::vector<float> _coefs)
{
    coefs = _coefs;
}

float Polynome::operator()(float x) const
{
    float pDeX = 0;
    for (int i = 0; i < coefs.size(); ++i)
        pDeX += coefs[i] * std::pow(x, i);
    return pDeX;
}

Fonction* Polynome::derivee() const
{
    int newDegre = coefs.size() - 1;
    std::vector<float> coefsDerivee;
    for (int i = 0; i < newDegre; ++i)
        coefsDerivee.push_back(coefs[i + 1] * (i+1));

    return new Polynome(coefsDerivee);
}
