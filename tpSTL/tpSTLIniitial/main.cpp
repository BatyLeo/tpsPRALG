// Author : Leo BATY

#include <algorithm>

#include "eleve.h"

const int NB_ELEVES = 10000000; // Nombre d'eleves

int main() {
    srand(time(NULL));

    // On cree un vecteur de NB_ELEVES aleatoires
    std::vector<Eleve> eleves;
    for (int ieleve = 0; ieleve < NB_ELEVES; ++ieleve)
    {
        Eleve e;
        // Majuscule
        std::string nom;
        nom = 'A' + rand()%26;
        // Minuscules
        std::string min;
        int nbMin = rand()%10 + 1; // Nombre de minuscules
        for (int i = 0; i < nbMin + 1; ++i)
        {
            min = 'a' + rand()%26;
            nom += min;
        }
        e.changeNom(nom);
        e.changeNote(rand()%21);
        eleves.push_back(e);
    }


    int compteur = 0;
    std::sort(eleves.begin(), eleves.end(), CompareNote(compteur));
    //for (int i = 0; i < NB_ELEVES; ++i)
        //std::cout << eleves[i].getNom() << "  " << eleves[i].getNote() << std::endl;
    std::cout << "Nombre de comparaisons de notes : " << compteur << std::endl;

    compteur = 0;
    std::sort(eleves.begin(), eleves.end(), CompareNom(compteur));
    //for (int i = 0; i < NB_ELEVES; ++i)
        //std::cout << eleves[i].getNom() << "  " << eleves[i].getNote() << std::endl;
    std::cout << "Nombre de comparaison de noms : " << compteur << std::endl;



    return 0;
}
