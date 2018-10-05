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

    int getNote(){return note;}
    std::string getNom(){return nom;}
    void changeNom(std::string name){nom = name;}
    void changeNote(int grade){note = grade;}
};


// Foncteurs pour la classe Eleve
class CompareNom
{
private:
    int* ptr;
public:
    CompareNom(int& compteur){ ptr = &compteur; }
    bool operator()(Eleve A, Eleve B);
};

class CompareNote
{
private:
    int* ptr;
public:
    CompareNote(int& compteur){ ptr = &compteur; }
    bool operator()(Eleve A, Eleve B);
};



#endif // ELEVE_H
