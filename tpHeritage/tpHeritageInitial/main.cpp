// Author : Leo BATY

#include "affine.h"
#include "trigo.h"


int main()
{
    // Creation du polynome x**3
    std::vector<float> coefs({0, 0, 0, 1});
    Polynome P(coefs);
    std::cout << P.inverse(27) << std::endl;


    Trigo tangente("tan");
    std::cout << tangente.inverse(1) * 4 << std::endl;

    Affine A(3,3);

    std::cout << A(-1) << std::endl;
    std::cout << A.inverse(0) << std::endl;
    Fonction* B = A.derivee();
    std::cout << (*B)(30000) << std::endl;

    return 0;
}
