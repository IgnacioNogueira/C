#include <iostream>

#include "FiguraGeometrica.h"
#include "Cuadrado.h"
#include "Circulo.h"

using namespace std;

void calcularAreaYPerimetro(const FiguraGeometrica* figura);

int main()
{
    Cuadrado* figCuadrado = new Cuadrado("Cuadrado", 3);
    Circulo* figCirculo = new Circulo("Circulo", 4);

    calcularAreaYPerimetro(figCuadrado);

    cout << endl;

    calcularAreaYPerimetro(figCirculo);

    delete figCuadrado;
    delete figCirculo;

    return 0;
}

void calcularAreaYPerimetro(const FiguraGeometrica* figura)
{
    cout << "Nombre de la figura: " << figura->getNombre() << endl;
    cout << "Area de la figura: " << figura->area() << endl;
    cout << "Perimetro de la figura: " << figura->perimetro() << endl;
}
