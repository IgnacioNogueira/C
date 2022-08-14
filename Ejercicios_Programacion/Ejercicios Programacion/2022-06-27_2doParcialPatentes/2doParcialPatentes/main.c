#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../SolucionPatentes/SolucionPatentes.h"

#define TDA_ARBOL_IMPL_DINAMICA
#include "../TDAArbol/TDAArbol.h"

#define TDA_LISTA_IMPL_DINAMICA_DOBLE
#include "../TDALista/TDALista.h"

#define ARG_ARCH_FACTURAS 1
#define ARG_ARCH_PARCHE	2
#define ARG_ARCH_FACT_INEX 3

// FERNANDEZ, ROCÍO BELÉN DNI 43.875.244

#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))

// FUNCIONES PRINCIPALES
void actualizarFacturas_ALU(const char* nombreArchFactAuto, const char* nombreArchParche, const char* nombreArchFactInex);
void cambiarExtension_ALU(const char* nombreArchivoOrig, char* nombreArchivoConExtension, const char* extension);
int cmpPatenteCuotaInd_ALU(const void* p1, const void* p2);
int cmpPatenteCuotaParche_ALU(const void* p1, const void* p2);
void actPatenteCuotaParche_ALU(void* actualizado, const void* actualizador);
void insertarEnLista_ALU(void* elem, void* datosAccion1);
void eliminarElementos_ALU(void* elem, void* datosAccion);

