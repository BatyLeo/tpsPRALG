#include "matrice.h"

Matrice::Matrice(int n0, int m0)
{
    assert(n0 > 0 && m0 > 0);
    std::cout << "Appel du constructeur" << std::endl;

    n = n0;
    m = m0;
    tab = new double[n*m];
    compteur = new int;
    *compteur = 1;
}

Matrice::Matrice(const Matrice &B)
{
    std::cout << "Appel du constructeur par copie" << std::endl;

    n = B.n; m = B.m;
    tab = B.tab;
    compteur = B.compteur;
    // On incremente le compteur
    (*compteur)++;
}

Matrice::~Matrice()
{
    std::cout << "Appel du destructeur" << std::endl;

    // S'il n'y a plus de copie de la matrice on libere les espaces memoires de tab et de compteur
    (*compteur)--;
    if (*compteur == 0)
    {
        delete compteur;
        delete [] tab;
    }
}

double Matrice::get(int i, int j) const
{
    assert(i<n && i>=0); assert(j<m && j>=0);
    return tab[n*j + i];
}

double& Matrice::get(int i, int j)
{
    assert(i<n && i>=0); assert(j<m && j>=0);
    return tab[m*i + j];
}

void Matrice::print(int i, int j) const
{
    std::cout << get(i, j) << std::endl;
}

Matrice Matrice::operator *(const Matrice& B)
{


    // on teste si le produit est licite
    assert(m == B.n);

    const int newN = n; const int newM = B.m;
    Matrice product(newN, newM);
    // on calcule le produit coefficient par coefficient
    for (int i = 0; i < newN; ++i)
        for (int j = 0; j < newM; ++j)
            for (int k = 0; k < m; ++k)
                product.get(i,j) += get(i, k) * B.get(k, j);

    return product;
}

void Matrice::operator =(const Matrice& B)
{
    // on supprime la matrice et on la remplace par une sallow copy de B
    (*compteur)--;
    if (*compteur == 0)
    {
        // si il n'y a plus de copies de la matrice, on libere les espaces memoire de tab et de compteur
        delete[] tab;
        delete compteur;
    }

    n = B.n; m = B.m;
    tab = B.tab;

    // On incremente le compteur de B et on fait pointer compteur au meme endroit
    (*B.compteur)++;
    compteur = B.compteur;
}

void Matrice::affiche() const
{
    // On affiche la matrice ligne par ligne
    for(int ligne = 0; ligne < n; ++ligne)
    {
        for(int colonne = 0; colonne < m; ++colonne)
        {
            std::cout << get(ligne, colonne) << " ";
        }
        std::cout << std::endl;
    }
}
