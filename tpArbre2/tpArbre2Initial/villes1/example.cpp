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


/*
 * Example of use of "town.h" and "villes.txt":
 * - read file of metropolitan French towns with coordinates
 * - display reading time and number of towns read
 * - ask for town name
 * - lookup for town coordinates with this name and display them
 * - display distance between two random towns
 */
int example()
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
    std::cout << "Reading town file: " << townFile << std::endl;
    clock_t t1 = clock();
    int nb_towns = Town::read_file(townFile, towns, xmin, ymin, xmax, ymax);
    clock_t t2 = clock();
    // Say how many towns have been read
    if (nb_towns < 0) {
        std::cout << "No town found" << std::endl;
        return 1;
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
    std::cout << "Number of leaves : " << qtree->nLeaves() << "\n";

    std::vector< Point2D<Town> > neighbors;
    Point2D<Town> Ponts;
    for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
        if (towns[townIndex].name() == "Ponts") {
            Ponts = Point2D<Town>(towns[townIndex].x(), towns[townIndex].y(), towns[townIndex]);
            break;
        }
    }

    clock_t t3 = clock();
    std::cout << search(neighbors, qtree, mainSquare, Ponts, false) << " nodes visited";
    clock_t t4 = clock();
    std::cout << "\nNearest city : " << neighbors.at(0).info().name() << " (found in "
              << ((float)(t4-t3)/CLOCKS_PER_SEC) << " s)" << std::endl;
    std::cout << "Distance : " << Ponts.dist(neighbors.at(0)) << " km\n";

    clock_t t5 = clock();
    float distanceMin = std::numeric_limits<float>::infinity();
    for (int townIndex = 0; townIndex < towns.size(); townIndex++) {
        if (towns[townIndex].name() != "Ponts" && Ponts.info().dist(towns[townIndex]) < distanceMin) {
            distanceMin = Ponts.info().dist(towns[townIndex]);
        }
    }
    clock_t t6 = clock();
    std::cout << distanceMin << " in " << ((float)(t6-t5)/CLOCKS_PER_SEC) << " s\n";

    // Question 8
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
    std::cout << "Mean tree = " << sumTree/nRandomTowns << " s\n";
    std::cout << "Mean vector = " << sumVector/nRandomTowns << " s\n";



    return 0;
}