// LISTA
void crearLista_ALU(Lista* pl);
int insertarOActualizarEnListaOrd_ALU(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
void vaciarYGrabarLista_ALU(Lista* pl, const char* pathArch);

// ARBOL
void crearArbol_ALU(Arbol* pa);
booleano cargarArbolDeArchivoOrdenado_ALU(Arbol* pa, size_t tamElem, const char* nomArch);
booleano cargarDatosOrd_ALU(Arbol* pa, FILE* arch, int li, int ls, void* param);
void recorrerArbolEnOrden_ALU(Arbol* pa, Accion accion, void* param1);
booleano eliminarDeArbol_ALU(Arbol* pa, void* dato, size_t tamElem, Cmp cmp);
Arbol* buscarRaizDeArbol_ALU(const Arbol* pa, void* dato, Cmp cmp);
void eliminarRaizDeArbol_ALU(Arbol* pae);
int alturaArbol_ALU(const Arbol* pa);
Arbol* mayorDeArbol_ALU(const Arbol* pa);
Arbol* menorDeArbol_ALU(const Arbol* pa);
booleano buscarEnArbol_ALU(const Arbol* pa, void* dato, size_t tamElem, Cmp cmp);

int main(int argc, char* argv[])
{
	generarArchivoFacturas();
	generarArchivoPatentesParche();

	puts("Archivo Facturas Automotor");
	mostrarFacturasAuto(argv[ARG_ARCH_FACTURAS]);

	puts("\nArchivo Parche");
	mostrarParche(argv[ARG_ARCH_PARCHE]);

///	actualizarFacturas(argv[ARG_ARCH_FACTURAS], argv[ARG_ARCH_PARCHE], argv[ARG_ARCH_FACT_INEX]);
	actualizarFacturas_ALU(argv[ARG_ARCH_FACTURAS], argv[ARG_ARCH_PARCHE], argv[ARG_ARCH_FACT_INEX]);

	puts("\nArchivo Facturas Automotor actualizado");
	mostrarFacturasAuto(argv[ARG_ARCH_FACTURAS]);

	puts("\nFacturas Inexistentes");
	mostrarParche(argv[ARG_ARCH_FACT_INEX]);

	return 0;
}


void actualizarFacturas_ALU(const char* nombreArchFactAuto, const char* nombreArchParche, const char* nombreArchFactInex)
{
	Arbol idxFactura;
	crearArbol_ALU(&idxFactura);

	char nombreArchIdxFactAuto[30];
	cambiarExtension_ALU(nombreArchFactAuto, nombreArchIdxFactAuto, "idx");

	cargarArbolDeArchivoOrdenado_ALU(&idxFactura, sizeof(IndFactura), nombreArchIdxFactAuto);

	Lista regInexistentes;
	crearLista_ALU(&regInexistentes);

	FILE* archFactAuto = fopen(nombreArchFactAuto, "r+b");
	if(!archFactAuto)
        return;

	recorrerArbolEnOrden_ALU(&idxFactura, insertarEnLista_ALU, &regInexistentes);
    recorrerLista(&regInexistentes, eliminarElementos_ALU, &idxFactura);

	imprimirArbol(&idxFactura, imprimirIndice, NULL);

    FILE* archParche = fopen(nombreArchParche, "rb");
    if(!archParche)
        return;

    booleano ret;
    FacturaAutomotor lectFact;
    ParcheFacturaAutomotor lectParche;
    IndFactura indActual;
    fread(&lectParche, sizeof(ParcheFacturaAutomotor), 1, archParche);
    while(!feof(archParche))
    {
        strcpy(indActual.patente, lectParche.patente);
        indActual.cuota = lectParche.cuota;
        ret = buscarEnArbol_ALU(&idxFactura, &indActual, sizeof(IndFactura), cmpPatenteCuotaInd_ALU);

        if(ret == falso)
            insertarOActualizarEnListaOrd_ALU(&regInexistentes, &lectParche, sizeof(ParcheFacturaAutomotor), cmpPatenteCuotaParche_ALU, actPatenteCuotaParche_ALU);
        else
        {
            fseek(archFactAuto, indActual.nroRegistro * sizeof(FacturaAutomotor), SEEK_SET);
            fread(&lectFact, sizeof(FacturaAutomotor), 1, archFactAuto);
            lectFact.importeAPagar += lectParche.importeAdicionalAPagar;
            fseek(archFactAuto, -1L * (long)sizeof(FacturaAutomotor), SEEK_CUR);
            fwrite(&lectFact, sizeof(FacturaAutomotor), 1, archFactAuto);
        }
        fread(&lectParche, sizeof(ParcheFacturaAutomotor), 1, archParche);
    }

    vaciarYGrabarLista_ALU(&regInexistentes, nombreArchFactInex);
    vaciarArbol(&idxFactura);

    fclose(archFactAuto);
    fclose(archParche);
}

void cambiarExtension_ALU(const char* nombreArchivoOrig, char* nombreArchivoConExtension, const char* extension)
{
    strcpy(nombreArchivoConExtension, nombreArchivoOrig);

    char* punto = strrchr(nombreArchivoConExtension, '.');
    strcpy(punto+1, extension);
}

void insertarEnLista_ALU(void* elem, void* datosAccion)
{
    Lista* plRegInexistentes = (Lista*)datosAccion;
    IndFactura* idxAct = (IndFactura*)elem;

    if((idxAct->nroRegistro) == -1)
    {
        ParcheFacturaAutomotor parcheEscritura;
        strcpy(parcheEscritura.patente, idxAct->patente);
        parcheEscritura.cuota = idxAct->cuota;
        parcheEscritura.importeAdicionalAPagar = 0;
        insertarOActualizarEnListaOrd_ALU(plRegInexistentes, &parcheEscritura, sizeof(parcheEscritura), cmpPatenteCuotaParche_ALU, actPatenteCuotaParche_ALU);
    }
}

void eliminarElementos_ALU(void* elem, void* datosAccion)
{
    ParcheFacturaAutomotor* parcheLectura = (ParcheFacturaAutomotor*)elem;
    Arbol* pa = (Arbol*)datosAccion;
    IndFactura idxElimina;

    strcpy(idxElimina.patente, parcheLectura->patente);
    idxElimina.cuota = parcheLectura->cuota;

    eliminarDeArbol_ALU(pa, &idxElimina, sizeof(IndFactura), cmpPatenteCuotaInd_ALU);
}

int cmpPatenteCuotaInd_ALU(const void* p1, const void* p2)
{
    IndFactura* d1 = (IndFactura*)p1;
    IndFactura* d2 = (IndFactura*)p2;

    int comp = strcmp(d1->patente, d2->patente);

    if(comp == 0)
        return d1->cuota - d2->cuota;
    else
        return comp;
}

int cmpPatenteCuotaParche_ALU(const void* p1, const void* p2)
{
    ParcheFacturaAutomotor* d1 = (ParcheFacturaAutomotor*)p1;
    ParcheFacturaAutomotor* d2 = (ParcheFacturaAutomotor*)p2;

    int comp = strcmp(d1->patente, d2->patente);

    if(comp == 0)
        return d1->cuota - d2->cuota;
    else
        return comp;
}

void actPatenteCuotaParche_ALU(void* actualizado, const void* actualizador)
{
    ParcheFacturaAutomotor* d1 = (ParcheFacturaAutomotor*)actualizado;
    const ParcheFacturaAutomotor* d2 = (const ParcheFacturaAutomotor*)actualizador;

    d1->importeAdicionalAPagar += d2->importeAdicionalAPagar;
}

// LISTA

void crearLista_ALU(Lista* pl)
{
    *pl = NULL;
}

int insertarOActualizarEnListaOrd_ALU(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    NodoD* act = *pl;
    NodoD* ant = NULL;
    NodoD* sig = NULL;

    if(act)
    {
        while(act->ant && cmp(elem, act->elem) < 0)
            act = act->ant;

        while(act->sig && cmp(elem, act->elem) > 0)
            act = act->sig;

        int comp = cmp(elem, act->elem);

        if(comp == 0)
        {
            if(actualizar)
            {
                actualizar(act->elem, elem);
                return TODO_OK;
            }
            return DUPLICADO;
        }

        if(comp < 0)
        {
            ant = act->ant;
            sig = act;
        }
        else
        {
            ant = act;
            sig = act->sig;
        }
    }

    NodoD* nue = (NodoD*)malloc(sizeof(NodoD));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(elemNodo);
        free(nue);
        return SIN_MEM;
    }

    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->ant = ant;
    nue->sig = sig;

    if(ant)
        ant->sig = nue;

    if(sig)
        sig->ant = nue;

    *pl = nue;

    return TODO_OK;
}

