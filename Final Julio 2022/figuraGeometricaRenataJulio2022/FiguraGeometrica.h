#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class FiguraGeometrica
{

private:
    string nombre;

public:
    FiguraGeometrica(const string&);
    virtual ~FiguraGeometrica();
    const string& getNombre() const;
    virtual float area() const = 0;
    virtual float perimetro() const = 0;
};

#endif // FIGURAGEOMETRICA_H_INCLUDED
