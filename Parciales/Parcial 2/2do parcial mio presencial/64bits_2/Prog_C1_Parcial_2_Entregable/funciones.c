/**//*             en los siguientes macroreemplazos indique:             *//**/
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

#include <string.h>
#include <stdlib.h>

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"


/** Para el PUNTO 1 **/

#define MENOR -1
#define MAYOR 1
#define IGUAL 0
#define ERROR_ARCHIVO -2

int obtenerIndiceRegistro(int ini,int fin);

int obtenerIndiceRegistro(int ini,int fin)
{
    return (ini + fin) / 2;
}

void copiarEstructura(const tCuenta * cue,tIndice *ind,unsigned indReg);

void copiarEstructura(const tCuenta * cue,tIndice *ind,unsigned indReg)
{
    ind->indiceRegistro = indReg;
    ind->clave.nro = cue->nro;
    ind->clave.tipo= cue->tipo;
    ind->clave.secuencia = cue->secuencia;
}

int cmpDeIndice(const void *v1,const void *v2);

int cmpDeIndice(const void *v1,const void *v2)
{
    const tIndice * info1 = (tIndice *)v1;
    const tIndice * info2 = (tIndice *)v2;

    if(info1->clave.nro == info2->clave.nro)
    {
        if(info1->clave.tipo == info2->clave.tipo)
        {
            if(info1->clave.secuencia == info2->clave.secuencia)
            {
                return IGUAL;
            }
            else if(info1->clave.secuencia < info2->clave.secuencia)
            {
                return MENOR;
            }

            return MAYOR;
        }
        else if(info1->clave.tipo < info2->clave.tipo)
        {
            return MENOR;
        }

        return MAYOR;
    }
    else if(info1->clave.nro < info2->clave.nro)
    {
        return MENOR;
    }

    return MAYOR;
}


int insertarEnArbol(tArbol * p,const void *d,unsigned cantBytes,
                    int (*cmp)(const void *,const void *));

int insertarEnArbol(tArbol * p,const void *d,unsigned cantBytes,
                    int (*cmp)(const void *,const void *))
{
    if(*p)
    {
        int r = cmp(d,(*p)->info);

        if(r < 0)
        {
            return insertarEnArbol(&(*p)->izq,d,cantBytes,cmp);
        }
        else if(r > 0)
        {
            return insertarEnArbol(&(*p)->der,d,cantBytes,cmp);
        }
        else
        {
            return CLA_DUP;
        }
    }

    tNodoArbol *nue;

    if( (nue = (tNodoArbol *)malloc(sizeof(tNodoArbol)) ) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL )
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;

    return TODO_BIEN;
}

int abrirArchivo(FILE ** fp,const char *nombreArchivo,char *modoAp);

int abrirArchivo(FILE ** fp,const char *nombreArchivo,char *modoAp)
{
    *fp = fopen(nombreArchivo,modoAp);

    if(*fp == NULL)
    {
        fprintf(stderr,"\nNo se pudo abrir el archivo %s en modo %s",nombreArchivo,modoAp);
        return ERROR_ARCHIVO;
    }

    return TODO_BIEN;
}

void ponerBalanceado(tArbol *p,int ini,int fin,FILE * fp);


void ponerBalanceado(tArbol *p,int ini,int fin,FILE * fp)
{
    tCuenta cue;
    tIndice ind;

    if(ini > fin)
        return;

    int m = obtenerIndiceRegistro(ini,fin);
    fseek(fp,m*sizeof(tCuenta),SEEK_SET);
    fread(&cue,sizeof(tCuenta),1,fp); //para copiarlo después a la estructura
    copiarEstructura(&cue,&ind,m);
    insertarEnArbol(p,&ind,sizeof(tIndice),cmpDeIndice);

    ponerBalanceado(p,ini,m-1,fp);
    ponerBalanceado(p,m+1,fin,fp);
}

int indexarArchivoCuentas_MIO(char *nombreArchivoCuentas, tArbol *p)
{
    FILE *fpc;

    if(abrirArchivo(&fpc,nombreArchivoCuentas,"rb") == ERROR_ARCHIVO)
        return ERROR_ARCHIVO;

    int ini = 0;
    int fin;

    fseek(fpc,0L,SEEK_END); //el 0 es porque no avanza nada
    fin = ftell(fpc)/sizeof(tCuenta); //obtengo el nro 14 (ult reg)
    ponerBalanceado(p,ini,fin-1,fpc); //porque me deja el flujo al final del archivo, hay que retroceder 1

    fclose(fpc);
    return 0;
}
/** FIN de PUNTO 1 **/