void vaciarYGrabarLista_ALU(Lista* pl, const char* pathArch)
{
    FILE* arch = fopen(pathArch, "wb");
    if(!arch)
        return;

    NodoD* act = *pl;
    NodoD* nae;

    if(act)
    {
        while(act->ant)
            act = act->ant;

        while(act)
        {
            fwrite(act->elem, act->tamElem, 1, arch);
            nae = act;
            act = act->sig;
            free(nae->elem);
            free(nae);
        }

        *pl = NULL;
    }

    fclose(arch);
}

// ARBOL

void crearArbol_ALU(Arbol* pa)
{
    *pa = NULL;
}

booleano cargarArbolDeArchivoOrdenado_ALU(Arbol* pa, size_t tamElem, const char* nomArch)
{
    FILE* arch = fopen(nomArch, "rb");

    if(*pa || !arch)
        return falso;

    fseek(arch, 0L, SEEK_END);
    int cantReg = ftell(arch) / tamElem;

    booleano ret = cargarDatosOrd_ALU(pa, arch, 0, cantReg-1, &tamElem);

    fclose(arch);
    return ret;
}

booleano cargarDatosOrd_ALU(Arbol* pa, FILE* arch, int li, int ls, void* param)
{
    if(li > ls)
        return verdadero;

    int medio = (li + ls) / 2;
    size_t tamElem = *((size_t*)param);

    (*pa) = (NodoA*)malloc(sizeof(NodoA));

    if(!*pa)
        return falso;

    (*pa)->elem = malloc(tamElem);

    if(!(*pa)->elem)
    {
        free(*pa);
        return falso;
    }

    fseek(arch, medio*tamElem, SEEK_SET);
    fread((*pa)->elem, tamElem, 1, arch);

    (*pa)->tamElem = tamElem;
    (*pa)->hIzq = (*pa)->hDer = NULL;

    booleano ret = cargarDatosOrd_ALU(&(*pa)->hIzq, arch, li, medio-1, param);
    if(ret != verdadero)
        return ret;

    return cargarDatosOrd_ALU(&(*pa)->hDer, arch, medio+1, ls, param);
}

void recorrerArbolEnOrden_ALU(Arbol* pa, Accion accion, void* param)
{
    if(!*pa)
        return;
    recorrerArbolEnOrden_ALU(&(*pa)->hIzq, accion, param);
    accion((*pa)->elem, param);
    recorrerArbolEnOrden_ALU(&(*pa)->hDer, accion, param);
}

booleano eliminarDeArbol_ALU(Arbol* pa, void* dato, size_t tamElem, Cmp cmp)
{
    Arbol* pae = buscarRaizDeArbol_ALU(pa, dato, cmp);

    if(!pae)
        return falso;

    memcpy(dato, (*pae)->elem, min(tamElem, (*pae)->tamElem));
    free((*pae)->elem);

    eliminarRaizDeArbol_ALU(pae);

    return verdadero;
}

Arbol* buscarRaizDeArbol_ALU(const Arbol* pa, void* dato, Cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(dato, (*pa)->elem);

    if(comp == 0)
        return (Arbol*)pa;

    return buscarRaizDeArbol_ALU(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, dato, cmp);
}

void eliminarRaizDeArbol_ALU(Arbol* pae)
{
    if(!((*pae)->hIzq) && !((*pae)->hDer))
    {
        free(*pae);
        *pae = NULL;
        return;
    }

    int hi = alturaArbol_ALU(&(*pae)->hIzq);
    int hd = alturaArbol_ALU(&(*pae)->hDer);

    Arbol* par = (hi > hd ? mayorDeArbol_ALU(&(*pae)->hIzq) : menorDeArbol_ALU(&(*pae)->hDer));

    (*pae)->elem = (*par)->elem;
    (*pae)->tamElem = (*par)->tamElem;

    eliminarRaizDeArbol_ALU(par);
}

int alturaArbol_ALU(const Arbol* pa)
{
    if(!*pa)
        return 0;

    return max(alturaArbol_ALU(&(*pa)->hIzq), alturaArbol_ALU(&(*pa)->hDer)) + 1;
}

Arbol* mayorDeArbol_ALU(const Arbol* pa)
{
    if(!(*pa)->hDer)
        return (Arbol*)pa;

    return menorDeArbol_ALU(&(*pa)->hDer);
}

Arbol* menorDeArbol_ALU(const Arbol* pa)
{
    if(!(*pa)->hIzq)
        return (Arbol*)pa;

    return menorDeArbol_ALU(&(*pa)->hIzq);
}

booleano buscarEnArbol_ALU(const Arbol* pa, void* dato, size_t tamElem, Cmp cmp)
{
    if(!*pa)
        return falso;

    int comp = cmp(dato, (*pa)->elem);

    if(comp == 0)
    {
        memcpy(dato, (*pa)->elem, min(tamElem, (*pa)->tamElem));
        return verdadero;
    }

    return buscarEnArbol_ALU(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, dato, tamElem, cmp);
}
