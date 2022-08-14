#include <iostream>
#include "Complejo.h"



using namespace std;


int main()
{
    Complejo c1(1, 2);
    Complejo c2(2, 1);

    Complejo c3 = c1 + c2;

    cout << c3 << " = " << c1 << " + " << c2 << endl;

    Complejo c4 = 5 * c3;

    cout << c4 << " = " << 5 << " * " << c3 << endl;

    Complejo c5 = c3 * c4;

    cout << c5 << " = " << c3 << " * " << c4 << endl;


    return 0;
}
