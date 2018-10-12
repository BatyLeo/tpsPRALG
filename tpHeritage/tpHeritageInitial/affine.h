#ifndef AFFINE_H
#define AFFINE_H

#include "polynome.h"

// f(x) = ax+b
class Affine: public Polynome
{
public:
    Affine(int a, int b): Polynome()
    {
        coefs.push_back(b);
        coefs.push_back(a);
    }
};

#endif // AFFINE_H
