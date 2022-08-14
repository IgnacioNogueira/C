#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <iostream>
#include "string.h"

using namespace std;

class Cadena
{

private:
        char *cad;
        size_t strlen_MIO(const char *cad);
        char * strcpy_MIO(char * dest,const char *orig);
        char * strcat_MIO(char *dest,const char *orig);


public:

    Cadena();
    Cadena(const char*);
    Cadena(const Cadena&);
    ~Cadena();

    size_t longitud();

    Cadena operator +(const Cadena &c2);
    Cadena operator+(const char *c2);
    friend Cadena operator+(const char *c1,const Cadena &c2);

    friend istream& operator >>(istream &ent,Cadena &obj);
    friend ostream& operator <<(ostream &sal, const Cadena &obj);



};

#endif // CADENA_H_INCLUDED
