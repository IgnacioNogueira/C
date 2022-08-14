#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Solucion1erParcialEcommerce/Solucion1erParcialEcommerce.h"

#define TDA_LISTA_IMPL_DINAMICA
#include "../TDALista/TDALista.h"

#define ARG_CLIENTES    1
#define ARG_PRODUCTOS   2
#define ARG_REGLAS      3
#define ARG_OFERTAS     4

#define TAM_LINEA 30
#define ERR_LINEA_LARGA 5

#define min(a,b) ((a) <= (b) ? (a) : (b))

int generarArchivoOfertas_ALU(const char* nombreArchClientes, const char* nombreArchProductos, const char* nombreArchReglas, const char* nombreArchOfertas);
int generarArchivoOfertasTxt_ALU(const char* nombreArchivoOfertas, const char* nombreArchivoOfertasTxt);
int cargarReglasALista_ALU(Lista* lReglas, const char* pathReglas);
int txtVariableABin_ALU(char* linea, Regla* regRegla);
booleano errorFatal_ALU(int ret);
int compararNivel_ALU(const void* d1, const void* d2);
void crearLista_ALU(Lista* pl);
int insertarEnListaOrd_ALU(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
booleano buscarEnListaOrd_ALU(const Lista* pl, void* elem, size_t tamElem, Cmp cmp);
void vaciarLista_ALU(Lista* pl);

int main(int argc, char* argv[])
{
    generarArchivoClientes(argv[ARG_CLIENTES]);
    generarArchivoProductos(argv[ARG_PRODUCTOS]);
    generarArchivoReglas(argv[ARG_REGLAS]);

///    generarArchivoOfertas(argv[ARG_CLIENTES], argv[ARG_PRODUCTOS], argv[ARG_REGLAS], argv[ARG_OFERTAS]);
    generarArchivoOfertas_ALU(argv[ARG_CLIENTES], argv[ARG_PRODUCTOS], argv[ARG_REGLAS], argv[ARG_OFERTAS]);

    if(mostrarArchivoOfertas(argv[ARG_OFERTAS]) != TODO_OK)
        printf("\n\nError al mostrar el archivo de ofertas.\n");

    char nombreArchivoOfertasTxt[251];
    cambiarExtension(argv[ARG_OFERTAS], nombreArchivoOfertasTxt, ".txt");

///    generarArchivoOfertasTxt(argv[ARG_OFERTAS], nombreArchivoOfertasTxt);
    generarArchivoOfertasTxt_ALU(argv[ARG_OFERTAS], nombreArchivoOfertasTxt);

    if(mostrarArchivoOfertasTxt(nombreArchivoOfertasTxt))
        printf("\n\nError al mostrar el archivo de ofertas txt.\n");

    return 0;
}


int generarArchivoOfertas_ALU(const char* nombreArchClientes, const char* nombreArchProductos, const char* nombreArchReglas, const char* nombreArchOfertas)
{
    // Cargo el archivo Reglas.txt a un TDA Lista Impl Dinamica

    Lista lReglas;
    int ret;
    crearLista_ALU(&lReglas);
    if((ret = cargarReglasALista_ALU(&lReglas, nombreArchReglas)) != TODO_OK)
        return ret;

    // Abrir archivos para generar oferta

    FILE* archClientes = fopen(nombreArchClientes, "rb");
    FILE* archProductos = fopen(nombreArchProductos, "rb");
    FILE* archOfertas = fopen(nombreArchOfertas, "wb");

    if(!archClientes || !archProductos || !archOfertas)
    {
        fclose(archClientes);
        fclose(archProductos);
        fclose(archOfertas);
        return ERR_ARCHIVO;
    }

    Cliente clienteAct;
    Regla reglaAct;
    Producto prodAct;
    Oferta ofertaAct;
    float desc;

    // Proceso los distintos clientes

    fread(&clienteAct, sizeof(Cliente), 1, archClientes);
    while(!feof(archClientes))
    {
        // Busco la regla acorde al nivel del cliente actual. No sería correcto usar la primitiva eliminarDeListaOrdPorValor
        // ya que la regla se elimina de la lista, se pierde y podría ser necesitada por otro cliente del mismo nivel
        reglaAct.nivel = clienteAct.nivel;
        buscarEnListaOrd_ALU(&lReglas, &reglaAct, sizeof(Regla), compararNivel_ALU);
        // Proceso los distintos productos
        fread(&prodAct, sizeof(Producto), 1, archProductos);
        while(!feof(archProductos))
        {
            // Completo el usuario y el producto de la oferta con el cliente y el producto procesados
            strcpy(ofertaAct.usuario, clienteAct.usuario);
            strcpy(ofertaAct.producto, prodAct.codigo);
            // Calculo descuento. Si es mayor al tope, solo se descuenta el tope
            desc = prodAct.precio * reglaAct.porcDescuento / 100;
            if(desc > reglaAct.topeDescuento)
                desc = reglaAct.topeDescuento;
            ofertaAct.precio = prodAct.precio - desc;
            // Se calcula si el precio final es aplicable para envio gratis
            if(ofertaAct.precio >= reglaAct.minimoParaEnvioGratis)
                ofertaAct.envioGratis = verdadero;
            // Se escribe en el archivo de ofertas binario
            fwrite(&ofertaAct, sizeof(Oferta), 1, archOfertas);
            // Se lee otro producto
            fread(&prodAct, sizeof(Producto), 1, archProductos);
        }
        // Al finalizar se leen todas las posibilidades de producto con determinado cliente, pasamos al siguiente cliente
        fread(&clienteAct, sizeof(Cliente), 1, archClientes);
    }

    // Liberamos la memoria de la lista de reglas ya que no se necesita más y cerramos los archivos

    vaciarLista_ALU(&lReglas);

    fclose(archClientes);
    fclose(archProductos);
    fclose(archOfertas);

    return TODO_OK;
}


int generarArchivoOfertasTxt_ALU(const char* nombreArchivoOfertas, const char* nombreArchivoOfertasTxt)
{
    FILE* archOfertas = fopen(nombreArchivoOfertas, "rb");
    FILE* archOfertasTxt = fopen(nombreArchivoOfertasTxt, "wt");

    if(!archOfertas || !archOfertasTxt)
    {
        fclose(archOfertas);
        fclose(archOfertasTxt);
        return ERR_ARCHIVO;
    }

    Oferta ofertaAct;
    char usuarioAct[21];
    char envioGratis[3];

    fread(&ofertaAct, sizeof(Oferta), 1, archOfertas);
    while(!feof(archOfertas))
    {
        strcpy(usuarioAct, ofertaAct.usuario);
        fprintf(archOfertasTxt, "%s\n", ofertaAct.usuario);
        while(!feof(archOfertas) && strcmp(usuarioAct, ofertaAct.usuario) == 0)
        {
            if(ofertaAct.envioGratis == verdadero)
                strcpy(envioGratis, "Si");
            else
                strcpy(envioGratis, "No");
            envioGratis[2] = '\0';
            fprintf(archOfertasTxt, "\t%-18s%8.2f\t%-s\n", ofertaAct.producto, ofertaAct.precio, envioGratis);
            fread(&ofertaAct, sizeof(Oferta), 1, archOfertas);
        }
        // Al terminar el while se leyeron todas las ofertas por producto del cliente actual y ofertaAct que queda cargada
        // es de un cliente diferente, entonces hay que cambiar el usuario de usuarioAct (strcpy al principio) y volver al
        // ciclo de mientras el cliente sea el mismo. Esto permite imprimir en el archivo txt una sola vez el usuario del cliente
    }

    // Cerramos los archivos antes de terminar la función

    fclose(archOfertas);
    fclose(archOfertasTxt);

    return TODO_OK;
}

/// Función para cargar el archivo Reglas.txt en su totalidad en un TDA Lista Implementación Dinámica

int cargarReglasALista_ALU(Lista* lReglas, const char* pathReglas)
{
    FILE* archReglas = fopen(pathReglas, "rt");

    if(!archReglas)
        return ERR_ARCHIVO;

    Regla regRegla;
    char linea[TAM_LINEA];
    int ret = TODO_OK;

    fgets(linea, TAM_LINEA, archReglas);
    while(!feof(archReglas) && !errorFatal_ALU(ret))
    {
        ret = txtVariableABin_ALU(linea, &regRegla);
        if(ret == TODO_OK)
            insertarEnListaOrd_ALU(lReglas, &regRegla, sizeof(Regla), compararNivel_ALU);

        fgets(linea, TAM_LINEA, archReglas);
    }

    if(errorFatal_ALU(ret))
        return ret;

    // Cerramos el archivo antes de terminar la función

    fclose(archReglas);

    return TODO_OK;
}

/// Función para cargar la línea de un registro de un archivo de texto con longitud variable a una estructura

int txtVariableABin_ALU(char* linea, Regla* regRegla)
{
    char* car = linea;
    car = strchr(linea, '\n');

    if(!car)
        return ERR_LINEA_LARGA;

    *car = '\0';
    car = strrchr(linea, '\t');
    sscanf(car+1, "%f", &(regRegla->minimoParaEnvioGratis));

    *car = '\0';
    car = strrchr(linea, '\t');
    sscanf(car+1, "%f", &(regRegla->topeDescuento));

    *car = '\0';
    car = strrchr(linea, '\t');
    sscanf(car+1, "%f", &(regRegla->porcDescuento));

    *car = '\0';
    sscanf(linea, "%d", &(regRegla->nivel));

    return TODO_OK;
}

/// Si no lee la línea completa, se arrastra el error a los otros registros y hay que parar la lectura de archivo

booleano errorFatal_ALU(int ret)
{
    if(ret == ERR_LINEA_LARGA)
        return verdadero;
    return falso;
}

/// Función cmp para recorrer la lista

int compararNivel_ALU(const void* d1, const void* d2)
{
    Regla* r1 = (Regla*)d1;
    Regla* r2 = (Regla*)d2;

    return r1->nivel - r2->nivel;
}

/// Primitivas de TDA Lista Implementación Dinámica

void crearLista_ALU(Lista* pl)
{
    *pl = NULL;
}

int insertarEnListaOrd_ALU(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(!*pl || cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
        return SIN_MEM;

    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}

booleano buscarEnListaOrd_ALU(const Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(!*pl || cmp(elem, (*pl)->elem) != 0)
        return falso;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return verdadero;
}

void vaciarLista_ALU(Lista* pl)
{
    Nodo* nae;
    while(*pl)
    {
        nae = *pl;
        *pl = nae->sig;
        free(nae->elem);
        free(nae);
    }
}
