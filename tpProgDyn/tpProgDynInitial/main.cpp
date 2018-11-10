#include <string>
#include <iostream>
#include <vector>
#include <string>


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

int recursionMemoiseLevenshtein(std::string s1, std::string s2, std::vector<std::vector<int> > tab){
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
    std::vector<std::vector<std::string> > operations;
    // Initialisation
    tab.resize(l1 + 1); operations.resize(l1 + 1);
    tab[0].resize(l2 + 1); operations[0].resize(l2 + 1);
    for (int j = 0; j < l2 + 1; j++)
        tab[0][j] = j;
    for (int ligne = 1; ligne < tab.size(); ++ligne) {
        tab[ligne].resize(l2 + 1, -1); operations[ligne].resize(l2 + 1);
        tab[ligne][0] = ligne;
    }
    // Calcul
    for (int i = 1; i < tab.size(); ++i)
        for (int j = 1; j < tab[i].size(); ++j) {
            // Developpement du min
            if (tab[i - 1][j] < tab[i][j - 1]){
                if (1 + tab[i - 1][j] <= tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])){
                    tab[i][j] = 1 + tab[i - 1][j];
                    operations[i][j] = "suppression";
                }
                else{
                    tab[i][j] = tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
                    operations[i][j] = "substitution";
                }
            }
            else{
                if (1 + tab[i][j - 1] <= tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])){
                    tab[i][j] = 1 + tab[i][j - 1];
                    operations[i][j] = "ajout";
                }
                else{
                    tab[i][j] = tab[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
                    operations[i][j] = "substitution";
                }
            }
        }

    int distance = tab[l1][l2];

    int ligne = l1; int colonne = l2;
    for (int k = 0; k < distance; ++k){
        std::string operation = operations[ligne][colonne];
        if (operation == "ajout"){
            std::cout << "ajout" << std::endl;
            colonne--;
        }
        else if (operation == "suppression"){
            std::cout << "suppression" << std::endl;
            ligne--;
        }
        else if (operation == "substitution") {
            std::cout << "substitution" << std::endl;
            ligne--; colonne--;
        }
    }

    return distance;

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

int main() {
    std::string a = "eoc"; std::string b = "eco";
    std::cout << "Levenshtein recursif : " << dLevenshteinRecursif(a, b) << std::endl;
    std::cout << "Levenshtein recursif memoise : " << dLevenshteinRecursifMemoise(a, b) << std::endl;
    std::cout << "Levenshtein iteratif memoise : \n" << dLevenshteinIteratifMemoise(a, b) << std::endl;
    std::cout << "Damerau-Levenshtein recursif : " << dDamerauLevenshteinRecursif(a, b) << std::endl;
    std::cout << "Damerau-Levenshtein recursif memoise : " << dDamerauLevenshteinRecursifMemoise(a, b) << std::endl;
    std::cout << "Damerau-Levenshtein iteratif memoise : " << dDamerauLevenshteinIteratifMemoise(a, b);
    return 0;
}
