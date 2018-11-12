#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>


int dLevenshteinRecursif(std::string s1, std::string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    if (l1 == 0 || l2 == 0)
        return l1 + l2;

    int min = 1 + dLevenshteinRecursif(s1. substr(0, l1 - 1), s2);
    min = std::min(min, 1 + dLevenshteinRecursif(s1, s2.substr(0, l2 - 1)));

    std::string subs1 = s1.substr(l1 - 1, 1); std::string subs2 = s2.substr(l2 - 1, 1);
    min = std::min(min, (subs1 != subs2) + dLevenshteinRecursif(s1.substr(0, l1 - 1), s2.substr(0, l2 - 1)));

    return min;
}

int recursionMemoiseLevenshtein(std::string s1, std::string s2, std::vector<std::vector<int> >& tab){
    int l1 = s1.length();
    int l2 = s2.length();

    if (tab.size() < l1 + 1)
        tab.resize(l1 + 1, std::vector<int>(l2 + 1, -1));

    for (int ligne = 0; ligne < tab.size(); ++ligne)
        if (tab[ligne].size() < l2 + 1)
            tab[ligne].resize(l2 + 1, -1);

    if (l1 == 0 || l2 == 0)
        return l1 + l2;

    if (tab[l1][l2] == -1) {
        int min = 1 + recursionMemoiseLevenshtein(s1. substr(0, l1 - 1), s2, tab);
        min = std::min(min, 1 + recursionMemoiseLevenshtein(s1, s2.substr(0, l2 - 1), tab));
        min = std::min(min, (s1[l1 - 1] != s2[l2 - 1]) + recursionMemoiseLevenshtein(s1.substr(0, l1 - 1), s2.substr(0, l2 - 1), tab));

        tab[l1][l2] = min;
    }

    return tab[l1][l2];
}

int dLevenshteinRecursifMemoise(std::string s1, std::string s2)
{
    std::vector<std::vector<int> > tab;
    return recursionMemoiseLevenshtein(s1, s2, tab);
}

int dLevenshteinIteratifMemoise(std::string s1, std::string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    std::vector<std::vector<int> > tab;
    // Initialisation
    tab.resize(l1 + 1);
    tab[0].resize(l2 + 1);
    for (int j = 0; j < l2 + 1; j++)
        tab[0][j] = j;
    for (int ligne = 1; ligne < tab.size(); ++ligne) {
        tab[ligne].resize(l2 + 1, -1);
        tab[ligne][0] = ligne;
    }
    // Calcul
    for (int i = 1; i < tab.size(); ++i)
        for (int j = 1; j < tab[i].size(); ++j) {
            int min = 1 + tab[i][j - 1];
            min = std::min(min, 1 + tab[i - 1][j]);
            min = std::min(min, tab[i - 1][j - 1] + (s1[i] != s2[j]));
            tab[i][j] = min;
        }

    // On parcours tab afin de recuperer les modifications a apporter a s1 pour obtenir s2
    int i = l1; int j = l2;
    while (tab[i][j] != 0){
        if (tab[i][j - 1] <= tab[i - 1][j]){
            if (tab[i][j - 1] < tab[i - 1][j - 1] && tab[i][j] == tab[i][j - 1] + 1){
                std::cout << " - insertion de " + s2.substr(j, 1) + " en " + std::to_string(i + 1) << std::endl;
                j--;
            }
            else{
                if (tab[i][j] == tab[i - 1][j - 1] + 1)
                    std::cout << " - substitution de " + s1.substr(i, 1) + " par " + s2.substr(j, 1) + " en " + std::to_string(i) << std::endl;
                j--; i--;
            }
        }
        else{
            if (tab[i - 1][j] < tab[i - 1][j - 1] && tab[i][j] == tab[i - 1][j] + 1){
                std::cout << " - suppression de " + s1.substr(i, 1) + " en " + std::to_string(i) << std::endl;
                j--;
            }
            else{
                if (tab[i][j] == tab[i - 1][j - 1] + 1)
                    std::cout << " - substitution de " + s1.substr(i, 1) + " par " + s2.substr(j, 1) + " en " + std::to_string(i) << std::endl;
                j--; i--;
            }
        }
    }
    return tab[l1][l2];
}

int dDamerauLevenshteinRecursif(std::string s1, std::string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    if (l1 == 0 || l2 == 0)
        return l1 + l2;

    int min = 1 + dDamerauLevenshteinRecursif(s1. substr(0, l1 - 1), s2);
    min = std::min(min, 1 + dDamerauLevenshteinRecursif(s1, s2.substr(0, l2 - 1)));
    min = std::min(min, (s1[l1 - 1] != s2[l2 - 1]) + dDamerauLevenshteinRecursif(s1.substr(0, l1 - 1), s2.substr(0, l2 - 1)));

    if (l1 > 1 && l2 > 1 && s1[l1 - 1] == s2[l2 - 2] && s1[l1 - 2] == s2[l2 - 1])
        min = std::min(min, (s1[l1 - 1] != s2[l2 - 1]) + dDamerauLevenshteinRecursif(s1.substr(0, l1 - 2), s2.substr(0, l2 - 2)));

    return min;
}

