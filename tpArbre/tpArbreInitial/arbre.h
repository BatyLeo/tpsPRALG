#ifndef ELEVE_H
#define ELEVE_H

#include <vector>
#include <cassert>
#include <iostream>
#include <string>

// Noeud d'un arbre contenant un entier a chaque noeud
class IntTree {
    int data;                   // Valeur du noeud
    std::vector<IntTree*> sons; // Liste des noeuds fils (vide s'il n'y en a pas)
public:
    IntTree(int d);                        // Constructeur d'un noeud de valeur d
    ~IntTree();                            // Destructeur d'un noeud et de tous ses descendants

    int getData();                         // Renvoie la valeur du noeud
    void setData(int d);                   // Modifie la valeur du noeud a d
    int nbSons();                          // Renvoie le nombre de fils de ce noeuds
    IntTree* getSon(int pos);              // Renvoie le fils a la position pos de sons (on considere que le fils le plus a gauche a pour position 0)
    void setSon(int pos, IntTree* newSon); // Remplace le fils a la position pos par newSon
    void addAsLastSon(IntTree* newSon);    // Ajoute un fils supplementaire tout a droite
    void removeLastSon();                  // Detruit le dernier fils tout a droite

    void display(std::string prefix = "", std::string indent = "  "); // Affiche l'arbre
    void display2(std::string prefix = "", std::string indent = "  ");
};


#endif // ELEVE_H
