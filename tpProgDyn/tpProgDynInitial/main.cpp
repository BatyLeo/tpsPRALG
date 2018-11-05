#include "matrice.h"
#include <string>
#include <iostream>
#include <vector>


int dLevenshteinRecursif(std::string s1, std::string s2)
{
    if (s1.length() == 0 || s2.length() == 0)
        return s1.length() + s2.length();

    int min = 1 + dLevenshteinRecursif(s1. substr(0, s1.length() - 1), s2);
    min = std::min(min, 1 + dLevenshteinRecursif(s1, s2.substr(0, s2.length() - 1)));

    std::string subs1 = s1.substr(s1.length() - 1, 1); std::string subs2 = s2.substr(s2.length() - 1, 1);
    min = std::min(min, (subs1 != subs2) + dLevenshteinRecursif(s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1)));

    return min;
}

std::vector<std::vector<int> > tab;
int dLevenshteinRecursifMemoise(std::string s1, std::string s2)
{
    if (tab.size() < s1.length() + 1)
        tab.resize(s1.length() + 1, std::vector<int>(s2.length() + 1, -1));

    for (int ligne = 0; ligne < tab.size(); ++ligne)
        if (tab[ligne].size() < s2.length() + 1)
            tab[ligne].resize(s2.length() + 1, -1);

    if (s1.length() == 0 || s2.length() == 0)
        return s1.length() + s2.length();

    if (tab[s1.length()][s2.length()] == -1) {
        int min = 1 + dLevenshteinRecursif(s1. substr(0, s1.length() - 1), s2);
        min = std::min(min, 1 + dLevenshteinRecursif(s1, s2.substr(0, s2.length() - 1)));

        std::string subs1 = s1.substr(s1.length() - 1, 1); std::string subs2 = s2.substr(s2.length() - 1, 1);
        min = std::min(min, (subs1 != subs2) + dLevenshteinRecursif(s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1)));

        tab[s1.length()][s2.length()] = min;
    }

    return tab[s1.length()][s2.length()];
}

int dLevenshteinIteratifMemoise(std::string s1, std::string s2)
{
    std::vector<std::vector<int> > tab;
    // Initialisation
    tab.resize(s1.length() + 1);
    tab[0].resize(s2.length() + 1);
    for (int j = 0; j < s2.length() + 1; j++)
        tab[0][j] = j;
    for (int ligne = 1; ligne < tab.size(); ++ligne) {
        tab[ligne].resize(s2.length() + 1, -1);
        tab[ligne][0] = ligne;
    }
    // Calcul
    for (int i = 1; i < tab.size(); ++i)
        for (int j = 1; j < tab[i].size(); ++j) {
            int min = 1 + tab[i - 1][j];
            min = std::min(min, 1 + tab[i][j - 1]);
            min = std::min(min, tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
            tab[i][j] = min;
        }

    return tab[s1.length()][s2.length()];

}

int main() {
    std::string a = "ecoles"; std::string b = "eclose";
    std::cout << dLevenshteinRecursif(a, b) << " " << dLevenshteinRecursifMemoise(a, b) << " " << dLevenshteinRecursifMemoise(b, a);
    std::cout << " " << dLevenshteinIteratifMemoise(a, b);
    return 0;
}
