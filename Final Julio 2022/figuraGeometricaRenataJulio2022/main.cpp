#include "FiguraGeometrica.h"
#include "Cuadrado.h"
#include "Circulo.h"

void calcularAreaYPerimetro(const FiguraGeometrica* figura);

int main()
{
    Cuadrado *figCuad = new Cuadrado("Cuadrado",8.88);
    Circulo *figCirc = new Circulo("Circulo",3.33);

    calcularAreaYPerimetro(figCirc);

    calcularAreaYPerimetro(figCuad);


    delete figCuad;
    delete figCirc;

    return 0;
}

void calcularAreaYPerimetro(const FiguraGeometrica* figura)
{
    cout << "- Nombre de la figura: " << figura->getNombre() << endl;
    cout << "- Area de la figura: " << figura->area() << endl;
    cout << "- Perimetro de la figura: " << figura->perimetro() << endl;
    cout << endl;
}
