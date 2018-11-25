#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include <limits>

#ifndef srcPath
#define srcPath "."
#endif
// The path and name of the town file
std::string townFile = srcPath "/villes.txt";

#include "town.h"
#include "neighbors.h"

void test()
{
    std::cout << "Testing QuadTrees of Point2D :\n";

    // Leaf and node creation
    QuadTree< Point2D<int> >* qtree;
    Square mainSquare(0, 0, 10);
    qtree = nullptr;
    insert(qtree, mainSquare, Point2D<int>(8, 8, 8)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(1, 1 ,5)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(9, 1 ,2)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(6, 4 ,3)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(3, 6 ,6)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(3, 9 ,4)); //display(qtree); std::cout << "\n";
    insert(qtree, mainSquare, Point2D<int>(5, 6 ,1)); display(qtree); std::cout << "\n";
    /*
    +---------------+---------------+
    |       |       |               |
    |       | (3,9) |               |
    |       |       |               |
    +-------+-------+     (8,8)     |
    |       |   |   |               |
    |       +---+---+               |
    |       |3,6|5,6|               |
    +-------+-------+-------+-------+
    |               |       |       |
    |               | (6,4) |       |
    |               |       |       |
    |     (1,1)     +-------+-------+
    |               |       |       |
    |               |       | (9,1) |
    |               |       |       |
    +---------------+-------+-------+
    */

    vector< Point2D<int> > neighbors; float r = 1;
    std::cout << search(neighbors, qtree, mainSquare, Point2D<int>(4, 6, 12), r, false);
    std::cout << "\nPoint in radius " << std::to_string((int)r) << " : ";
    for (int i = 0; i < neighbors.size(); i++) {
        std::cout << neighbors[i] << ", ";
    }

    std::cout << "\n" << search(neighbors, qtree, mainSquare, Point2D<int>(10, 10, 12));
    std::cout << "\nNearest point : " << neighbors.size() << " " << neighbors.at(0);
}


void example()
{
    // Make sure rand() draws different random numbers each time the
    // program is run
    srand(clock());

    /////
    ///// Read town file
    /////
    // Create an empty list of towns
    vector<Town> towns;
    // Prepare limits
    float xmin = std::numeric_limits<float>::max();
    float ymin = std::numeric_limits<float>::max();
    float xmax = std::numeric_limits<float>::min();
    float ymax = std::numeric_limits<float>::min();
    // Read file
    std::cout << "\n\nReading town file: " << townFile << std::endl;
    clock_t t1 = clock();
    int nb_towns = Town::read_file(townFile, towns, xmin, ymin, xmax, ymax);
    clock_t t2 = clock();
    // Say how many towns have been read
    if (nb_towns < 0) {
        std::cout << "No town found" << std::endl;
        return;
    }
    std::cout << "File read in " << ((float)(t2-t1)/CLOCKS_PER_SEC) << " s" << std::endl;
    std::cout << "Number of towns in file: " << nb_towns << std::endl;
    std::cout << "Bounding box: (" << xmin<< "," << ymin << ")-("
     << xmax << "," << ymax << ")" << std::endl;

    // Dimensionnement du carre initial
    Square mainSquare(xmin, ymin, std::max(ymax - ymin, xmax - xmin));

    // Creation du QuadTree
    clock_t t0 = clock();
    QuadTree< Point2D<Town> >* qtree = nullptr;
    for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
        Town town = towns[townIndex];
        insert(qtree, mainSquare, Point2D<Town>(town.x(), town.y(), town));
    }
    clock_t t00 = clock();
    std::cout << "QuadTree created in " << ((float)(t00-t0)/CLOCKS_PER_SEC) << " s\n";

    // Affichage des infos
    std::cout << "Number of trees : " << qtree->nTrees() << "\n";
    std::cout << "Number of nodes : " << qtree->nNodes() << "\n";
    std::cout << "Number of leaves : " << qtree->nLeaves() << "\n\n";

    std::vector< Point2D<Town> > neighbors;
    Point2D<Town> Ponts;
    for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
        if (towns[townIndex].name() == "Ponts") {
            Ponts = Point2D<Town>(towns[townIndex].x(), towns[townIndex].y(), towns[townIndex]);
            break;
        }
    }

    std::cout << "Nearest city to Ponts : \n";
    clock_t t3 = clock();
    std::cout << "  Found visiting only " << search(neighbors, qtree, mainSquare, Ponts, false) << " nodes !";
    clock_t t4 = clock();
    std::cout << "  City name : " << neighbors.at(0).info().name() << " (found in "
              << ((float)(t4-t3)/CLOCKS_PER_SEC) << " s)" << std::endl;
    std::cout << "  Distance to Ponts : " << Ponts.dist(neighbors.at(0)) << " km\n";

    /*clock_t t5 = clock();
    float distanceMin = std::numeric_limits<float>::infinity();
    for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
        if (towns[townIndex].name() != "Ponts" && Ponts.info().dist(towns[townIndex]) < distanceMin) {
            distanceMin = Ponts.info().dist(towns[townIndex]);
        }
    }
    clock_t t6 = clock();
    std::cout << distanceMin << " in " << ((float)(t6-t5)/CLOCKS_PER_SEC) << " s\n";*/

    // Draw 100 random towns
    std::vector<Town> randomTowns;
    int nRandomTowns = 100;
    float sumTree = 0;
    float sumVector = 0;
    for (int townIndex = 0; townIndex < nRandomTowns; townIndex++) {
        Town randomTown = towns[std::rand() % towns.size()];

        clock_t startTree = clock();
        search(neighbors, qtree, mainSquare, Point2D<Town>(randomTown.x(), randomTown.y(), randomTown), false);
        clock_t endTree = clock();
        float timeTree = (float)(endTree-startTree)/CLOCKS_PER_SEC;
        sumTree += timeTree;

        clock_t startVector = clock();
        float distanceMin = std::numeric_limits<float>::infinity();
        for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
            if (towns[townIndex].name() != randomTown.name() && randomTown.dist(towns[townIndex]) < distanceMin) {
                distanceMin = Ponts.info().dist(towns[townIndex]);
            }
        }
        clock_t endVector = clock();
        float timeVector = (float)(endVector-startVector)/CLOCKS_PER_SEC;
        sumVector += timeVector;
    }
    std::cout << "\nMean searching time using tree : " << sumTree/nRandomTowns << " s\n";
    std::cout << "Mean searching time using vector : " << sumVector/nRandomTowns << " s\n";

}

int main()
{
    test();
    example();
    return 0;
}
