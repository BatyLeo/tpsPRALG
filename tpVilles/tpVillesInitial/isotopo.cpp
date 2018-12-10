#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>

#include "point2d.h"
#include "town.h"

using namespace std;


#ifndef srcPath
#define srcPath "."
#endif

// The path and name of the town file
string townFile = srcPath "/villes.txt";

// Affiche l'histogramme des repetitions et renvoie N
set<Town> histogrammeRepetitions(vector<Town> towns)
{
    map<string, vector<Town> > occurences;
    for (vector<Town>::iterator it = towns.begin(); it != towns.end(); it++) {
        vector<Town> s;
        map<string, vector<Town> >::iterator it2 = occurences.insert( pair<string, vector<Town> >((*it).name(), s) ).first;
        //occurences.at((*it).name())++;
        (*it2).second.push_back(*it);
    }

    vector<int> histo;
    set<Town> N;
    for (map<string, vector<Town> >::iterator it = occurences.begin(); it != occurences.end(); it++) {
        if (histo.size() <= (*it).second.size())
            histo.resize((*it).second.size() + 1, 0);
        histo[(*it).second.size()]++;

        if ((*it).second.size() > 1) {
            for (vector<Town>::iterator town_it = (*it).second.begin(); town_it != (*it).second.end(); town_it++) {
                N.insert(*town_it);
            }
        }
    }

    for (int i = 1; i < histo.size(); i++) {
        std::cout << histo[i] << " noms de ville sont utilises par exactement " << i << " villes.\n";
    }

    return N;
}

// Affiche l'histogramme des coordonnees et revoie C
set<Town> histogrammeCoordonnees(vector<Town> towns)
{
    map<Point2D, vector<Town> > occurences;
    for (vector<Town>::iterator it = towns.begin(); it != towns.end(); it++) {
        vector<Town> s;
        map<Point2D, vector<Town> >::iterator ohohoh = occurences.insert(pair<Point2D, vector<Town> >((*it).point(), s)).first;
        (*ohohoh).second.push_back(*it);
    }

    vector<int> histo;
    set<Town> C;
    for (map<Point2D, vector<Town> >::iterator it = occurences.begin(); it != occurences.end(); it++) {
        if (histo.size() <= (*it).second.size())
            histo.resize((*it).second.size() + 1, 0);
        histo[(*it).second.size()]++;

        if ((*it).second.size() > 1) {
            for (vector<Town>::iterator town_it = (*it).second.begin(); town_it != (*it).second.end(); town_it++) {
                C.insert(*town_it);
            }
        }
    }

    for (int i = 1; i < histo.size(); i++) {
        std::cout << histo[i] << " coordonnees sont utilises par exactement " << i << " villes.\n";
    }

    return C;
}

// Affiche les deux histogrammes et renvoie l'intersection entre N et C
set<Town> NinterC(vector<Town> towns) {
    set<Town> N = histogrammeRepetitions(towns);
    cout << "\n";
    set<Town> C = histogrammeCoordonnees(towns);

    vector<Town> v(min(N.size(), C.size()));
    vector<Town>::iterator end = set_intersection(N.begin(), N.end(), C.begin(), C.end(), v.begin());
    v.resize(end - v.begin());

    set<Town> intersection(v.begin(), v.end());

    return intersection;
}

// Cherche le nombre de villes que l'on peut confondre
// en entendant parler d'une ville A proche d'une ville B
// (en parcourant N inter C)
int confusion(vector<Town> towns)
{
    set<Town> intersection = NinterC(towns);
    int compteur = 0;
    for (set<Town>::iterator it1 = intersection.begin(); it1 != intersection.end(); it1++) {
        for (set<Town>::iterator it2 = intersection.begin(); it2 != intersection.end(); it2++) {
            if (*it1 != *it2 && (*it1).point() == (*it2).point())
                for (set<Town>::iterator it3 = intersection.begin(); it3 != intersection.end(); it3++) {
                    if (*it2 != *it3 && *it1 != *it3 && (*it1).name() == (*it3).name())
                        for (set<Town>::iterator it4 = intersection.begin(); it4 != intersection.end(); it4++) {
                            if (*it4 != *it1 && *it4 != *it2 && *it4 != *it3
                                    && (*it3).point() == (*it4).point() && (*it2).name() == (*it4).name())
                                compteur++;
                        }
                }
        }
    }
    cout << "Nombre de villes pouvant etre confondues : " << compteur << "\n";
    return compteur;
}

// Cherche le nombre de villes que l'on peut confondre
// en entendant parler d'une ville A proche d'une ville B
// (en parcourant toutes les villes)
int confusion2(vector<Town> towns)
{
    int compteur = 0;
    for (vector<Town>::iterator it1 = towns.begin(); it1 != towns.end(); it1++) {
        for (vector<Town>::iterator it2 = towns.begin(); it2 != towns.end(); it2++) {
            if (*it1 != *it2 && (*it1).point() == (*it2).point())
                for (vector<Town>::iterator it3 = towns.begin(); it3 != towns.end(); it3++) {
                    if (*it2 != *it3 && *it1 != *it3 && (*it1).name() == (*it3).name())
                        for (vector<Town>::iterator it4 = towns.begin(); it4 != towns.end(); it4++) {
                            if (*it4 != *it1 && *it4 != *it2 && *it4 != *it3
                                    && (*it3).point() == (*it4).point() && (*it2).name() == (*it4).name())
                                compteur++;
                        }
                }
        }
    }
    cout << "Nombre de villes pouvant etre confondues : " << compteur << "\n";
    return compteur;
}


/*
 * Study French isotoponyms
 */
int main()
{
    /////
    ///// Read town file
    /////
    // Create an empty list of towns
    vector<Town> towns;
    // Read file
    cout << "Reading town file: " << townFile << endl;
    clock_t time1 = clock();
    int nb_towns = Town::read_file(townFile, towns);
    clock_t time2 = clock();
    // Sanity check
    if (nb_towns < 0) {
	cout << "Error while reading file" << endl;
	return 2;
    }
    if (nb_towns == 0) {
	cout << "No town found" << endl;
	return 1;
    }
    // Initialize random seed
    srand(time(NULL));
    // Say how many towns have been read
    cout << "File read in: "
	 << ((float)(time2-time1)/CLOCKS_PER_SEC) << " s" << endl;
    cout << "Number of towns in file: "
	 << towns.size() /* same as nb_towns */ << endl;
    cout << "A random town, using format \"name[lat,lon](x,y)\": "
	 << towns[rand() % towns.size()] << endl;

    // That's all folks
    clock_t t1 = clock();
    confusion(towns);
    clock_t t2 = clock();
    cout << "Calcul rapide en " << (float)(t2-t1)/CLOCKS_PER_SEC << " s\n\n";

    clock_t t3 = clock();
    confusion2(towns);
    clock_t t4 = clock();
    cout << "Calcule lent en " << (float)(t4-t3)/CLOCKS_PER_SEC << " s\n";

    return 0;
}
