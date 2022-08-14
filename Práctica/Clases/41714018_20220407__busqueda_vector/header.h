#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long dni;
    char apyn[36];
    char edad;
    float altura;

}tPersona;

#define NOMBRE_ARCHIVO_BIN "Personas.bin"

#define OK 1
#define NO 0

void cargarPersona(char * nombreArchivo);
int buscarPersonaPorDNI(const tPersona *v, tPersona *p, int cantidad);


#endif // HEADER_H_INCLUDED
