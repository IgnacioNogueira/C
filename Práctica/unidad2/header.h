#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NO 0

#define ES_BLANCO(X)((X) == ' ' || (X) == '\t')
#define ES_NUMERO(X)((X) >= 0 && (X) <=9)
#define ES_MINUS(X)((X) >= 'a' && (X) <= 'z')
#define ES_MAYUS(X)((X) >= 'A' && (X) <= 'Z')
#define aMayusc(X)((X) >= 'a' && (X)<='z' ? (X)-32:(X))
#define aMinusc(X)((X) >= 'A' && (X)<='Z' ? (X)+=32:(X))


#define ES_LETRA(X) ((X>='A' && X<='Z')||(X>='a' && X<='z') ||\
                    (X=='Á' || X=='É' || X=='Í' || X=='Ó' || X=='Ú' || X=='Ü') ||\
                    (X=='á' || X=='é' || X=='í' ||  X=='ó' ||  X=='ú' ||  X=='ü') ||\
                    (X=='Ñ'|| X=='ñ'))

#define ES_SIMBOLO(X)((X) != ES_LETRA)

#define TAM_NYA       35
#define TAM_NOTA1      5
#define TAM_NOTA2      5
#define TAM_NOTA3      5
#define TAM_NOTA4      5
#define TAM_NOTA5      5
#define TAM_NOTA6      5
#define TAM_PROMEDIO   5

#define TAM_LINEA TAM_NYA + TAM_NOTA1 + TAM_NOTA2 \
                  + TAM_NOTA3 + TAM_NOTA4 + TAM_NOTA5 + TAM_NOTA6 + TAM_PROMEDIO


/*
#define MENU_MSJ1 ""\n\n\n\n=======================MENU - UNIDAD 2======================="\
                   "Elija una opcion:\n"                \
                   "A - Ejercicio 12\n"                 \
                                                        \
                                                        \
                                                        \
                    "0 - SALIR\n"                        \
                    "--> "
*/

typedef struct
{

    char nya[36];
    float nota1,
          nota2,
          nota3,
          nota4,
          nota5,
          nota6,
          prom;
} tAlumno;


#endif // HEADER_H_INCLUDED
