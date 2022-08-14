#include <iostream>
#include "Medicion.h"

using namespace std;

int main()
{
    Medicion m1mv(100.0, "Mv");
    Medicion m2mv(20.0, "Mv");
    Medicion m4amp(3.0, "Amp");
    Medicion m3mv=m1mv-m2mv;
    cout << "Resultado 1: " << 180.0+m3mv << endl;

    try
    {
        cout << m3mv-m4amp << endl;
    }catch(RestaInvalidaException &error)
    {
        cout << "No se pueden restar mediciones de distinta unidad de medida" << endl;
    }
    return 0;
}
