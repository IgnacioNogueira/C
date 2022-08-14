#include <iostream>

#include "ClaseBase.h"
#include "ClaseA.h"
#include "ClaseB.h"

int main() {
    //Declaro ambas clases como si fueran ClaseBase
    ClaseBase *a = new ClaseA(1);
    ClaseBase *b = new ClaseB(2);
    /*
    Elimino ambas clases, se llama al destructor de la clase
    derivada y luego al de la clase base
    Resultado esperado para cada variable:
        1-Se llama al destructor de la clase derivada
        2-Se llama al destructor de la clase base
    */
    delete b;
    delete a;
    return 0;
}

