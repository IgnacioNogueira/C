#include "FiguraGeometrica.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "excepcionValorNegativoException.h"

void calcularAreaYPerimetro(const FiguraGeometrica* figura);

int main()
{
    Cuadrado *figCuad = new Cuadrado("Cuadrado",8.88);
    cout << "valor viejo cuad -- " << *figCuad << endl;

    Circulo *figCirc = new Circulo("Circulo",3.33);
    cout << "valor viejo circ -- " << *figCirc << endl;


    calcularAreaYPerimetro(figCirc);


    calcularAreaYPerimetro(figCuad);



    (*figCirc)++;
    cout << "viejo circ 1 ++ -- " << *figCirc << endl;

    (*figCirc)--;
    cout << "viejo circ 2 -- -- " << *figCirc << endl;

    --*figCirc;
    cout << "viejo circ 3 pre -- " << *figCirc << endl;

    ++*figCirc;
    cout << "viejo cuad 4 pre ++ " << *figCirc << endl;

//    cout << (*figCirc)++ << endl;
//    cout << ++*figCirc << endl;

    *figCirc+=30.33;
    cout << "viejo cuad 5 pre += " << *figCirc << endl;
    try
    {
        *figCirc-=40;
        cout << "viejo cuad 6 pre -= " << *figCirc << endl;
    }
    catch(excepcionValorNegativoException &err)
    {
        cout << "Excepcion: " << err.what() << endl;
    }


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
