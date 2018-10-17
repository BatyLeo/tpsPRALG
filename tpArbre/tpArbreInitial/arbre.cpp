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
    //delete sons.back();
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
