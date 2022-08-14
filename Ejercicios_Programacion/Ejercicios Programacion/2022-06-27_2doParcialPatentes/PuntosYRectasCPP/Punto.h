#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

class Punto
{
    private:
        double coordX;
        double coordY;
    public:
        Punto(double coordX=0, double coordY=0);
        friend ostream& operator <<(ostream& salida, const Punto& punto);

        friend class Recta;
};

#endif // PUNTO_H
