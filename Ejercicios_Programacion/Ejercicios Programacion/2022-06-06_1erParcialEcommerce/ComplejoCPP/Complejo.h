#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
	private:
        int real;
        int imag;
	public:
	    // Complejo c1(1, 2);
	    Complejo(int real = 0, int imag = 0); // Los valores predeterminados de los parámetros son de 0
	    // Complejo c3 = c1 + c2;
        Complejo operator +(const Complejo& otroComplejo) const; // const porque no modifica al objeto llamador, sino que crea uno nuevo
        // Complejo c5 = c3 * c4;
        Complejo operator *(const Complejo& otroComplejo) const; // const porque no modifica al objeto llamador, sino que crea uno nuevo
        /// Funciones friend para que puedan acceder a los miembros privados de la clase sin pertenecer a la misma el objeto llamador
        // Complejo c4 = 5 * c3;
        friend Complejo operator *(const int num, const Complejo& numComplejo);
        // cout << c3 << " = " << c1 << " + " << c2 << endl;
        friend ostream& operator <<(ostream& salida, const Complejo& numComplejo);
};


#endif // COMPLEJO_H
