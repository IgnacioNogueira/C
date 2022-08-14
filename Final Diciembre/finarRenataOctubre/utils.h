#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "main.h"

void trozarLongitudVariable(tMatrizRala *m, char *linea);
int concatenarPosicion(const tMatrizRala *m);

int valorMatriz(const tMatrizRala *m);
int esMatrizCuadrada(const tMatrizRala *m);
int construirMatrizRala(const int *v,
                        const int *f,
                        const int *c,
                        int *mat);
#endif // UTILS_H_INCLUDED
