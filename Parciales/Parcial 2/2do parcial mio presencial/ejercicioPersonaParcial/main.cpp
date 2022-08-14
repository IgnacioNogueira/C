#include "Persona.h"
#include "Empleado.h"
#include "mostrarPersona.h"
#include "EdadEmpleadoInvalidaException.h"

int main()
{
    Persona* pers = new Persona("Dani", 14);
    cout << "Esperado: Nombre:Dani Edad:14" << endl;
    cout << "Actual : ";
    mostrarPersona(pers);
    cout << endl;
    delete pers;

    Empleado* emp = new Empleado("Andy", 27, "ABC12345");
    cout << "Esperado: Nombre:Andy Edad:27" << endl;
    cout << "Actual : ";
    mostrarPersona(emp);
    cout << endl;
    cout << "Esperado: ABC12345" << endl;
    cout << "Actual : " << emp->getLegajo() << endl << endl;
    delete emp;

    cout << "Esperado: El empleado debe tener una edad entre 18 y 65 inclusive"
         << endl
         << "Actual : ";
    try
    {
        Empleado* emp = new Empleado("Naty", 17, "XYZ9876");
        cout << "Exito" << endl;
    }
    catch (EdadEmpleadoInvalidaException &ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
