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

#include "stdlib.h"
#include "string.h"

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

/** Para el PUNTO 1 **/

int cmp_ent(const void *v1,const void *v2);

int cmp_ent(const void *v1,const void *v2)
{
    return *((int*)v1)-*((int*)v2);
}

#define TODO_OK_AR 1
#define ERROR_AR 0
#define CLA_DUP_AR -1
int abrirArchivo(FILE ** arch, const char *nomArch, const char *ap);

void crearIndice(void *vi, const void *vc, unsigned pos);

int cargarDesdeDatosOrdenadosRec(tArbol *p, void *dataSet,
                    unsigned (*accion)(void **, void *, unsigned, void *params,void *params2),
                    int li, int ls, void *params,void *params2);

unsigned leerYasignarEstructura(void **d, void *vfp, unsigned pos, void *params,void *params2);
int cargarArchivoBinOrdenadoToArbol(tArbol *p, const char *nomArch,
                                    unsigned tamReg,unsigned tamInd);

int indexarArchivoCuentas_MIO(char *nombreArchivoCuentas, tArbol *p)
{
    cargarArchivoBinOrdenadoToArbol(p, nombreArchivoCuentas, sizeof(tCuenta),sizeof(tIndice));
    return 0;
}

int cargarDesdeDatosOrdenadosRec(tArbol *p, void *dataSet,
                    unsigned (*accion)(void **, void *, unsigned, void *params,void *params2),
                    int li, int ls, void *params,void *params2)
{
    int media = (li + ls) / 2, r;

    if(li > ls)
    {
        return TODO_OK_AR;
    }

    *p = (tNodoArbol*)malloc(sizeof(tNodoArbol));

    if(*p == NULL)
    {
        return ERROR_AR;
    }

    (*p)->tamInfo = accion(&(*p)->info, dataSet, media, params,params2);

    if((*p)->info == NULL)
    {
        free(*p);
        return ERROR_AR;
    }

    (*p)->izq = (*p)->der = NULL;

    r = cargarDesdeDatosOrdenadosRec(&(*p)->izq, dataSet,accion,
                                     li, media-1, params,params2);
    if(r != TODO_OK_AR)
    {
        return r;
    }
    return cargarDesdeDatosOrdenadosRec(&(*p)->der, dataSet,accion,
                                     media+1, ls, params,params2);
}
/*
unsigned leerDesdeArchBin(void **d, void *vfp, unsigned pos, void *params)
{
    FILE *fp = (FILE*)vfp;
    unsigned tam = *((unsigned*)params);

    *d = malloc(tam);
    if(*d == NULL)
    {
        return 0;
    }

    fseek(fp, pos * tam, SEEK_SET);
    return fread(*d, tam, 1, fp);
}
*/
unsigned leerYasignarEstructura(void **d, void *vfp, unsigned pos, void *params,void *params2)
{
    FILE *fp = (FILE*)vfp;
    unsigned tamRegArch = *((unsigned*)params);
    unsigned tamInfoArbol = *((unsigned*)params2);

    void *reg = malloc(tamRegArch);

    if(reg == NULL)
    {
        return 0;
    }
    *d = malloc(tamInfoArbol);
    if(*d == NULL)
    {
        free(reg);
        return 0;
    }

    fseek(fp, pos * tamRegArch, SEEK_SET);
    fread(reg, tamRegArch, 1, fp);

    crearIndice(*d, reg, pos);

    //memcpy(*d, &ind, sizeof(tIndice));
    return tamInfoArbol;
}
// vindice, vclave, posicionArch
void crearIndice(void *vi, const void *vc, unsigned pos)
{
    tIndice* ind = (tIndice*)vi;
    tCuenta* cue = (tCuenta*)vc;

    ind->clave.nro = cue->nro;
    ind->clave.secuencia = cue->secuencia;
    ind->clave.tipo = cue->tipo;
    ind->indiceRegistro = pos;
}

int cargarArchivoBinOrdenadoToArbol(tArbol *p, const char *nomArch,
                                    unsigned tamReg,unsigned tamInd)
{
    int cantReg, r;
    FILE *fp = fopen(nomArch,"rb");

    if(!fp)
        return -1;

    fseek(fp, 0L, SEEK_END);
    cantReg = ftell(fp) / tamReg;

    r = cargarDesdeDatosOrdenadosRec(p, fp, leerYasignarEstructura,
                                     0, cantReg-1, &tamReg,&tamInd);
    fclose(fp);
    return r;
}