/** Para el PUNTO 2 **/
int cmpLista(const void *v1,const void *v2);

int cmpLista(const void *v1,const void *v2)
{
    const tNovedad * nov1 = (tNovedad *)v1;
    const tNovedad * nov2 = (tNovedad *)v2;

    if(nov1->nro == nov2->nro)
    {
        if(nov1->tipo == nov2->tipo)
        {
            return IGUAL;
        }
        else if(nov1->tipo < nov2->tipo)
        {
            return MENOR;
        }

        return MAYOR;

    }
    else if(nov1->nro < nov2->nro)
    {
        return MENOR;
    }

    return MAYOR;
}

int acumularMontoNovedades(void **info1, unsigned *tamInfo1,
                           const void *info2,unsigned tamInfo2);

int acumularMontoNovedades(void **info1, unsigned *tamInfo1,
                           const void *info2,unsigned tamInfo2)
{
    tNovedad ** novA = (tNovedad **)info1;
    const tNovedad * novB = (tNovedad *)info2;

    (*novA)->monto+=novB->monto;

    return TODO_BIEN;
}

int insertarEnListaDobleAcum(tLista *pl,const void *d,unsigned cantBytes,
                             int (*cmp)(const void*,const void*),
                             int (*acum)(void **,unsigned *,const void *,unsigned));

int insertarEnListaDobleAcum(tLista *pl,const void *d,unsigned cantBytes,
                             int (*cmp)(const void*,const void*),
                             int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tNodoL *nue,
           *ant,
           *sig,
           *act = *pl;

    if(act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        int aux;

        while(act->sig && cmp(act->info,d) < 0)
            act = act->sig;

        while(act->ant && cmp(act->info,d) > 0)
            act = act->ant;

        aux = cmp(act->info,d);

        if(aux == 0)
        {
            *pl = act;

            if(acum)
                if(acum(&act->info,&act->tamInfo,d,cantBytes) == SIN_MEM)
                    return SIN_MEM;

            return CLA_DUP;
        }
        else if(aux < 0)
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            ant = act->ant;
            sig = act;
        }
    }

    if( (nue = (tNodoL *)malloc(sizeof(tNodoL))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL )
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->ant = ant;
    nue->sig = sig;

    if(ant)
        ant->sig = nue;

    if(sig)
        sig->ant = nue;

    *pl = nue;

    return TODO_BIEN;
}

int cargarArchivoNovedadesEnLista_MIO(FILE *fpPantalla,
                                      char *nombreArchivoNovedades,
                                      tLista *p)
{
    FILE *fpn;

    if(abrirArchivo(&fpn,nombreArchivoNovedades,"rb") == ERROR_ARCHIVO)
        return ERROR_ARCHIVO;

    int cantNov = 0;
    tNovedad nov;

    fread(&nov,sizeof(tNovedad),1,fpn);

    while(!feof(fpn))
    {
        if(insertarEnListaDobleAcum(p,&nov,sizeof(tNovedad),cmpLista,acumularMontoNovedades) == TODO_BIEN)
            cantNov++;

        fread(&nov,sizeof(tNovedad),1,fpn);
    }

    return cantNov;
}
/** FIN de PUNTO 2 **/


/** Para el PUNTO 3 **/

#define NO_ENC -3
#define ENCONT 7
#define TODO_BIEN_LD 1

int sacarDeListaDoble(tLista *pl,void *d,unsigned cantBytes);

