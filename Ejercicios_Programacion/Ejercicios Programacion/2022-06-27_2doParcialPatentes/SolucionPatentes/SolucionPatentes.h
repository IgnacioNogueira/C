#ifndef SOLUCION_PATENTES_H
#define SOLUCION_PATENTES_H

#define TDA_ARBOL_IMPL_DINAMICA
#include "../TDAArbol/TDAArbol.h"

#define TDA_LISTA_IMPL_DINAMICA_DOBLE
#include "../TDALista/TDALista.h"


typedef struct
{
	char patente[7];
	int cuota;
	int dniPropietario;
	char nombrePropietario[31];
	double importeAPagar;
}
FacturaAutomotor;


typedef struct
{
	char patente[7];
	int cuota;
	double importeAdicionalAPagar;
}
ParcheFacturaAutomotor;


typedef struct
{
	char patente[7];
	int cuota;
	long nroRegistro;
}
IndFactura;


int generarArchivoFacturas();
int generarArchivoPatentesParche();
void mostrarFacturasAuto(const char* nombreArchFactAuto);
void mostrarParche(const char* nombreArchParche);
void cambiarExtension(const char* nombreArchivoOrig, char* nombreArchivoConExtension, const char* extension);
void imprimirIndice(const void* pvElem, void* pvDatos, int nivel); /// Para pasarla a imprimirArbol().
void actualizarFacturas(const char* nombreArchFactAuto, const char* nombreArchParche, const char* nombreArchFactInex);
void actualizarFacturas_ALU(const char* nombreArchFactAuto, const char* nombreArchParche, const char* nombreArchFactInex);


#endif // SOLUCION_PATENTES_H
