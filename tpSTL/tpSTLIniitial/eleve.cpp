#include "eleve.h"

bool CompareNom::operator ()(Eleve A, Eleve B)
{
    ++*ptr;
    return (A.getNom() < B.getNom());
}

bool CompareNote::operator ()(Eleve A, Eleve B)
{
    ++*ptr;
    return (A.getNote() < B.getNote());
}