/** FIN de PUNTO 1 **/


/** Para el PUNTO 2 **/

int acumularMontosNov(void **info,unsigned *tam1,
                      const void *info2, unsigned tam2);
int insertarEnListDobleAcum(tLista *pl,const void *d,unsigned tam,
                            int (*cmp)(const void *,const void *),
                            int (*acum)(void **,unsigned *,const void *, unsigned));

#define CLA_DUP_EXC 3

int acumularMontosNov(void **info,unsigned *tam1,
                      const void *info2, unsigned tam2)
{
    tNovedad ** v1 = (tNovedad **)info;
    tNovedad * v2 = (tNovedad *)info2;

    if((*v1)->tipo == v2->tipo)
    {
        (*v1)->monto += v2->monto;
        return CLA_DUP;
    }
    else
    {
        return CLA_DUP_EXC;
    }

    return -1;
}

int insertarEnListDobleAcum(tLista *pl,const void *d,unsigned tam,
                            int (*cmp)(const void *,const void *),
                            int (*acum)(void **,unsigned *,const void *, unsigned))
{
    tNodoL * act = *pl,
             *nue,
             *ant,
             *sig;

    int rt;

    if(act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        int aux;

        while(act->sig && cmp(act->info,d) < 0 )
            act = act->sig;

        while(act->ant && cmp(act->info,d) > 0 )
            act = act->ant;

        aux = cmp(act->info,d);

        if(aux == 0)
        {
            *pl = act;

            if( (rt = acum(&act->info,&act->tamInfo,d,tam)) == CLA_DUP_EXC)
            {
                ant = act;
                sig = act->sig;
            }
            else if(rt == 1)
            {
                return CLA_DUP; //clave dup
            }
            else
            {
                return SIN_MEM;
            }
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
            (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
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
    tNovedad nov;
    int cantNov = 0;
    FILE * fpn = fopen(nombreArchivoNovedades,"rb");

    if(!fpn)
        return -1;

    fread(&nov,sizeof(tNovedad),1,fpn);

    while(!feof(fpn))
    {
        if(insertarEnListDobleAcum(p,&nov,sizeof(tNovedad),cmp_ent,acumularMontosNov) == CLA_DUP)
        {
            --cantNov;
        }

        ++cantNov;
        fread(&nov,sizeof(tNovedad),1,fpn);
    }

    fclose(fpn);
    return cantNov;
}

/** FIN de PUNTO 2 **/


/** Para el PUNTO 3 **/

int sacarUltimoListaDoble(tLista *pl,void *d,unsigned cantBytes);

int sacarUltimoListaDoble(tLista *pl,void *d,unsigned cantBytes)
{
    tNodoL * act = *pl;
    tNodoL *aux;

    if(act == NULL)
        return 0;

    while(act->sig)
        act = act->sig;

    memcpy(d,act->info,minimo(act->tamInfo,cantBytes));

    aux = act;
    act = aux->ant;

    free(aux->info);
    free(aux);

    if(act)
        act->sig = NULL;

    *pl = act;
    return TODO_BIEN;
}

int listaVaciaDoble(tLista *pl);

int listaVaciaDoble(tLista *pl)
{
    return *pl == NULL;
}

int colaVaciaDoble(tCola *pc);

int colaVaciaDoble(tCola *pc)
{
    return *pc == NULL;
}

int ponerEnColaCir(tCola * pc,const void *d,unsigned cantBytes);

int ponerEnColaCir(tCola * pc,const void *d,unsigned cantBytes)
{
    tNodoC * nue;

    if ( (nue = (tNodoC *) malloc(sizeof(tNodoC))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL )
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    if(!*pc)
    {
        nue->sig = nue;
        *pc = nue;
    }
    else
    {
        nue->sig = (*pc)->sig; //el nuevo tiene que apuntar al que antes era mi tope
        (*pc)->sig = nue;
        *pc = nue;

    }

    return TODO_BIEN;
}

int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes);

int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes)
{
    tNodoC *aux;

    if(*pc == NULL)
        return 0;

    aux = (*pc)->sig;
    memcpy(d,aux->info,minimo(aux->tamInfo,cantBytes));

    if(aux == *pc)
        *pc = NULL;
    else
        (*pc)->sig = aux->sig;

    free(aux->info);
    free(aux);
    return 1;
}


int cargarNovedadesEnColaDesdeLista_MIO(tLista *pl,
                                        tCola *pc,
                                        FILE *fpPantalla)
{
    int cantElem = 0;
    tNovedad nov;

    while(!listaVaciaDoble(pl))
    {
        sacarUltimoListaDoble(pl,&nov,sizeof(tNovedad));
        ponerEnColaCir(pc,&nov,sizeof(tNovedad));
        ++cantElem;
    }

//    while(sacarEnColaCir(pc,&nov,sizeof(tNovedad)))
//    {
//        printf("%02d %c %02d    %8.2f\n\n",
//               nov.nro,
//               nov.tipo,
//               nov.secuencia,
//               nov.monto);
//    }

    return cantElem;
}

/** FIN de PUNTO 3 **/

/** Para el PUNTO 4 **/

void copiarNovEnInd(const tNovedad *nov, tIndice *ind);

void copiarNovEnInd(const tNovedad *nov, tIndice *ind)
{
    ind->clave.nro = nov->nro;
    ind->clave.secuencia = nov->secuencia;
    ind->clave.tipo = nov->tipo;
}

int compInd(const void *v1, const void *v2);

int compInd(const void *v1, const void *v2)
{
    tIndice* ind1 = (tIndice*)v1;
    tIndice* ind2 = (tIndice*)v2;

    if(ind1->clave.nro == ind2->clave.nro)
    {
        if(ind1->clave.tipo == ind2->clave.tipo)
        {
            if(ind1->clave.secuencia == ind2->clave.secuencia)
            {
                //printf("pasa");
                return 0;
            }
            else if(ind1->clave.secuencia < ind2->clave.secuencia)
            {
                return -1;
            }
            return 1;
        }
        else if(ind1->clave.tipo < ind2->clave.tipo)
        {
            return -1;
        }
        return 1;
    }
    else if(ind1->clave.nro < ind2->clave.nro)
    {
        return -1;
    }
    return 1;
}


unsigned recuperarDeArbol(const tArbol *p, void *bus, unsigned tamBus,
                          int (*comp)(const void *, const void *));

unsigned recuperarDeArbol(const tArbol *p, void *bus, unsigned tamBus,
                          int (*comp)(const void *, const void *))
{
    if(*p == NULL)
        return -1;

    int res = comp(bus, (*p)->info);
    if(res < 0)
    {
        return recuperarDeArbol(&(*p)->izq, bus, tamBus, comp);
    }
    else if(res > 0)
    {
        return recuperarDeArbol(&(*p)->der, bus, tamBus, comp);
    }
    memcpy(bus, (*p)->info, minimo(tamBus, (*p)->tamInfo));
    return TODO_BIEN;
}

//void actCuenta(FILE *archCuentas, unsigned indiceReg, float montoAct);
//
//void actCuenta(FILE *archCuentas, unsigned indiceReg, float montoAct)
//{
//    tCuenta cuenta;
//    fseek(archCuentas, indiceReg * sizeof(tCuenta) , SEEK_SET);
//    fread(&cuenta, sizeof(tCuenta), 1, archCuentas);
//    printf("\nMONTO:%8.2f\n",montoAct);
//
//    //printf("CUENTAA: %f %f\n", cuenta.saldo, nov->monto);
//    cuenta.saldo += montoAct;
//    fseek(archCuentas, -1L * (long)sizeof(tCuenta), SEEK_CUR);
//    fwrite(&cuenta, sizeof(tCuenta), 1, archCuentas);
//    fseek(archCuentas, 0L, SEEK_CUR);
//}

void actualizarCuentaPuntoCuatro(FILE *archCuenta,tCuenta * cue,const tIndice *ind,const tNovedad *nov);

void actualizarCuentaPuntoCuatro(FILE *archCuenta,tCuenta * cue,const tIndice *ind,const tNovedad *nov)
{
    fseek(archCuenta, (ind->indiceRegistro) * sizeof(tCuenta),SEEK_SET);
    fread(cue,sizeof(tCuenta),1,archCuenta);
    cue->saldo+=nov->monto;
    fseek(archCuenta,-1L *(long)(sizeof(tCuenta)),SEEK_CUR);
    fwrite(cue,sizeof(tCuenta),1,archCuenta);
    fseek(archCuenta,0L,SEEK_CUR);
}

int sacarDeColaCircular(tCola *cola, void *d, unsigned cantBytes);

int sacarDeColaCircular(tCola *cola, void *d, unsigned cantBytes)
{
    tNodoC *aux;
    if(*cola == NULL)
    {
        return 0;
    }
    aux = (*cola)->sig;

    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));

    if(aux == *cola)
    {
        *cola = NULL;
    }
    else
    {
        (*cola)->sig = aux->sig;
    }
    free(aux->info);
    free(aux);
    return 1;
}

