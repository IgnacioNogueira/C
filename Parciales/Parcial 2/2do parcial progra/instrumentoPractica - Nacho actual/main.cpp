#include "Instrumento.h"
#include "Cuerdas.h"
#include "Vientos.h"
#include "Percusion.h"
#include "CambioEscalaException.h"

void mostrar(Instrumento* i);

int main()
{
    cout << "Esperado: Instrumento: Contrabajo - G"
         << endl << "--------: ";
    Cuerdas *c1 = new Cuerdas("Contrabajo", 'G');
    mostrar(c1);
    cout << "Esperado: Instrumento: Contrabajo - B"
         << endl << "--------: ";
    (*c1)++;
    ++(*c1);
    mostrar(c1);
    delete c1;
    cout << "Esperado: Instrumento: Oboe - A material:madera"
         << endl << "--------: ";
    Vientos v2("Oboe", 'A', "madera");
    mostrar(&v2);
    cout << "Esperado: Instrumento: Oboe - F material:madera"
         << endl << "--------: ";
    v2--;
    --v2;
    mostrar(&v2);
    cout << "Esperado: Instrumento: Bateria - X"
         << endl << "--------: ";
    Percusion p3("Bateria");
    mostrar(&p3);
    cout << endl
         << "Esperado: Excepcion: No permite cambio de escala"
         << endl << "--------: ";
    try
    {
        p3++;
        ++p3;
        p3--;
        --p3;
    }
    catch(CambioEscalaException &cee)
    {
        cout << "Excepcion: " << cee.what() << endl;
    }
    return 0;
}

void mostrar(Instrumento* i)
{
    cout << "Instrumento: " << i->getNombre()
         << " - " << i->getEscala()
         << " " << i->getDetalles()
         << endl;
}
