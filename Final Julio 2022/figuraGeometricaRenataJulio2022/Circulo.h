#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

#include "FiguraGeometrica.h"
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

};


#endif // CIRCULO_H_INCLUDED
