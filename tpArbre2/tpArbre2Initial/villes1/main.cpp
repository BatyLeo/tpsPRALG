#include "neighbors.h"
#include "town.h"

void test()
{
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

int main()
{
    test();
    example();

    return 0;
}
