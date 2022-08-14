#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "main.h"

int cmp_ent(const void *v1,const void *v2);
int cmp_codPed(const void *d1,const void *d2);
void imprimir(void *info,unsigned tam,void *params);
int acumularCantidad(void **info,unsigned *tamInfo,
                      const void *info2,unsigned tamInfo2);

#endif // UTILS_H_INCLUDED