int actualizarArchivoDeCuentasDesdeColaDeNovedades_MIO(FILE *fpPantalla,
        char *nombreArchivoCuentas,
        tCola *cola,
        tArbol *indice)
{
    int cantAct = 0;
    tNovedad nov;
    tIndice ind;
    tCuenta cue;
    FILE * archCuentas = fopen (nombreArchivoCuentas,"r+b");

    if(!archCuentas)
    {
        return -1;
    }

    while(sacarDeColaCircular(cola, &nov, sizeof(tNovedad)))
    {
        copiarNovEnInd(&nov, &ind);

        if(recuperarDeArbol(indice, &ind, sizeof(tIndice), compInd) == TODO_BIEN)
        {
            actualizarCuentaPuntoCuatro(archCuentas,&cue,&ind,&nov);
            ++cantAct;
        }
        else
        {
            mostrarNovedad(&nov, fpPantalla);
        }
    }
    fclose(archCuentas);
    return cantAct;
}


/** FIN de PUNTO 4 **/

/** Para el PUNTO 5 **/

unsigned guardarEnColaYVaciarArbol(tArbol *p,tCola *col);

int colaVaciaCir(tCola * pc)
{
    return *pc == NULL;
}

unsigned guardarEnColaYVaciarArbol(tArbol *p,tCola *col)
{
    int nodoIzq;
    int nodoDer;

    if(!*p)
        return 0;

    nodoIzq = guardarEnColaYVaciarArbol(&(*p)->izq,col);
    nodoDer = guardarEnColaYVaciarArbol(&(*p)->der,col);

    ponerEnColaCir(col,(*p)->info,sizeof(tIndice));
    free((*p)->info);
    free((*p));
    *p = NULL;

    return nodoIzq + nodoDer + 1;
}

