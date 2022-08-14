#include "Recta.h"

Recta::Recta(Punto a, Punto b)
{
    pto1 = a;
    pto2 = b;
}

Punto Recta::operator &&(const Recta& otraRecta) const
{
    double coordX = ((((pto1.coordX * pto2.coordY) - (pto1.coordY * pto2.coordX)) * (otraRecta.pto1.coordX - otraRecta.pto2.coordX)) - ((pto1.coordX - pto2.coordX) * ((otraRecta.pto1.coordX * otraRecta.pto2.coordY) - (otraRecta.pto1.coordY * otraRecta.pto2.coordX))))
            / (((pto1.coordX - pto2.coordX) * (otraRecta.pto1.coordY - otraRecta.pto2.coordY)) - ((pto1.coordY - pto2.coordY) * (otraRecta.pto1.coordX - otraRecta.pto2.coordX)));

    double coordY = ((((pto1.coordX * pto2.coordY) - (pto1.coordY * pto2.coordX)) * (otraRecta.pto1.coordY - otraRecta.pto2.coordY)) - ((pto1.coordY - pto2.coordY) * ((otraRecta.pto1.coordX * otraRecta.pto2.coordY) - (otraRecta.pto1.coordY * otraRecta.pto2.coordX))))
            / (((pto1.coordX - pto2.coordX) * (otraRecta.pto1.coordY - otraRecta.pto2.coordY)) - ((pto1.coordY - pto2.coordY) * (otraRecta.pto1.coordX - otraRecta.pto2.coordX)));

    return Punto(coordX, coordY);
}

double Recta::operator -(const Punto& punto) const
{
    return abs(((pto2.coordY - pto1.coordY) * punto.coordX) - ((pto2.coordX - pto1.coordX) * punto.coordY) + (pto2.coordX * pto1.coordY) - (pto2.coordY * pto1.coordX)) / (sqrt((pow(2, pto2.coordY - pto1.coordY)) + (pow(2, pto2.coordX - pto1.coordX))));
}

ostream& operator <<(ostream& salida, const Recta& recta)
{
    salida << "[" << recta.pto1 << "," << recta.pto2 << "]";

    return salida;
}
