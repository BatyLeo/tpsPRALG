#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <assert.h>

class Matrice
{
private:
    int n;         // nombre de lignes
    int m;         // nombre de colonnes
    double* tab;   // tableau des coefficients de la matrice
    int* compteur; // nombre de partages du tableau des coefficients
private:
    double get(int i, int j) const;    // permet d'acceder en lecture a l'element (i,j) dans les methodes publiques
    double& get(int i, int j);         // permet d'acceder en ecriture a l'element (i,j) dans les methodes publiques
public:
    Matrice(int n0, int m0);   // constructeur : matrice de taille (n0 x m0)
    Matrice(const Matrice& B); // constructeur par copie
    ~Matrice();                // destructeur

    double operator ()(int i, int j) const {return get(i,j);} // accesseur en lecture a l'element (i,j)
    double& operator ()(int i, int j){return get(i,j);}       // accesseur en ecriture a l'element (i,j)
    int get_n() const {return n;}         // accede au nombre de lignes
    int get_m() const {return m;}         // accede au nombre de colonnes
    void print(int i, int j) const;       // affiche l'element (i,j)
    Matrice operator *(const Matrice& B); // multiplication matricielle
    void operator =(const Matrice& B);    // operateur= creant une copie de B dans un autre emplacement memeoire
    void affiche() const;                 // affiche la matrice
};


#endif // MATRICE_H
