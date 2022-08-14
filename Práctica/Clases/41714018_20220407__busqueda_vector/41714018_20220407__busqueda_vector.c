#include "header.h"

/*
    Generar una vector de 10 elementos de tipo Persona. El tipo persona contiene los siguientes campos:

    dni (long)
    apyn (char 36 elementos)
    edad (char)
    altura (float)

    Escriba una funci�n que permita hacer una b�squeda por DNI en el vector. El prototipo de la funci�n es el siguiente:

    int buscarPersonaPorDNI(const tPersona *v, tPersona *p, int cantidad);

    La funci�n recibe como argumento un puntero de tipo tPersona que tiene en su campo dni el DNI de la persona a buscar.

    Si el DNI buscado se encuentre dentro del vector, se deben completar los datos restantes de la estructura y la funci�n debe retornar 1. En el caso contrario, la funci�n retorna 0.


*/

int buscarPersonaPorDNI(const tPersona *v, tPersona *p, int cantidad)
{
    while(cantidad)
    {
        if(v->dni == p->dni)
        {
            memcpy(&p,v,sizeof(p));
            return 1;
        }
        --cantidad;
    }

    return 0;
}
