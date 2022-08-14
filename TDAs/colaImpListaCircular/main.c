#include "colaImpListaCircular.h"

int main()
{
    tCola cola;
    crearCola(&cola);

    int vec[] = {1,2,3,4,5,6,0};
    int *aux = vec;
    int num;

    while(*aux)
    {
        num = *aux;
        ponerEnColaCir_mio(&cola,&num,sizeof(int));
        ++aux;
    }


    if(colaVacia(&cola))
        printf("\nNO LLENASTE NADA\n");


    while(!colaVacia(&cola))
    {
        sacarDeCola_MIO(&cola,&num,sizeof(int));
        printf("%d\n**",num);
    }

    if(colaVacia(&cola))
        printf("\nOK\n");


    return 0;
}
