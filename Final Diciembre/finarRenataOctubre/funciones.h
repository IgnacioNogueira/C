#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "main.h"
#include "utils.h"

int cargar_mat_rala(const char *archivoMatrizRala, int *matRala);
int verificar_mat(const tMatrizRala *m);
int cargar_mat_rala(const int *v,
                        const int *f,
                        const int *c,
                        int *mat);

#endif // FUNCIONES_H_INCLUDED
