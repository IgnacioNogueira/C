#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

#include "FiguraGeometrica.h"
#include "excepcionValorNegativoException.h"
#define PI 3.14159265359

class Circulo:public FiguraGeometrica
{
private:
    float radio;

public:
    Circulo(const string&,float);
    virtual ~Circulo();

    float area() const;
    float perimetro() const;

    Circulo& operator++();
    Circulo operator--(int);
    Circulo& operator--();
    Circulo operator++(int);

    Circulo& operator+=(float valorFloat);
    Circulo& operator-=(float valorFloat);

    friend ostream& operator << (ostream& sal,const Circulo&);

};


#endif // CIRCULO_H_INCLUDED
