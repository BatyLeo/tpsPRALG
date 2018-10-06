#include "eleve.h"

bool CompareNom::operator ()(Eleve A, Eleve B)
{
    // On augmente de 1 le nombre de comparaisons
    ++*ptr;
    return (A.getNom() < B.getNom());
}

bool CompareNote::operator ()(Eleve A, Eleve B)
{
    // On augmente de 1 le nombre de comparaisons
    ++*ptr;
    return (A.getNote() < B.getNote());
}
