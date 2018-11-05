#ifndef ELEVE_H
#define ELEVE_H

#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <limits>

// Noeud d'un arbre contenant un entier a chaque noeud
template <typename T> class Tree {
    int data;                   // Valeur du noeud
    std::vector<Tree<T>*> sons; // Liste des noeuds fils (vide s'il n'y en a pas)
public:
    Tree(T d); // Constructeur d'un noeud de valeur d
    ~Tree();   // Destructeur d'un noeud et de tous ses descendants

    T getData();                           // Renvoie la valeur du noeud
    void setData(T d);                     // Modifie la valeur du noeud a d
    int nbSons();                          // Renvoie le nombre de fils de ce noeuds
    Tree<T>* getSon(int pos);              // Renvoie le fils a la position pos de sons (on considere que le fils le plus a gauche a pour position 0)
    void setSon(int pos, Tree<T>* newSon); // Remplace le fils a la position pos par newSon
    void addAsLastSon(Tree<T>* newSon);    // Ajoute un fils supplementaire tout a droite
    void removeLastSon();                  // Detruit le dernier fils tout a droite
    void insertSon(int pos, Tree<T>* son); // Insere son a la position pos
    void removeSon(int pos);               // Supprime de descendant en position pos

    void display(std::string prefix = "", std::string indent = "  "); // Parcours de l'arbre en profondeur d'abord en entrant
    void profondeurSortant();                                         // Calcul du parcours de l'arbre en profondeur d'abord en sortant
    void parcoursProfondeurSortant();                                 // Affichage du parcours de l'arbre en profondeur d'abord en sortant
    void parcoursLargeur();                                           // Parcours de l'arbre en largeur d'abord

    int maxDepth(); // Calcule la profondeur maximale de l'arbre
    int minDepth(); // Calcule la profondeur minimale de l'arbre
};

template <typename T> Tree<T>::Tree(T d)
{
    data = d;
    // sons = std::vector<Tree*> (0);
}

template <typename T> Tree<T>::~Tree()
{
    // On detruit tous les fils
    for (int i = 0; i < sons.size(); ++i)
        // delete appelle a son tour le destructeur, ce qui detruit recursivement l'arbre
        delete sons[i];
}

template <typename T> T Tree<T>::getData()
{
    return data;
}

template <typename T> void Tree<T>::setData(T d)
{
    data = d;
}

template <typename T> int Tree<T>::nbSons()
{
    return sons.size();
}

template <typename T> Tree<T>* Tree<T>::getSon(int pos)
{
    if (pos < 0 || pos >= sons.size())
        throw std::out_of_range("La position demandee n'existe pas\n");
    return sons.at(pos);
}

template <typename T> void Tree<T>::setSon(int pos, Tree<T>* newSon)
{
    if (pos < 0 || pos >= sons.size())
        throw std::out_of_range("La position demandee n'existe pas\n");
    delete sons[pos];
    sons[pos] = newSon;
}

template <typename T> void Tree<T>::addAsLastSon(Tree<T>* newSon)
{
    sons.push_back(newSon);
}

template <typename T> void Tree<T>::removeLastSon()
{
    if (sons.size() == 0) {
        throw std::length_error("Le noeud n'a pas de descendants\n");
    }
    // On desalloue la memoire avant de supprimer le pointeur
    Tree* a = sons.back();
    delete a;
    sons.pop_back();
}

template <typename T> void Tree<T>::insertSon(int pos, Tree<T>* son)
{
    if (pos < 0 || pos > sons.size())
        throw std::out_of_range("La position demandee n'existe pas\n");
    sons.insert(sons.begin() + pos, son);
}

template <typename T> void Tree<T>::removeSon(int pos)
{
    if (pos < 0 || pos >= sons.size())
        throw std::out_of_range("La position demandee n'existe pas\n");
    // On desalloue la memoire avant de supprimer le pointeur sons[pos]
    Tree<T>* son = sons.at(pos);
    delete son;
    sons.erase(sons.begin() + pos);
}

template <typename T> void Tree<T>::display(std::string prefix, std::string indent)
{
    // On affiche l'arbre de maniere recursive en descendant
    std::cout << prefix << data << std::endl;
    for (int i = 0; i < sons.size(); ++i) {
        sons[i]->display(prefix + indent);
    }
}

template <typename T> void Tree<T>::profondeurSortant()
{
    // On affiche l'arbre de maniere recursive en remaontant
    for (int i = 0; i < sons.size(); ++i) {
        sons[i]->profondeurSortant();
    }
    std::cout << data << " ";
}

template  <typename T> void Tree<T>::parcoursProfondeurSortant()
{
    std::cout << "Parcours en profondeur d'abort sortant :\n";
    profondeurSortant();
    std::cout << std::endl;
}

template <typename T> void Tree<T>::parcoursLargeur()
{
    std::cout << "Parcours en largeur d'abord :\n";
    // File dans laquelle on ajoute les descendants des noeuds consideres
    std::vector<Tree<T>*> res;
    res.push_back(this);
    while (res.size() > 0)
    {
        // Tant qu'il y a un element dans la file, on le sort (et l'affiche) et y ajoute tous ses descendants
        Tree<T>* noeud = res.back();
        res.pop_back();
        for (int i = 0; i < noeud->sons.size(); ++i)
            res.insert(res.begin(), noeud->sons.at(i));
        std::cout << noeud->data << " ";
    }
    std::cout << std::endl;
}

template <typename T> int Tree<T>::maxDepth()
{
    // Un noeud sans descendants vaut a une profondeur nulle
    if (sons.size() == 0)
        return 0;

    int max = 0;
    // La profondeur maximale de this est egale a 1 + le maximum des profondeurs maximales des sous-arbres
    for (int i = 0; i < sons.size(); ++i)
        max = std::max(max, 1 + sons.at(i)->maxDepth());
    return max;
}

template <typename T> int Tree<T>::minDepth()
{
    // Un noeud sans descendants vaut a une profondeur nulle
    if (sons.size() == 0)
        return 0;

    int min = std::numeric_limits<int>::max();
    // La profondeur minimale de this est egale a 1 + le minimum des profondeurs maximales des sous-arbres
    for (int i = 0; i < sons.size(); ++i)
        min = std::min(min, 1 + sons.at(i)->minDepth());
    return min;
}

#endif // ELEVE_H
