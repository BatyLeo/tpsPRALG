//
//  graphe.hpp
//  RO
//

#ifndef graphe_hpp
#define graphe_hpp

#include <vector>
#include <iostream>

const double INFTY = std::numeric_limits<double>::infinity();

struct Arrete
{
    int debut;    // Indice du sommet origine de l'arrete
    int fin;      // Indice du sommet arrivee de l'arrete
    double poids; // Poids de l'arrete
};


// Classe graphe oriente
class Graphe
{
private:
    // Necessaire
    int nbSommets;
    std::vector<Arrete> arretes;
    
    // Redondant mais utile
    std::vector<std::vector<int> > deltaS; // Indices des arretes sortantes
    std::vector<std::vector<int> > deltaE; // Indices des arretes entrantes
public:
    Graphe();
    
    void createDeltaS();
    void createDeltaE();
    
    double djikstra(int s, int t); // Algorithme de Djikstra, recherche du plus court s-t chemin
    
    void scanne(int sommet, std::vector<bool>& sommetsOuverts, std::vector<int>& sommets);
    void ordreTopologique(std::vector<int>& sommets);
    double acircuitique(int s, int t);
    
};


#endif /* graphe_hpp */
