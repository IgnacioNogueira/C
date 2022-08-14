#include <iostream>
#include <math.h>

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

class Recta
{
    private:
        Punto pto1;
        Punto pto2;
    public:
        Recta(Punto a, Punto b);
        Punto operator &&(const Recta& otraRecta) const;
        double operator -(const Punto& punto) const;
        friend ostream& operator <<(ostream& salida, const Recta& recta);
};

int main()
{
    Recta r1(Punto(2, 0), Punto(0, 2));
    Recta r2(Punto(1, 0), Punto(1, 2));

    Punto p(2, 2);

    cout << "Punto de Interseccion entre las rectas " << r1 << " y " << r2 << ": " << (r1 && r2) << endl;

    cout << "Distancia del punto " << p << " a la recta " << r1 << ": " << (r1 - p) << endl;

    cout << "Distancia del punto " << p << " a la recta " << r2 << ": " << (r2 - p) << endl;

    return 0;
}

Punto::Punto(double coordX, double coordY)
{
    this->coordX = coordX;
    this->coordY = coordY;
}

ostream& operator <<(ostream& salida, const Punto& punto)
{
    salida << "(" << punto.coordX << "," << punto.coordY << ")";
    return salida;
}

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
