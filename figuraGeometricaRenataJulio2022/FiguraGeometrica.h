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

    /*
        ++ incremento
        ++ preincremento
        -- decremento
        -- predecremento
        +=
        -=
    */

    //virtual FiguraGeometrica& operator++() const = 0; //preincremento
//    virtual FiguraGeometrica operator++(int) const = 0; //postIncremento
//    virtual FiguraGeometrica& operator--() const = 0; //preDecremento
//    virtual FiguraGeometrica operator--(int) const = 0; //postDecremento

};

#endif // FIGURAGEOMETRICA_H_INCLUDED
