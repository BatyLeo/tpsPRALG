#include "arbre.h"

IntTree::IntTree(int d)
{
    data = d;
    // sons = std::vector<IntTree*> (0);
}

IntTree::~IntTree()
{
    // On detruit tous les fils
    for (int i = 0; i < sons.size(); ++i)
        // delete appelle a son tour le destructeur, ce qui detruit recursivement l'arbre
        delete sons[i];
}

int IntTree::getData()
{
    return data;
}

void IntTree::setData(int d)
{
    data = d;
}

int IntTree::nbSons()
{
    return sons.size();
}

IntTree* IntTree::getSon(int pos)
{
    if (pos < 0 || pos >= sons.size()) {
        throw std::out_of_range("position non valide\n");
    }
    return sons.at(pos);
}

void IntTree::setSon(int pos, IntTree* newSon)
{
    if (pos < 0 || pos >= sons.size()) {
        throw std::out_of_range("position non valide\n");
    }
    delete sons[pos];
    sons[pos] = newSon;
}

void IntTree::addAsLastSon(IntTree* newSon)
{
    sons.push_back(newSon);
}

void IntTree::removeLastSon()
{
    if (sons.size() == 0) {
        throw std::length_error("le noeud n'a pas de descendants");
    }
    IntTree* a = sons.back();
    delete a;
    sons.pop_back();
}

void IntTree::display(std::string prefix, std::string indent)
{
    // On affiche l'arbre de maniere recursive
    std::cout << prefix << data << std::endl;
    for (int i = 0; i < sons.size(); ++i) {
        sons[i]->display(prefix + indent);
    }
}
