#include "Medicion.h"

Medicion::Medicion(float valorMedicion,string unidad)
{
    this->valorMedicion = valorMedicion;
    this->unidad = unidad;
}

Medicion::~Medicion()
{
}

Medicion Medicion::operator -(const Medicion& v2)
{
    Medicion res(*this);

    if(strcmp(v2.unidad.c_str(),this->unidad.c_str()) != 0)
        throw exception();

    res.valorMedicion = this->valorMedicion - v2.valorMedicion;

    return res;
}

Medicion operator -(const float v1, const Medicion& v2) //m5mv
{
    Medicion res(v2.valorMedicion,v2.unidad); //por el error del constructor

    res.valorMedicion = v1 - res.valorMedicion;

    return res;
}


Medicion Medicion::operator -(const int v2)
{
    Medicion res(*this);

    res.valorMedicion = res.valorMedicion - v2;

    return res;
}


float operator +(const float v1,const Medicion& v2)
{
    float valorTotal = v1 + v2.valorMedicion; //acá no se pasa al constructor ya que es para los cout de Resultado 1

    return valorTotal;
}

float operator +(const Medicion &v1,const float v2)
{
    float valorTotal = v1.valorMedicion + v2; //acá no se pasa al constructor ya que es para los cout de Resultado 1

    return valorTotal;
}

ostream &operator << (ostream &sal,const Medicion &obj)
{
    return sal << obj.valorMedicion << " " << obj.unidad << endl;
}