int podarIndiceYEncolarPodados_MIO(FILE *fpPantalla,
                                   tArbol *indice,
                                   tCola *cola,
                                   int alturaPoda)
{
    int izq;
    int der;

    if(!*indice)
        return 0;

    if(alturaPoda == 0)
    {
        return guardarEnColaYVaciarArbol(indice,cola);
    }
    else
    {
        izq = podarIndiceYEncolarPodados_MIO(fpPantalla,&(*indice)->izq,cola,alturaPoda-1);
        der = podarIndiceYEncolarPodados_MIO(fpPantalla,&(*indice)->der,cola,alturaPoda-1);
    }

    return izq + der;
}

/** FIN de PUNTO 5 **/
/** Para el PUNTO 6 **/

void actAltaBaja(FILE *archCuentas, tIndice * ind);

void actAltaBaja(FILE *archCuentas, tIndice * ind)
{
    tCuenta cuenta;
    fseek(archCuentas, ind->indiceRegistro * sizeof(tCuenta), SEEK_SET);
    fread(&cuenta, sizeof(tCuenta), 1, archCuentas);

    cuenta.estado = 'B';
    fseek(archCuentas, -1L *(long)sizeof(tCuenta), SEEK_CUR);
    fwrite(&cuenta, sizeof(tCuenta), 1, archCuentas);
    fseek(archCuentas, 0L, SEEK_CUR);
}


int actualizarEstadosArchivoCuentasDesdeCola_MIO(FILE *fpPantalla,
        char *nombreArchivoCuentas,
        tCola *cola)
{
    int cantBajas= 0;
    tIndice ind;
    FILE *fpc;

    fpc = fopen(nombreArchivoCuentas,"r+b");

    if(!fpc)
    {
        return -1;
    }

//    while(sacarDeColaCircular(cola,&ind,sizeof(tIndice)))
//    {
//        printf("%d %02d %c %02d\n\n",
//                   ind.indiceRegistro,
//                   ind.clave.nro,
//                   ind.clave.tipo,
//                   ind.clave.secuencia);
//
//    }


    while(!colaVaciaCir(cola))
    {
        sacarDeColaCircular(cola,&ind,sizeof(tIndice));
        actAltaBaja(fpc,&ind);
        ++cantBajas;
    }

    fclose(fpc);

    return cantBajas;
}


/** FIN de PUNTO 6 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

