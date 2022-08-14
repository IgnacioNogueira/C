#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 5
#define tam2 300

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


//#define MINUSaCAR(X)((X) >= 'a' && (X) <= 'z' ? (X)-=49 : (X) )
//#define MAYUSaCAR(X)((X) >= 'A' && (X) <= 'Z' ? (X)-=17 : (X) )


#endif // HEADER_H_INCLUDED
