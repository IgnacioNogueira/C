#include "Utils.h"

int cmp_ent(const void *v1,const void *v2)
{
    return *((int *)v1)-*((int *)v2);
}

int cmp_codPed(const void *d1,const void *d2)
{
    const tPedidos *c1 = (tPedidos *)d1;
    const tPedidos *c2 = (tPedidos *)d2;

    return strcmp(c1->cod,c2->cod);
}

void imprimir(void *info,unsigned tam,void *params)
{
    int *i = (int *)info;
    printf("-%d-",*i);
}

int acumularCantidad(void **info,unsigned *tamInfo,
                      const void *info2,unsigned tamInfo2)
{
    tPedidos ** d1 = (tPedidos **)info;
    const tPedidos * d2 = (tPedidos *)info2;

    (*d1)->cant+=d2->cant;
    (*d1)->sector = ' ';
    return TODO_BIEN;
}
