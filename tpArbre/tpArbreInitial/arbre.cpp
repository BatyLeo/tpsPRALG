#include "arbre.h"

IntTree::IntTree(int d)
{
    data = d;
    // sons = std::vector<IntTree*> (0);
}

IntTree::~IntTree()
{
    std::cout << "destructor o.O\n";
    // On detruit tous les fils
    for (int i = 0; i < sons.size(); ++i)
        // delete appelle a son tour le destructeur, ce qui detruit recursivement l'arbre
        delete sons[i];
    std::cout << "destructor o.O\n";
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
    return sons.at(pos);
}

void IntTree::setSon(int pos, IntTree* newSon)
{
    delete sons[pos];
    sons[pos] = newSon;
}

void IntTree::addAsLastSon(IntTree* newSon)
{
    sons.push_back(newSon);
}

void IntTree::removeLastSon()
{
    assert(sons.size());
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
