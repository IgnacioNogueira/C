#include "header.h"

/*
Imprimir por pantalla, las letras may�sculas, las letras min�sculas, y los n�meros de la tabla ASCII, indicando el s�mbolo y el valor decimal, una letra por cada l�nea:

EJ:

A | 65
B | 66
C | 67
D | 68
*/

void ejercicioPantalla1()
{

    int i = 48,max= 123;

    while(i<max)
    {
        printf("\n%d | %c\n",i,i);
        i++;

        if(i == 58)
        {
            i+=7;
        }
        else if(i == 91)
        {
            i+=6;
        }

    }
}

