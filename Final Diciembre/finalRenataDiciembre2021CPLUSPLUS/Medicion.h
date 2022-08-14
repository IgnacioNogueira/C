#ifndef MEDICION_H_INCLUDED
#define MEDICION_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

class Medicion{

private:
    float valorMedicion;
    string unidad;

public:

    Medicion(float,string);
    ~Medicion();

    //m3mv
    Medicion operator -(const Medicion& v2);

    //m4mv
    Medicion operator -(const int v2);

    //m5mv
    friend Medicion operator -(const float v1, const Medicion& v2);

    //cout sueltos:

    friend float operator +(const float v1,const Medicion& v2);
    friend float operator +(const Medicion &v1,const float v2);

    friend ostream& operator << (ostream & sal,const Medicion &obj);

};



#endif // MEDICION_H_INCLUDED
