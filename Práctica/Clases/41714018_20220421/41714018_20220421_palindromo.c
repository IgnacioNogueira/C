#include "header.h"

#define ES_BLANCO(X)((X) == '\t' || (X) ==' ')
#define ES_LETRA(X)((X>='A' && X<='Z')||(X>='a' && X<='z'))
#define A_MINUS(X)( (X)>= 'a' && (X)<='z' ? (X):(X)+32 )


/*
Ejercicio:

    Desarrollar una función que a partir de una cadena indique si la misma es un palíndromo.

    El prototipo de la función es el siguiente:
    void esPalindromo(<definir> *p);


    Parte A:
    La cadena solamente tiene letras.

    Parte B:
    La cadena además de letras puede tener números, espacios y signos de puntuación.

    Parte C:
    La función no es sensible a mayúsculas y minúsculas.

*/

size_t nogueiraStrlen(const char * cad)
{
    size_t n = 0;
    while(*cad)
    {
        ++cad;
        ++n;
    }

    return n;
}


void esPalindromo(const char * cad)
{
    const char *p1 = cad,
                *p2 = cad + (nogueiraStrlen(cad)-1);

    while(p1 < p2)
    {
        if(ES_LETRA(*p1) && ES_LETRA(*p2))
        {
            if(A_MINUS(*p1) == A_MINUS(*p2))
            {
                p1++;
                p2--;
            }
            else
            {
                printf("\n- No es palindromo\n");
                return;
            }
        }
        else if(!ES_LETRA(*p1))
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }

    if(p1 == p2)
        printf("\n- Es palindromo\n");
}
