#include <ctime>
#include <random>
#include <cstdlib>

#include "matrice.h"



int main() {

    srand(time(NULL));

    int n = 1;
    for (int i = 0; i < n; i++)
    {
        Matrice A(rand()%10 + 1, rand()%10 + 1);
        //A.affiche();
        Matrice B(rand()%10 + 1, A.get_n());
        //B.affiche();

        Matrice C = B * A;
        C.affiche();

        const Matrice D = C;
        D.affiche();

        A = D;
    }

    return 0;
}
