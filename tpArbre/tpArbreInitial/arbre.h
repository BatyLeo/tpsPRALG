#ifndef ELEVE_H
#define ELEVE_H

#include <vector>
#include <cassert>
#include <iostream>
#include <string>

// Node of a tree containing an integer at each node
class IntTree {
    int data; // Node information
    std::vector<IntTree*> sons; // Sequence of sons (empty if none)
public:
    IntTree(int d); // Create a node with given information
    ~IntTree(); // Destruct a node and all its descendants
    int getData(); // Return information of this node
    void setData(int d); // Set information of this node
    int nbSons(); // Return the number of sons of this node
    IntTree* getSon(int pos); // Return the son at position pos, if any (considering left-most son is at position 0)
    void setSon(int pos, IntTree* newSon); // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void addAsLastSon(IntTree* newSon); // Add newSon as supplementary right-most son of this node
    void removeLastSon(); // Remove right-most son of this node

    void display(std::string prefix = "", std::string indent = "  ");
};


#endif // ELEVE_H
