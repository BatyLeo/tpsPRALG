//
//  main.cpp
//  RO
//

#include "graphe.hpp"

int main() {

    Graphe G;
    
    std::cout << G.djikstra(0, 5) << std::endl;
    
    Graphe H;
    
    std::cout << H.acircuitique(0, 5) << std::endl;
    
    return 0;
}
