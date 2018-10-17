// Author : Leo BATY

#include "arbre.h"


int main()
{
    IntTree* root = new IntTree(12);
    root->addAsLastSon(new IntTree(8));
    root->getSon(0)->addAsLastSon(new IntTree(4));
    root->getSon(0)->addAsLastSon(new IntTree(9));
    root->addAsLastSon(new IntTree(23));
    root->getSon(1)->addAsLastSon(new IntTree(17));
    root->getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));

    root->display(">>> ");

    return 0;
}