int recursionMemoiseDamerauLevenshtein(std::string s1, std::string s2, std::vector<std::vector<int> > tab){
    int l1 = s1.length();
    int l2 = s2.length();

    if (tab.size() < l1 + 1)
        tab.resize(l1 + 1, std::vector<int>(l2 + 1, -1));

    for (int ligne = 0; ligne < tab.size(); ++ligne)
        if (tab[ligne].size() < l2 + 1)
            tab[ligne].resize(l2 + 1, -1);

    if (l1 == 0 || l2 == 0)
        return l1 + l2;

    if (tab[l1][l2] == -1) {
        int min = 1 + recursionMemoiseDamerauLevenshtein(s1. substr(0, l1 - 1), s2, tab);
        min = std::min(min, 1 + recursionMemoiseDamerauLevenshtein(s1, s2.substr(0, l2 - 1), tab));
        min = std::min(min, (s1[l1 - 1] != s2[l2 - 1]) + recursionMemoiseDamerauLevenshtein(s1.substr(0, l1 - 1), s2.substr(0, l2 - 1), tab));

        if (l1 > 1 && l2 > 1 && s1[l1 - 1] == s2[l2 - 2] && s1[l1 - 2] == s2[l2 - 1])
            min = std::min(min, (s1[l1 - 1] != s2[l2 - 1]) + recursionMemoiseDamerauLevenshtein(s1.substr(0, l1 - 2), s2.substr(0, l2 - 2), tab));

        tab[l1][l2] = min;
    }

    return tab[l1][l2];
}

int dDamerauLevenshteinRecursifMemoise(std::string s1, std::string s2)
{
    std::vector<std::vector<int> > tab;
    return recursionMemoiseDamerauLevenshtein(s1, s2, tab);
}

int dDamerauLevenshteinIteratifMemoise(std::string s1, std::string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    std::vector<std::vector<int> > tab;
    // Initialisation
    tab.resize(l1 + 1);
    tab[0].resize(l2 + 1);
    for (int j = 0; j < l2 + 1; j++)
        tab[0][j] = j;
    for (int ligne = 1; ligne < tab.size(); ++ligne) {
        tab[ligne].resize(l2 + 1, -1);
        tab[ligne][0] = ligne;
    }
    // Calcul
    for (int i = 1; i < tab.size(); ++i)
        for (int j = 1; j < tab[i].size(); ++j) {
            int min = 1 + tab[i - 1][j];
            min = std::min(min, 1 + tab[i][j - 1]);
            min = std::min(min, tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));

            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1])
                min = std::min(min, (s1[i - 1] != s2[j - 1]) + tab[i -2][j - 2]);
            tab[i][j] = min;
        }

    return tab[l1][l2];
}

int dLevenshteinIteratifMemoiseLineaire(std::string s1, std::string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    std::vector<std::vector<int> > tab;
    // Initialisation
    tab.resize(2);
    tab[0].resize(l2 + 1);
    tab[1].resize(l2 + 1, -1);
    for (int j = 0; j < l2 + 1; j++) {
        tab[0][j] = j;
    }
    tab[1][0] = 1;
    // Calcul
    for (int i = 1; i < l1 - 1; ++i) {
        for (int j = 1; j < tab[0].size(); ++j) {
            int min = 1 + tab[1][j - 1];
            min = std::min(min, 1 + tab[0][j]);
            min = std::min(min, tab[0][j - 1] + (s1[i] != s2[j]));
            tab[1][j] = min;
        }
        for (int j = 0; j < l2; j++) {
            tab[0][j] = tab[1][j];
            tab[1][j] = -1;
        }
        tab[1][0] = i + 1;
    }

    return tab[1][l2];
}

int main() {
    std::string a = "ecoles"; std::string b = "eclose";
    clock_t t1 = clock();
    std::cout << "Levenshtein recursif : " << dLevenshteinRecursif(a, b);
    clock_t t2 = clock();
    std::cout << ", " << (float)(t2-t1)/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Levenshtein recursif memoise : " << dLevenshteinRecursifMemoise(a, b);
    clock_t t3 = clock();
    std::cout << ", " << (float)(t3-t2)/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Levenshtein iteratif memoise :\n" << dLevenshteinIteratifMemoise(a, b);
    clock_t t4 = clock();
    std::cout << ", " << (float)(t4-t3)/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Levenshtein iteratif memoise lineaire : " << dLevenshteinIteratifMemoiseLineaire(a, b);
    clock_t t5 = clock();
    std::cout << ", " << (float)(t5-t4)/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Damerau-Levenshtein recursif : " << dDamerauLevenshteinRecursif(a, b) << std::endl;
    std::cout << "Damerau-Levenshtein recursif memoise : " << dDamerauLevenshteinRecursifMemoise(a, b) << std::endl;
    std::cout << "Damerau-Levenshtein iteratif memoise : " << dDamerauLevenshteinIteratifMemoise(a, b) << std::endl;
    return 0;
}
