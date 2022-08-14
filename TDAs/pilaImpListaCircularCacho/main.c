#include "pilaImpListaCircular.h"

int main()
{
    int vec[] = {1,2,3,4,5,6,0};
    int *aux = vec;
    int num;
    tPila pila;

    while(*aux)
    {
        num = *aux;
        ponerEnPilaCircular_MIO(&pila,&num,sizeof(int));
        ++aux;
    }

    while(!pilaVacia(&pila))
    {
        sacarDePilaCircular_MIO(&pila,&num,sizeof(int));
        printf("%d\n",num);
    }



    return 0;
}
