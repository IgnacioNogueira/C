#include "mostrarPersona.h"

void mostrarPersona(const Persona *p)
{
    cout << "Nombre:" << p->getNombre() << " "
    << "Edad:" << p->getEdad() << endl;
}
