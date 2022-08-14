#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "header.h"
#include "tdaLista.h"

#define ERROR_ARCH -1

int cmp_cp(const void *v1,const void *v2);
int cmpSectorYprod(const void *v1,const void *v2);

int cmpCodProdSectorYOficina(const void *v1,const void *v2);

int acumularCantidadPedida(void ** info1,unsigned *tamInfo1,
                           const void *info2,unsigned tamInfo2);
int crearLotePrueba(const char *nombreArchivo);

void mostrarPedidos(const void *d);
int mostrarArchivoFinal(char * nombreArchivoFinal);
void trozarLongitudVariable(tPedidos *ped,char *s);


#endif // UTILS_H_INCLUDED
