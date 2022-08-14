#include "header.h"

int main()
{

    unsigned char vec[] = {1,2,0,4,5,3,2,0,2,2,2,5,5,199};
    unsigned char max = 0;
    int analiz = analizar(vec,2);
    //int anali2= analizar2(vec,2);
/*
    if(!anali2)
    {
        printf("\nEl valor introducido no es correcto");

    }
    else
    {
        printf("La cantidad de veces que se repite el valor es: %d",analiz);
        max = maximoValor(vec);
        printf("\nEl maximo valor de vec es: %d",max);
    }
*/
    return 0;
}
