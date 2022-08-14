#include "Medicion.h"

int main()
{
    Medicion m1mv(100.0,"Mv");
    Medicion m2mv(20.0,"Mv");
    Medicion m4amp(3.0,"Amp");
    Medicion m3mv = m1mv - m2mv;
    Medicion m4mv = m2mv - 100;
    Medicion m5mv = 150 - m2mv;

    cout << m3mv << endl;
    cout << m4mv << endl;
    cout << "acaaa" << m5mv << endl;
   // cout << m4mv << endl;
    cout << "Resultado 1: " << 180.0 + m3mv << endl;
    cout << "Resultado 2: " << m3mv + 188.5 << endl;

    try
    {
        cout << m3mv - m4amp << endl;
    }catch(...)
    {
        cout << "No se pueden restar mediciones de distinta unidad de medida" << endl;
    }

    return 0;
}
