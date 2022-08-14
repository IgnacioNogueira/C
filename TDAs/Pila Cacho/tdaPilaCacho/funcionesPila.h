#ifndef FUNCIONESPILA_H_INCLUDED
#define FUNCIONESPILA_H_INCLUDED

#include "pila.h"
#include "pilaDinamica.h"
#include "pilaEstatica.h"

char * sumarNGrandes (char * n1,char * n2, char * resultado);
char sumarValores(char valorPila1, char valorPila2,unsigned char *carry);
void valoresRestantes(tPilaD *pil, unsigned char * carry, tPilaD *pil3);


#endif // FUNCIONESPILA_H_INCLUDED