int sacarDeListaDoble(tLista *pl,void *d,unsigned cantBytes)
{
    tNodoL *aux,*act = *pl;

    if(act == NULL)
        return 0;

    while(act->ant)
        act = act->ant;

    aux = act;
    act = aux->sig;
    memcpy(d,aux->info,minimo(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);

    if(act)
    {
        act->ant = NULL;
    }

    *pl = act;
    return TODO_BIEN_LD;
}

void copiarNovedadAParteDeIndice(tIndice *ind,const tNovedad *nov);

void copiarNovedadAParteDeIndice(tIndice *ind,const tNovedad *nov)
{
    ind->clave.nro = nov->nro;
    ind->clave.tipo= nov->tipo;
    ind->clave.secuencia = nov->secuencia;
}

int buscarYrecuperarEnArbol(tArbol *p,void *d,unsigned cantBytes,
                  int (*cmp)(const void*,const void*)); //el void * es porque no está completa la estructura

int buscarYrecuperarEnArbol(tArbol *p,void *d,unsigned cantBytes,
                  int (*cmp)(const void*,const void*))
{
    if(*p == NULL)
        return NO_ENC;

    int r;

    if( (r = cmp(d,(*p)->info)) < 0)
        return buscarYrecuperarEnArbol(&(*p)->izq,d,cantBytes,cmp);
    else if(r > 0)
        return buscarYrecuperarEnArbol(&(*p)->der,d,cantBytes,cmp);

    memcpy(d,(*p)->info,minimo((*p)->tamInfo,cantBytes));
    //memcpy(d,(*p)->info,cantBytes);

    return ENCONT;
}

void actualizarArchivoCuenta(float montoNov,unsigned indiceRegistro,FILE *fp);

void actualizarArchivoCuenta(float montoNov,unsigned indiceRegistro,FILE *fp)
{
    tCuenta cue;

    fseek(fp,indiceRegistro * sizeof(tCuenta),SEEK_SET);
    fread(&cue,sizeof(tCuenta),1,fp);
    cue.saldo+=montoNov;
    fseek(fp,-1L*(long)sizeof(tCuenta),SEEK_CUR);
    fwrite(&cue,sizeof(tCuenta),1,fp);
    fseek(fp,0L,SEEK_CUR);
}

int actualizarArchivoDeCuentasDesdeListaDeNovedades_MIO(FILE *fpPantalla,
        char *nombreArchivoCuentas,
        tLista *lista,
        tArbol *indice)
{

    FILE *fpc;
    int cantAct = 0;
    if(abrirArchivo(&fpc,nombreArchivoCuentas,"r+b") == ERROR_ARCHIVO)
        return ERROR_ARCHIVO;

    tNovedad nov;
    tIndice ind;

    // como no recibí el file *, no hay que hacer esto://long posOrig = ftell(fpc);

    while(sacarDeListaDoble(lista,&nov,sizeof(tNovedad)) == TODO_BIEN_LD)
    {
        copiarNovedadAParteDeIndice(&ind,&nov);

        if(buscarYrecuperarEnArbol(indice,&ind,sizeof(tIndice),cmpDeIndice) == ENCONT)
        {
            actualizarArchivoCuenta(nov.monto,ind.indiceRegistro,fpc);
            ++cantAct;
        }
        else
        {
            fprintf(fpPantalla,"%02d %c %02d   %7.2f\n",
                    nov.nro,
                    nov.tipo,
                    nov.secuencia,
                    nov.monto
                    );
        }

    }

    // mirar arriba-> NO: fseek(fpc,posOrig,SEEK_SET);

    return cantAct;
}
/** FIN de PUNTO 3 **/


/** Para el PUNTO 4 **/

void imprimir(const void *vInfo,unsigned tamInfo,void *params);

void imprimir(const void *vInfo,unsigned tamInfo,void *params)
{
    const tIndice * info = (tIndice *) vInfo;
    FILE * archPar = (FILE *)params;

    fprintf(archPar,"[%3u - %02d %c %02d]\n",
            info->indiceRegistro,
            info->clave.nro,
            info->clave.tipo,
            info->clave.secuencia
           );
}

void recorrerPreOrden(const tArbol *p,
                      void (*mostrar)(const void *,unsigned,void*),
                      void *params);

void recorrerPreOrden(const tArbol *p,
                      void (*mostrar)(const void *,unsigned,void*),
                      void *params)
{
    if(*p == NULL)
        return;

    mostrar((*p)->info,(*p)->tamInfo,params);
    recorrerPreOrden(&(*p)->izq,mostrar,params);
    recorrerPreOrden(&(*p)->der,mostrar,params);
}




void mostrarArbolEnPreorden_MIO(const tArbol *p,
                                FILE *fpPantalla)
{
    recorrerPreOrden(p,imprimir,fpPantalla);
}
/** FIN de PUNTO 4 **/


/** Para el PUNTO 5 **/

int nodosParesCriterio(const void *info);

int nodosParesCriterio(const void *info)
{
    const tIndice * infoIndice = (tIndice *)info;

    if(infoIndice->indiceRegistro %2 == 0)
        return 1;

    return 0;
}

int contarNodosPorCondicion(const tArbol *p,
                            int (*crt)(const void*))
{
    if(*p == NULL)
        return 0;

    return contarNodosIndiceRegistroPar_MIO(&(*p)->izq)
           + contarNodosIndiceRegistroPar_MIO(&(*p)->der)
           + crt((*p)->info);
}

int contarNodosIndiceRegistroPar_MIO(const tArbol *p)
{
    return contarNodosPorCondicion(p,nodosParesCriterio);
}
/** FIN de PUNTO 5 **/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

