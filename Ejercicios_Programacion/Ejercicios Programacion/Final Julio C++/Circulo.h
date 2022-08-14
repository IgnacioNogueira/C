#ifndef CIRCULO_H
#define CIRCULO_H

#include "FiguraGeometrica.h"
#include <cmath>

#define PI 3.14159265359

class Circulo : public FiguraGeometrica
{
    private:
        float _radio;
    public:
        Circulo(string nombre, float radio);
        virtual ~Circulo();
        float area() const;
        float perimetro() const;
};

#endif // CIRCULO_H
