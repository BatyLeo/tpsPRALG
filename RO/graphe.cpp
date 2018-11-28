//
//  graphe.cpp
//  RO
//

#include "graphe.hpp"

/*Graphe::Graphe(int _nbSommets, int _nbArretes, std::vector<int[2]> _listeArretes, std::vector<double> _poids)
{
    nbSommets = _nbSommets;
    nbArretes = _nbArretes;
    //listeArretes = _listeArretes;
    //poids = _poids;
}*/

Graphe::Graphe()
{
    nbSommets = 6;
    Arrete a;
    a.debut = 0; a.fin = 1; a.poids = 7; arretes.push_back(a);
    a.debut = 0; a.fin = 2; a.poids = 9; arretes.push_back(a);
    a.debut = 0; a.fin = 4; a.poids = 14; arretes.push_back(a);
    a.debut = 1; a.fin = 2; a.poids = 10; arretes.push_back(a);
    a.debut = 1; a.fin = 3; a.poids = 15; arretes.push_back(a);
    a.debut = 2; a.fin = 4; a.poids = 2; arretes.push_back(a);
    a.debut = 2; a.fin = 3; a.poids = 11; arretes.push_back(a);
    a.debut = 3; a.fin = 5; a.poids = 6; arretes.push_back(a);
    a.debut = 4; a.fin = 5; a.poids = 9; arretes.push_back(a);
    
    createDeltaE(); createDeltaS();
}

void Graphe::createDeltaS()
{
    std::vector<std::vector<int> > a(nbSommets);
    deltaS = a;
    
    for (int i = 0; i < arretes.size(); ++i)
        deltaS[arretes[i].debut].push_back(i);
}

void Graphe::createDeltaE()
{
    std::vector<std::vector<int> > a(nbSommets);
    deltaE = a;
    
    for (int i = 0; i < arretes.size(); ++i)
        deltaE[arretes[i].debut].push_back(i);
}

bool finDjikstra(std::vector<double> lambda, std::vector<bool> U)
{
    for (int i = 0; i < lambda.size(); ++i)
        if (U[i] == true && lambda[i] != INFTY)
            return false;
    return true;
}

int selectSommet(std::vector<double> lambda, std::vector<bool> U)
{
    double min = INFTY;
    int imin = 0;
    for (int i = 0; i < lambda.size(); ++i)
        if (U[i] == true && lambda[i] < min) {
            min = lambda[i];
            imin = i;
        }
    return imin;
}

double Graphe::djikstra(int s, int t)
{
    //std::vector<int> plusCourtChemin({s});
    
    // Initialisation des labels et de l'ensemble des sommets a considerer
    std::vector<double> lambda (nbSommets, INFTY);
    std::vector<bool> U (nbSommets, true);
    lambda[s] = 0;
    
    while (!finDjikstra(lambda, U)) {
        int sommet = selectSommet(lambda, U);
        U[sommet] = false;
        
        std::vector<int> arretesSortantes = deltaS[sommet];
        for (int i = 0; i < arretesSortantes.size(); ++i) {
            Arrete arrete = arretes[arretesSortantes[i]];
            int successeur = arrete.fin;
            if (lambda[successeur] > lambda[sommet] + arrete.poids)
                lambda[successeur] = lambda[sommet] + arrete.poids;
        }
    }
    return lambda[t];
}


void Graphe::scanne(int sommet, std::vector<bool>& sommetsOuverts, std::vector<int>& sommets)
{
    std::vector<int> arretesSortantes = deltaS[sommet];
    for (int i = 0; i < arretesSortantes.size(); ++i) {
        int successeur = arretes[arretesSortantes[i]].fin;
        if (sommetsOuverts[successeur])
            scanne(successeur, sommetsOuverts, sommets);
    }
    
    sommetsOuverts[sommet] = false;
    sommets.insert(sommets.begin(), sommet);
    //sommets.push_back(sommet);/////
}


void Graphe::ordreTopologique(std::vector<int>& sommets)
{
    // On cherche un sommet sans successeur
    std::vector<bool> hasPredecesseur (nbSommets, false);
    for (int i = 0; i < arretes.size(); ++i)
        hasPredecesseur[arretes[i].fin] = true;
    int s = 0;
    while (hasPredecesseur[s])
        s += 1;
    
    // On cree recursivement l'ordre topologique sur l'ensemble des sommets
    std::vector<bool> sommetsOuverts(nbSommets, true);
    scanne(s, sommetsOuverts, sommets);
}


double Graphe::acircuitique(int s, int t)
{
    // Initialisation des labels et de l'ensemble des sommets a considerer
    std::vector<double> lambda (nbSommets, INFTY);
    std::vector<bool> U (nbSommets, true);
    lambda[s] = 0;
    
    // Creation de l'ordre topologique
    std::vector<int> ordreTopo;
    ordreTopologique(ordreTopo);
    
    // Algorithme de programmation dynamique
    for (int sommet = 1; sommet < ordreTopo.size(); ++sommet) {
        std::vector<int> arretesEntrantes = deltaE[sommet];
        double min = INFTY;
        for (int i = 0; i < arretesEntrantes.size(); ++i) {
            Arrete arrete = arretes[arretesEntrantes[i]];
            int predecesseur = arrete.debut;
            if (min > lambda[predecesseur] + arrete.poids)
                min = lambda[predecesseur] + arrete.poids;
        }
        std::cout << min << std::endl;
        lambda[sommet] = min;
    }
    
    return lambda[t];
}











