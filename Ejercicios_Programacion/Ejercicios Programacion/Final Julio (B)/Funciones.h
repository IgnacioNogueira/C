#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

#include "Tipos.h"
#include "Comun.h"
#include "ListaSimplementeEnlazada.h"

void generarArchivoPedidos(const char* pathPedidos);
int procesarPedidos(const char* pathPedidos, const char* pathAcumulador);

#endif // FUNCIONES_H
