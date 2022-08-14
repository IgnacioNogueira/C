/**//*             En los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "PÉREZ DEL RÍO"
#define NOMBRE      "Juan Manuel"
#define DOCUMENTO   "22.333.444"
#define COMISION    "07(7299)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/
#include <stdlib.h>
#include <string.h>

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**/ /* CUALQUIER FUNCIÓN AUXILIAR DE SU AUTORÍA, DESARRÓLLELA DESDE ACÁ */ /**/

#define A_MAYUS(X)((X)>='a' && (X)<='z' ? (X)-32:(X))
#define A_MINUS(X)((X)>='A' && (X)<='Z' ? (X)+32:(X))
#define ES_BLANCO(X)((X) == ' ' || (X)== '\t')
#define MINIMO(X,Y)((X)<=(Y)?(X):(Y))

//punto 1

size_t strlen_MIO(const char *cad);
void *memcpy_mio(void *dest,const void *orig, size_t cant);
char * strcpy_MIO(char *dest, const char *orig);
int strncmp_MIO(const char* cad1,const char *cad2,size_t cant);
char * strstr_MIO(const char* cad,const char *subcad);
void *memmove_MIO(void *dest,const void *orig,size_t cant);

void sinEspacioPrincipioyFin(char *nomProd);
void unSoloEspacio(char *nomProd);
void camelCase(char *nomProd);
void normalizarProductos(tProducto *prod);

int cmpId(const void *d1,const void *d2);
int ponerEnOrdLista(tLista *pl,const void *pd,unsigned tam,
                    int (*cmpId)(const void*, const void*));

void trozarLongitudVariable(tProducto *prod,char *linea);

//Punto 2
int sacarPrimeroDeLista(tLista *pl,void *d,unsigned tam);
int verPrimeroLista(const tLista *pl,void *d,unsigned cantBytes);

//Punto 3
void *acumulacionCantProd(void *dato,const void *cant);
int eliminarYacumOrd(tLista *pl,int(*cmp)(const void*,const void*),void*(acum)(void *,const void*));
int elimDup (tLista * lista,int(*comparar)(const void *, const void *));
int elimNult (tLista * lista, unsigned cant);



/**/ /* CUALQUIER FUNCIÓN AUXILIAR DE SU AUTORÍA, DESARRÓLLELA HASTA ACÁ */ /**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/** para el PUNTO 1 **/

void sinEspacioPrincipioyFin(char *nomProd)
{
    char *p1 = nomProd,
          *p2 = nomProd + (strlen_MIO(nomProd)-1);

    while(ES_BLANCO(*p2))
    {
        --p2;
    }

    *(p2+1) = '\0'; //aca

    while(ES_BLANCO(*p1))
    {
        ++p1;
    }

    strcpy_MIO(nomProd,p1);
}

void unSoloEspacio(char *nomProd)
{
    char *p1 = nomProd,*p2;

    while((p2 = strstr_MIO(p1,"  ")) != NULL)
    {
        memmove_MIO(p2,p2+1,strlen_MIO(p2));
    }

}

void camelCase(char *nomProd)
{
    *nomProd = A_MAYUS(*nomProd);
    ++nomProd;

    while(!ES_BLANCO(*nomProd))
    {
        *nomProd = A_MINUS(*nomProd);
        ++nomProd;
    }

    ++nomProd;
    *nomProd = A_MAYUS(*nomProd);
    ++nomProd;

    while(*nomProd)
    {
        *nomProd = A_MINUS(*nomProd);
        ++nomProd;
    }
}

size_t strlen_MIO(const char *cad)
{
    size_t n = 0;

    while(*cad)
    {
        ++n;
        ++cad;
    }

    return n;
}

void *memcpy_mio(void *dest,const void *orig, size_t cant)
{
    void *aux = dest;

    while(--cant)
    {
        *((char *)dest) = *((char *)orig);
        ++dest;
        ++orig;
    }

    return aux;
}

char * strcpy_MIO(char *dest, const char *orig)
{
    char *p = dest;

    while(*orig)
    {
        *dest = *orig;
        ++dest;
        ++orig;
    }

    *dest = '\0';

    return p;
}

int strncmp_MIO(const char* cad1,const char *cad2,size_t cant)
{
    while(*cad1 && --cant && *cad1 == *cad2)
    {
        ++cad1;
        ++cad2;
    }

    return *(unsigned char*)cad1 - *(unsigned char*)cad2;
}

