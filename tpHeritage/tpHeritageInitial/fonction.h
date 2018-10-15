#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>

const float epsilon = 1e-5;

class Fonction
{
protected:
    Fonction* integrale;
public:
    Fonction(){integrale = 0;}      // Constructeur vide
    Fonction(Fonction* _integrale); // Constructeur pour le calcul de derivees de Trigo
    ~Fonction();

    virtual float operator()(float x) const; // evalue la fonction en x
    virtual Fonction* derivee() const{}      // renvoie la fonction derivee
    virtual float inverse(float y) const;    // renvoie l'image reciproque de y par la fonction
};



#endif // ELEVE_H
