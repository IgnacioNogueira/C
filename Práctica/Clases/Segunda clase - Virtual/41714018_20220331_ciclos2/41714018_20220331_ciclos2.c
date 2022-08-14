#include "header.h"

/*
Imprimir por pantalla, en 4 columnas, y bien alineado, las letras mayúsculas, las letras minúsculas, y los números de la tabla ASCII, indicando el símbolo, el valor decimal y el valor hexadecimal de cada uno.

Ejemplo:


A | 65 | 41         B | 66 | 42         C | 67 | 43         D | 68 | 44

E | 69 | 45
*/


void ejercicioPantalla2()
{

    int i = 48,max= 123,j=4;

    while(i<max)
    {
        printf("%d | %c | %x\t",i,i,i);
        i++;

        if(i == 58)
        {
            i+=7;
        }
        else if(i == 91)
        {
            i+=6;
        }

        j--;
        if(j == 0)
        {
            printf("\n");
            j= 4;
        }
    }
}