char * strstr_MIO(const char* cad,const char *subcad)
{
    size_t tamSub = strlen_MIO(subcad);

    while(*cad && strncmp_MIO(cad,subcad,tamSub))
        ++cad;

    return *cad ? (char *)cad:NULL;
}

void *memmove_MIO(void *dest,const void *orig,size_t cant)
{
    char *pDest = (char *)dest;
    const char *pOrig = (const char*)orig;

    if((pDest > pOrig) && (pDest < pOrig + cant))
    {
        while(cant)
        {
            *(pDest + cant) = *(pOrig + cant);
            --cant;
        }

    }
    else
    {
        while(cant)
        {
            *pDest = *pOrig;
            ++pDest;
            ++pOrig;
            --cant;
        }
    }

    return pDest;
}


void normalizarProductos(tProducto *prod)
{
    sinEspacioPrincipioyFin(prod->descripcion);
    unSoloEspacio(prod->descripcion);
    camelCase(prod->descripcion);

}

int cmpId(const void *d1,const void *d2)
{
    unsigned int id1 = ((tProducto*)d1)->idProducto;
    unsigned int id2 = ((tProducto*)d2)->idProducto;

    return id1-id2;
}

int ponerEnOrdLista(tLista *pl,const void *pd,unsigned tam,int (*cmpId)(const void*, const void*))
{
    tNodoL *nue;

    while(*pl && (cmpId(pd,(*pl)->info)) > 0) // LA COMP ENTRE DATO POR PARAM Y LA INFO QUE ESTÁ EN LA LISTA. SI EL DATO PASADO ES MÁS GRANDE QUE LO QUE ESTÁ EN LA LISTA...
        pl = &(*pl)->sig;

    nue = (tNodoL*)malloc(sizeof(tNodoL));

    if(!nue)
    {
        return 0;  ///LISTA LLENA
    }

    nue->info = (tNodoL*)malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0;  ///LISTA LLENA
    }

    memcpy(nue->info,pd,tam);
    nue->tamInfo = tam;
    nue->sig = *pl;
    *pl = nue; //para que apunte al nuevo elemento

    return 1;

}

void trozarLongitudVariable(tProducto *prod,char *linea)
{
    char * aux = strchr(linea,'\n');
    *aux = '\0';

    aux = strrchr(linea,';');
    sscanf(aux+1,"%f",&prod->precioUnitario);
    *aux = '\0';

    aux = strrchr(linea,';');
    sscanf(aux+1,"%d",&prod->cantidad);
    *aux ='\0';

    aux = strrchr(linea,';');
    sscanf(aux+1,"%d/%d/%d",&prod->fechaPrecio.dia,
           &prod->fechaPrecio.mes,
           &prod->fechaPrecio.anio
          );
    *aux = '\0';

    aux = strrchr(linea,';');
    strcpy(prod->descripcion,aux+1);
    *aux = '\0';

    sscanf(linea,"%u",&prod->idProducto);
}


int punto_uno_MIO(FILE *fpPantalla,
                  const char *nombreArchMaestro1,
                  const char *nombreArchMaestro2,
                  tLista *listaA,
                  tLista *listaB)
{

    tProducto prod;
    char linea[100];

    FILE * fpm1,*fpm2;

    fpm1 = fopen(nombreArchMaestro1,"rb");

    if(!fpm1)
    {
        return -1;
    }

    fpm2 = fopen(nombreArchMaestro2,"rt");

    if(!fpm2)
    {
        fclose(fpm1);
        return -2;
    }

    fread(&prod,sizeof(tProducto),1,fpm1);

    while(!feof(fpm1))
    {
        normalizarProductos(&prod);
        ponerEnOrdLista(listaA,&prod,sizeof(tProducto),cmpId);
        fread(&prod,sizeof(tProducto),1,fpm1);
    }

    while(fgets(linea,sizeof(linea),fpm2))
    {
        trozarLongitudVariable(&prod,linea);
        normalizarProductos(&prod);
        ponerEnOrdLista(listaB,&prod,sizeof(tProducto),cmpId);
    }

    fclose(fpm1);
    fclose(fpm2);

    return 0;
}
/** FIN de PUNTO 1 **/




/** para el PUNTO 2 **/


int sacarPrimeroDeLista(tLista *pl,void *d,unsigned tam)
{
    tNodoL * aux = *pl;

    if(aux == NULL)
        return 0;

    *pl = aux->sig;
    memcpy(d,aux->info,MINIMO(tam,aux->tamInfo));
    free(aux->info);
    free(aux);

    return TODO_BIEN;
}

