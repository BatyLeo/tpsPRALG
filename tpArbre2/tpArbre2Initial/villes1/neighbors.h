#pragma once

#include <vector>
using std::vector;
#include <cmath>

#include "point2d.h"
#include "square.h"
#include "quadrant.h"
#include "../quadtree/quadtree.h"

//
// Add point p in the quadtree representing the points in square s
//
template <typename T>
void insert(QuadTree< Point2D<T> >* &qtree, Square s, Point2D<T> p)
{
    // Si on a une feuille vide
    if (qtree == nullptr) {
        // on ajoute le point p  a la feuille
        qtree = new QuadLeaf< Point2D<T> >(p);
        return;
    }

    // sous-quadrant dans lequel se trouve p
    Quadrant currentQuadrant(s, p);

    // Si on a deja un point p2, on redecoupe une nouvelle fois
    if (qtree->isLeaf()) {
        Point2D<T> p2 = qtree->value();
        // si le p est deja dans l'arbre on ne fait rien
        if (p == p2)
            return;

        // sous-quadrant dans lequel se trouve p2
        Quadrant subQuadrant(s, p2);
        // on decoupe qtree en 4 et on ajoute p2 dans le sous-quadrant associe
        QuadNode< Point2D<T> >* qtrees = new QuadNode<Point2D<T> >;
        qtrees->son(subQuadrant.dir) = qtree;
        qtree = qtrees;

        // sous-quadrant dans lequel se trouve p
        //newQuadrant = Quadrant(currentQuadrant.ssq, p);
        // on ajoute p dans son sous-quadrant (qui va  eventuellement etre redecoupe si c'est le meme que p2)
        insert(qtree->son(currentQuadrant.dir), currentQuadrant.ssq, p);
        return;
    }

    // Sinon, on continue a parcourir l'arbre
    insert(qtree->son(currentQuadrant.dir), currentQuadrant.ssq, p);
}

//
// Add in vector neighbors the points q in quadtree qtree representing
// points in square s at euclidean distance less than r from point p
//
// Set only the nearest point if nearest is true
//
// Return the number of nodes visited
//
template <typename T>
int search(vector< Point2D<T> > &neighbors,
	   QuadTree< Point2D<T> >* qtree, Square s,
       Point2D<T> p, float& r, bool nearest = false, bool includingP = true)
{
    int nNodeVisited = 0; // nombre de noeuds visites

    // s'il n'y a pas de point dans la zone exploree
    if (qtree == 0) {
        nNodeVisited++;
    }
    // si qtree est une feuille
    else if (qtree->isLeaf()) {
        if (p.dist2(qtree->value()) <= r * r) {
            // si nearest==true on garde uniquement le point le plus proche et on modifie r
            if (nearest) {
                if(r * r > p.dist2(qtree->value()) && ((p.dist2(qtree->value()) > 0 && !includingP) || includingP)) {
                    r = p.dist(qtree->value());
                    if (neighbors.size() == 1)
                        neighbors[0] = qtree->value();
                    else
                        neighbors.push_back(qtree->value());
                }
            }
            // sinon on les garde tous
            else
                neighbors.push_back(qtree->value());
            nNodeVisited++;
        }
    }
    // sinon, on explore chaque fils de qtree
    // qui intersecte le cercle de centre p et de rayon r
    else {
        nNodeVisited++;
        for (int dir = 0; dir < nQuadDir; dir++) {
            Square currentSquare = s.subsquare(dir);
            if (currentSquare.intersects_disk(p, r)) {
                nNodeVisited += search(neighbors, qtree->son(dir), currentSquare, p, r, nearest, includingP);
            }
            else {
                nNodeVisited++;
            }
        }
    }
    return nNodeVisited;
}

//
// Add in vector neighbors the nearest point of p in the quadtree qtree
// representing the points in square s
//
// Return the number of nodes visited
//
template <typename T>
int search(vector< Point2D<T> > &neighbors,
	   QuadTree< Point2D<T> >* qtree, Square s,
       Point2D<T> p, bool includingP = true) {
    neighbors = vector< Point2D<T> >();
    // initialisation de r a +oo
    float r = std::numeric_limits<float>::infinity();
    return search(neighbors, qtree, s, p, r, true, includingP);
}

