#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"
#include <math.h>

class Recta
{
    private:
        Punto pto1;
        Punto pto2;
    public:
        Recta(Punto a, Punto b);
        Punto operator &&(const Recta& otraRecta) const;
        double operator -(const Punto& punto) const;
        friend class Punto;
        friend ostream& operator <<(ostream& salida, const Recta& recta);
};

#endif // RECTA_H