int verPrimeroLista(const tLista *pl,void *d,unsigned cantBytes)
{
    if(*pl == NULL)
        return 0;
    memcpy(d,(*pl)->info,MINIMO(cantBytes,(*pl)->tamInfo));
    return TODO_BIEN;
}

int punto_dos_MIO(FILE *fpPantalla,
                  tLista *listaA,
                  tLista *listaB,
                  tLista *listaF)
{
    tProducto prod;

    if(listaVacia(listaA) || listaVacia(listaB))
        return 0;

    //printf("\nLista A: ");
    while(!listaVacia(listaA))
    {
        //verPrimeroLista(listaA,&prod,sizeof(tProducto));
        /*printf("%u %-*.*s %d %.2f\n\n",prod.idProducto,
                                 (int)sizeof(prod.descripcion)-1,
                                 (int)sizeof(prod.descripcion)-1,
                                 prod.descripcion,
                                 prod.cantidad,
                                 prod.precioUnitario);
        */
        sacarPrimeroDeLista(listaA,&prod,sizeof(tProducto));
        ponerEnOrdLista(listaF,&prod,sizeof(tProducto),cmpId);

    }

    //printf("\n\nLista B: ");
    while(!listaVacia(listaB))
    {
        //verPrimeroLista(listaB,&prod,sizeof(tProducto));
        /*printf("%u %-*.*s %d %.2f\n\n",prod.idProducto,
                                 (int)sizeof(prod.descripcion)-1,
                                 (int)sizeof(prod.descripcion)-1,
                                 prod.descripcion,
                                 prod.cantidad,
                                 prod.precioUnitario);
        */sacarPrimeroDeLista(listaB,&prod,sizeof(tProducto));
        ponerEnOrdLista(listaF,&prod,sizeof(tProducto),cmpId);
    }

    //ordenarLista(listaF,cmpId);

    return 0;
}
/** FIN de PUNTO 2 **/

/** para el PUNTO 3 **/
/*
void *acumulacionCantProd(void *dato,const void *cant)
{
    ((tProducto*)(dato))->cantidad += ((tProducto*)(cant))->cantidad;
    return dato;
}
*/
void *acumulacionCantProd(void *dato,const void *cant)
{
    ((tProducto*)(dato))->cantidad += ((tProducto*)(cant))->cantidad;
    return dato;
}

int eliminarYacumOrd(tLista *pl,int(*cmp)(const void*,const void*),void*(acum)(void *,const void*))
{
    int cant = 0;
    tNodoL * aux1, * aux2;

    aux1 = *pl;

    while(aux1)
    {
        aux2 = aux1->sig;
        while(aux2)
        {
            if(cmp(aux1->info, aux2->info) == 0)
            {
                acum(aux1->info, aux2->info);
                aux1->sig = aux2->sig;
                free(aux2->info);
                free(aux2);
                aux2->sig = aux1->sig;
                cant++;
            }
            else
                aux2 = aux2->sig;
        }
        aux1 = aux1->sig;
    }

    return cant;
}

int elimNult (tLista * pl, unsigned cant)
{
    tNodoL *aux,**iniElim = &(*pl);
    int i = 0;

    while(*pl && i<cant)
    {
        pl = &(*pl)->sig;
        ++i;
    }
    while(*pl)
    {
        pl = &(*pl)->sig;
        iniElim = &(*iniElim)->sig;
    }

    while(*iniElim)
    {
        aux = *iniElim;
        free(aux->info);
        free(aux);
        *iniElim = (*iniElim)->sig;
    }

    return i;
}


/*
int eliminarYacumOrd(tLista *pl,int(*cmp)(const void*,const void*),void*(acum)(void *,const void*))
{
    tNodoL * actual;
    int cantAct = 0;

    if(!*pl)
        return 0;

    while((*pl)->sig)
    {
        actual = (*pl)->sig;
        while(actual && cmpId(actual->info,(*pl)->info)==0 )
        {
            acumulacionCantProd((*pl)->info,actual->info);
            (*pl)->sig = actual->sig;
            ++cantAct;
            free(actual->info);
            free(actual);
            actual = (*pl)->sig;
        }
        if((*pl)->sig)
            pl = &(*pl)->sig;
    }
    return cantAct;
}
*/

