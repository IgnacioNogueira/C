#include "Complejo.h"

Complejo::Complejo(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

Complejo Complejo::operator +(const Complejo& otroComplejo) const
{
    Complejo resultado;
    resultado.real = this->real + otroComplejo.real;
    resultado.imag = this->imag + otroComplejo.imag;
    return resultado;
}

Complejo Complejo::operator *(const Complejo& otroComplejo) const
{
    Complejo resultado;
    resultado.real = (this->real * otroComplejo.real) - (this->imag * otroComplejo.imag);
    resultado.imag = (this->real * otroComplejo.imag) + (this->imag * otroComplejo.real);
    return resultado;
}

Complejo operator *(const int num, const Complejo& numComplejo)
{
    Complejo resultado;
    resultado.real = num * numComplejo.real;
    resultado.imag = num * numComplejo.imag;
    return resultado;
}

ostream& operator <<(ostream& salida, const Complejo& numComplejo)
{
    salida << "(" << numComplejo.real << ", " << numComplejo.imag << ")";
    return salida;
}
