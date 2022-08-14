#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ES_BLANCO(X)( (X) == ' ' || (X) == '\t'  ? 1:0)

#define ES_LETRA(X) ((X>='A' && X<='Z')||(X>='a' && X<='z') ||\
                    (X=='Á' || X=='É' || X=='Í' || X=='Ó' || X=='Ú' || X=='Ü') ||\
                    (X=='á' || X=='é' || X=='í' ||  X=='ó' ||  X=='ú' ||  X=='ü') ||\
                    (X=='Ñ'|| X=='ñ') ? (X) : 0)

#define esMinusc(X) ((X) >= 'a' && (X) <= 'z' ? (X): 0)
#define esMayusc(X) ((X) >= 'A' && (X) <= 'Z' ? (X): 0)

#define aMinus(X) ((X) >= 'A' && (X) <= 'Z' ? (X)+=32 : (X))
#define aMayus(X) ((X) >= 'a' && (X) <= 'z' ? (X)-=32 : (X))

void sacarCaracteresYnum(char *nombre);
void eliminarEspacioPrincipioFin(char * nombre);
void unicoEspacio(char *nombre);
void moverEspacios(char *nombre);
void comaNombre(char * nombre);
void CamelCase(char * nombre);

#endif // CADENA_H_INCLUDED