int punto_tres_MIO(FILE *fpPantalla,
                   tLista *listaF,
                   const char *nombreArchMaestroCons)
{
    tProducto prod;
    FILE *fpmc;
    int cantElim;

    if(listaVacia(listaF))
        return 0;

    fpmc = fopen(nombreArchMaestroCons,"wb");

    if(!fpmc)
    {
        return -5;
    }

    cantElim = eliminarYacumOrd(listaF,cmpId,acumulacionCantProd);
    cantElim = elimNult(listaF,5);

    fprintf(fpPantalla,"\nLista F sin duplicados:\n\n");
    fprintf(fpPantalla,"ID Prod     DESCRIPCION      FECHA PRECIO CANTIDAD PRECIO UNIT.\n");
    fprintf(fpPantalla,"------- -------------------- ------------ -------- ------------\n");
    while(!listaVacia(listaF))
    {
        sacarPrimeroDeLista(listaF,&prod,sizeof(tProducto));
        fprintf(fpPantalla,"%07u %-*.*s  %02d/%02d/%04d       %03d     %8.2f\n",
                prod.idProducto,
                (int)sizeof(prod.descripcion)-1,
                (int)sizeof(prod.descripcion)-1,
                prod.descripcion,
                prod.fechaPrecio.dia,
                prod.fechaPrecio.mes,
                prod.fechaPrecio.anio,
                prod.cantidad,
                prod.precioUnitario
               );
        fwrite(&prod,sizeof(tProducto),1,fpmc);
    }

    fclose(fpmc);
    return cantElim;
}
/** FIN de PUNTO 3 **/

/** para el PUNTO 4 **/
int punto_cuatro_MIO(FILE *fpPantalla,
                     const char *nombreArchivoMaestro,
                     const char *nombreArchivoNovedades)
{

    FILE * fm,*fn;
    tProducto prod;
    tNovedad nov;

    int cantAct = 0;
    fm = fopen(nombreArchivoMaestro,"r+b");

    if(!fm)
    {
        return -7;
    }

    fn = fopen(nombreArchivoNovedades,"rb");

    if(!fn)
    {
        fclose(fm);
        return -8;
    }

    long posOrigArcMaes = ftell(fm);
    long posOrigArcNov = ftell(fn);

    rewind(fm);
    rewind(fn);

    fread(&prod,sizeof(tProducto),1,fm);
    fread(&nov,sizeof(tNovedad),1,fn);

    while(!feof(fm))
    {
        while(!feof(fn))
        {
            if(prod.idProducto == nov.idProducto)
            {
                if(A_MAYUS(nov.tipoMovimiento) == 'I')
                {
                    prod.cantidad+=nov.cantidad;
                    fseek(fm,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    fwrite(&prod,sizeof(tProducto),1,fm);
                    fseek(fm,0L,SEEK_CUR);
                    ++cantAct;
                    fread(&nov,sizeof(tNovedad),1,fn);

                }
                else if(A_MAYUS(nov.tipoMovimiento) == 'E')
                {
                    prod.cantidad-=nov.cantidad;
                    fseek(fm,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    fwrite(&prod,sizeof(tProducto),1,fm);
                    fseek(fm,0L,SEEK_CUR);
                    ++cantAct;
                    fread(&nov,sizeof(tNovedad),1,fn);
                }
            }
            else
            {
                fread(&nov,sizeof(tNovedad),1,fn);
            }

        }

        rewind(fn);
        fread(&prod,sizeof(tProducto),1,fm);
        fread(&nov,sizeof(tNovedad),1,fn);

    }

    fseek(fm,posOrigArcMaes,SEEK_SET);
    fseek(fn,posOrigArcNov,SEEK_SET);

    fclose(fm);
    fclose(fn);
    return cantAct;
}
/** FIN de PUNTO 4 **/

/** para el PUNTO 5 **/
int punto_cinco_MIO(FILE *fpPantalla, int mat[][TAM_MAT])
{
    int i,j;

    for(i = 0; i<TAM_MAT; ++i)
    {
        for(j=0; j<TAM_MAT; ++j)
        {
            fprintf(fpPantalla,"%d ",mat[i][j]);
            if( (mat[i][j] != 0 && i!=j) && mat[i][j] !=1 && i==j )
            {
                return 0;
            }
        }
        fprintf(fpPantalla,"\n");
    }

    return TODO_BIEN;
}
/** FIN de PUNTO 5 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

