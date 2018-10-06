#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

class Eleve
{
private:
    std::string nom;
    int note;

public:
    Eleve(){}

    int getNote(){return note;}                   // Accesseur de note
    std::string getNom(){return nom;}             // Accesseur de nom
    void changeNom(std::string name){nom = name;} // Remplace nomn par name
    void changeNote(int grade){note = grade;}     // Remplace note par grade
};


// Foncteurs pour la classe Eleve

// Comparaison de noms
class CompareNom
{
private:
    int* ptr; // Nombre de comparaisons effectuees
public:
    CompareNom(int& compteur){ ptr = &compteur; } // Constructeur du compteur de comparaisons
    bool operator()(Eleve A, Eleve B);
};

// Comparaison de notes
class CompareNote
{
private:
    int* ptr; // Nombre de comparaisons effectuees
public:
    CompareNote(int& compteur){ ptr = &compteur; } // Constructeur du compteur de comparaisons
    bool operator()(Eleve A, Eleve B);
};



#endif // ELEVE_H
