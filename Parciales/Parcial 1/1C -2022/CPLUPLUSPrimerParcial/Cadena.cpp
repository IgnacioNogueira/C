#include "Cadena.h"

size_t Cadena::strlen_MIO(const char *cad)
{
    size_t n = 0;
    const char *p = cad;

    while(*p)
    {
        ++n;
        ++p;
    }

    return n;
}

char * Cadena::strcpy_MIO(char * dest,const char *orig)
{
    char *pDest = dest;
    const char *pOrig = orig;

    while(*pOrig)
    {
        *pDest = *pOrig;
        ++pOrig;
        ++pDest;
    }

    *pDest = '\0';
    return dest;
}

char * Cadena::strcat_MIO(char *dest,const char *orig)
{
    int tamDest = strlen_MIO(dest);
    char *aux = dest;
    dest+=tamDest;

    while(*orig)
    {
        *dest = *orig;
        ++orig;
        ++dest;
    }

    *dest = '\0';

    return aux;
}

Cadena::Cadena()
{
    this->cad = new char[1];
    *this->cad = '\0';
}

Cadena::Cadena(const char *cad)
{
    this->cad = new char[strlen_MIO(cad)+1];
    strcpy_MIO(this->cad,cad);
}

Cadena::Cadena(const Cadena &obj)
{
    this->cad = new char[strlen_MIO(obj.cad)+1];
    strcpy_MIO(this->cad,obj.cad);
}

Cadena::~Cadena()
{
    delete [] cad;
}

size_t Cadena::longitud()
{
    return strlen_MIO(this->cad);
}

Cadena Cadena::operator +(const Cadena &c2)
{
    char *concat = new char[strlen_MIO(this->cad)+strlen_MIO(c2.cad)+1];
    *concat = '\0';
    strcpy_MIO(concat,this->cad);
    strcat_MIO(concat,c2.cad);

    return Cadena(concat);
}

Cadena Cadena::operator+(const char *c2)
{
    return *this + Cadena(c2);
}

Cadena operator+(const char *c1,const Cadena &c2)
{
    return Cadena(c1) + c2;
}

istream& operator >>(istream& ent,Cadena &obj)
{
    char *linea = new char[100];
    ent.getline(linea,100);

    size_t tamBuffer = obj.strlen_MIO(linea);
    size_t tamParam = obj.strlen_MIO(obj.cad);

    if(tamBuffer != tamParam)
    {
        delete [] obj.cad;
        obj.cad = new char[tamParam+1];
    }

    obj.strcpy_MIO(obj.cad,linea);

    delete [] linea;

    return ent;
}

ostream& operator <<(ostream &sal,const Cadena &obj)
{
    return sal << obj.cad << endl;
}


