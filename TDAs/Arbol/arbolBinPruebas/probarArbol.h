#ifndef PROBARARBOL_H_INCLUDED
#define PROBARARBOL_H_INCLUDED

#include "archivosBasico.h"
#include "arbol.h"
#include "estructuras.h"
#include <string.h>

int probarArbol_1(tArbol *p, const char *nomArch, const char *modoAp);
int compEmp(const void *vEmp1, const void *vEmp2);
int crit(const void *e);

int critSueldo(const void *e);
int critDni(const void *e);
int critMesyDia(const void *e);
int critAn(const void *e);
int critAyN(const void *e);

int compClave(const void *, const void *);
int compClave2(const void *, const void *);
#endif // PROBARARBOL_H_INCLUDED
