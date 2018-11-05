// Author : Leo BATY

#include "tree.h"
#include "arbre.h"


int main()
{
    Tree<int>* root = new Tree<int>(12);
    root->addAsLastSon(new Tree<int>(8));
    root->getSon(0)->addAsLastSon(new Tree<int>(4));
    root->getSon(0)->addAsLastSon(new Tree<int>(9));
    root->addAsLastSon(new Tree<int>(23));
    root->getSon(1)->addAsLastSon(new Tree<int>(17));
    root->getSon(1)->getSon(0)->addAsLastSon(new Tree<int>(15));
    root->display("* ");
    //root->display2("* ");
    //root->removeLastSon();
    root->insertSon(0, new Tree<int>(42));
    root->display("* ");
    root->removeSon(0);
    root->display("* ");
    root->parcoursProfondeurSortant();
    root->parcoursLargeur();

    std::cout << "Profondeur maximale : " << root->maxDepth() << std::endl;
    std::cout << "Profondeur minimale : " << root->minDepth() << std::endl;

    // Tests des exceptions
    try {
        root->getSon(5);
    }
    catch (std::out_of_range exception) {
        std::cerr << exception.what();
    }
    try {
        root->setSon(5, new Tree<int>(2));
    }
    catch (std::out_of_range exception) {
        std::cerr << exception.what();
    }
    try {
        Tree<int>* tree = new Tree<int>(1);
        tree->removeLastSon();
    }
    catch (std::length_error exception) {
        std::cerr << exception.what();
    }
    try {
        root->insertSon(25, new Tree<int>(1));
    }
    catch (std::out_of_range exception) {
        std::cerr << exception.what();
    }
    try {
        root->removeSon(25);
    }
    catch (std::out_of_range exception) {
        std::cerr << exception.what();
    }


    delete root;



    return 0;
}
