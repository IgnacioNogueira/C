/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "CARTASEGNA"
#define NOMBRE      "Nahuel Nicolas"
#define DOCUMENTO   "41645704"
#define COMISION    "05(1965)"
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
#include <ctype.h>
#include <stdlib.h>
#define ES_BLANCO(c) (((c)>='\t'&&(c)<='\r') || ((c)==' ') || ((c)==','))


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

void trozarCamposLongitudVariable(tProducto *d, char *s);
void Normalizar(tProducto *prod);

/** para el PUNTO 1 **/
void *mi_memmove_MIO(void *str1, const void *str2, size_t n)
{
    char *pDest = (char *)str1;
    const char *pOrig= (const char *)str2;

    if((pDest > pOrig) && (pDest < pOrig + n)) // Copiar de atrás hacia adelante (izquierda a derecha)
    {
        while(n)
        {
            n--;
            *(pDest + n) = *(pOrig+n);
        }
    }

    else
    {
        while(n) // Copiar de adelante hacia atrás (derecha a izquierda)
        {
            n--;
            *pDest = *pOrig;
            pDest++;
            pOrig++;
        }
    }

    return str1;
}

/** FIN de PUNTO 1 **/

/** para el PUNTO 2 **/

void Normalizar2(tProducto *prod)
{
    char *pini = prod->descripcion;
    char *pdes = prod->descripcion;
    char *paux = prod->descripcion;

    while(*pini)
    {
        while((ES_BLANCO (*pini)))
        {
            pini++;
        }
        if(*pini)
        {
            *pdes =toupper(*pini);
            pdes++;
            pini++;
            while(!ES_BLANCO(*pini) && *pini)
            {
                *pdes = tolower(*pini);
                pdes++;
                pini++;
            }
            if (ES_BLANCO (*pini))
            {
                *pdes = ' ';
                pdes++;
                pini++;
            }
        }
    }
    paux = pdes-1;
    if(pdes > prod->descripcion && *paux == ' ')
    {
        pdes--;
    }
    *pdes = '\0';
}


void unicoEspacio(char * nombre)
{
    char * aux = nombre;
    char * aux2;

    while((aux2=strstr(aux,"  ")) != NULL)
        memmove(aux2,aux2+1,strlen(aux2));

}

void eliminarEspacioPrincipioFin(char *nombre)
{
    char *p1=nombre;
    char *p2 = nombre + (strlen(nombre)-1);

    while(ES_BLANCO(*p2))
    {
        --p2;
    }

    *(p2+1) = '\0';

    while(ES_BLANCO(*p1))
    {
        ++p1;
    }

    strcpy(nombre,p1);

}

void CamelCase(char * nombre)
{
    *nombre = aMayusc(*nombre);
    nombre++;

    while(*nombre != ' ')
    {
        *nombre = aMinusc(*nombre);
        nombre++;
    }

    nombre++; //para pasar a la segunda mayus ;p

    *nombre = aMayusc(*nombre);
    nombre++;

    while(*nombre)
    {
        *nombre = aMinusc(*nombre);
        nombre++;
    }
}


void Normalizar(tProducto *prod)
{
    eliminarEspacioPrincipioFin(prod->descripcion);
    unicoEspacio(prod->descripcion);
    CamelCase(prod->descripcion);
}

void trozarCamposLongitudVariable(tProducto *d, char *s)
{
    char *aux = strchr(s,'\n');
    *aux = '\0'; //voy a final de cadena y le pongo el barra cero

    //*Precio unitario*//
    aux = strrchr(s,';');
    sscanf(aux+1,"%f",&d->precioUnitario);
    *aux = '\0';

    //*Cantidad*//
    aux = strrchr(s,';');
    sscanf(aux+1,"%d",&d->cantidad);
    *aux = '\0';

    //*Fecha*//
    aux = strrchr(s,';');
    sscanf(aux+1,"%d/%d/%d",&d->fecUltAct.dia,
           &d->fecUltAct.mes,
           &d->fecUltAct.anio);
    *aux = '\0';

    //*Descrip*//
    aux = strrchr(s,';');
    strcpy(d->descripcion,aux+1);
    *aux = '\0';

    //*Id producto*//
    sscanf(s,"%ld",&d->idProducto);
}

/*
#define NOMBRE_ARCHIVO_1      "maestro1.dat"
#define NOMBRE_ARCHIVO_2      "maestro2.txt"
#define NOMBRE_ARCHIVO_FUSION "maestro_fusion.dat"

*/


int fusionarMaestros_MIO(char *nombreArchivo1,
                         char *nombreArchivo2,
                         char *nombreArchivoF)
{
    FILE *fp1,*fp2,*fpf;
    tProducto prodBin,prodTxt;
    char linea[100];

    fp1 = fopen(nombreArchivo1,"rb");

    if(!fp1)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo1);
        return -1;
    }

    fp2 = fopen(nombreArchivo2,"rt");

    if(!fp2)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo2);
        return -2;
    }|

    fpf = fopen(nombreArchivoF,"w+b");

    if(!fpf)
    {
        printf("\nNo se pudo crear el archivo %s",nombreArchivoF);
        return -3;
    }

    fread(&prodBin,sizeof(tProducto),1,fp1);
    fgets(linea,sizeof(linea),fp2);
    trozarCamposLongitudVariable(&prodTxt,linea);

    while(!feof(fp1) && !feof(fp2))
    {
        if(prodBin.idProducto < prodTxt.idProducto)
        {
            Normalizar(&prodBin);
            fwrite(&prodBin,sizeof(tProducto),1,fpf);
            fread(&prodBin,sizeof(tProducto),1,fp1);
        }
        else
        {
            if(prodBin.idProducto > prodTxt.idProducto)
            {
                Normalizar(&prodTxt);
                fwrite(&prodTxt,sizeof(tProducto),1,fpf);
                fgets(linea,sizeof(linea),fp2);
                trozarCamposLongitudVariable(&prodTxt,linea);

            }
            else //son iguales
            {
                Normalizar(&prodBin);
                fwrite(&prodBin,sizeof(tProducto),1,fpf);
                fread(&prodBin,sizeof(tProducto),1,fp1);

                Normalizar(&prodTxt);
                fwrite(&prodTxt,sizeof(tProducto),1,fpf);
                fgets(linea,sizeof(linea),fp2);
                trozarCamposLongitudVariable(&prodTxt,linea);
            }

        }
    }

    while(!feof(fp1))
    {
        Normalizar(&prodBin);
        fwrite(&prodBin,sizeof(tProducto),1,fpf);
        fread(&prodBin,sizeof(tProducto),1,fp1);

    }

    while(!feof(fp2))
    {
        Normalizar(&prodTxt);
        fwrite(&prodTxt,sizeof(tProducto),1,fpf);
        if(fgets(linea,sizeof(linea),fp2))
        trozarCamposLongitudVariable(&prodTxt,linea);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fpf);

    return 0;
}
/** FIN de PUNTO 2 **/


/** para el PUNTO 3 **/
int cargarMaestroEnListaYeliminarDuplicados_MIO(char *nombreArchivoMaestro,
        tLista *pl,
        FILE *fpPantalla)
{

    FILE *archf;
    tProducto prod;
    tLista lista;

    archf = fopen(nombreArchivoMaestro,"r+b");

    if(!archf)
    {
        printf("\nNo se pudo abrir archivo Maestro - Punto 3");
        return -3;
    }

    crearLista(&lista);

    fread(&prod,sizeof(tProducto),1,archf);

    while(!feof(archf))
    {
        ponerOrdenLista(&lista,&prod,sizeof(tProducto),cmpIDproducto);
        fread(&prod,sizeof(tProducto),1,archf);
        mostrarLista(&lista);
    }

    rewind(archf);

    while(!listaVacia(&lista))
    {
        eliminarDuplicadosLista(&lista,&prod,sizeof(tProducto),cmpIDproducto);
        sacarPrimeroLista(&lista,&prod,sizeof(tProducto));
        fwrite(&prod,sizeof(tProducto),1,archf);
    }

    fclose(archf);

    return 0;
}

void eliminarDuplicadosLista(tLista *pl,const void *pd,unsigned tam,int (*cmp)(const void*, const void*)) //y esto es acumular, no es lo buscado en código de la cátedra
{
    tNodo *aux;
    int rc; //result comp

    if(!*pl)
        exit(printf("\nNO HAY ELEMENTOS EN LA LISTA - PUNTO 3")); // si no hay cosas en la lista, salgo

    while(*pl && (rc=cmpIDproducto(pd,(*pl)->info)) !=0)
    {
        pl = &(*pl)->sig; //apunta basicamente al sig elem para trabajar en él hasta que aparezca el NULL
        aux = *pl; //aux para utilizarlo para pisar la info
        memcpy(&pd,aux->info,MIN(tam,aux->tamInfo));
    }

    free(aux->info);
    free(aux);
}


/** FIN de PUNTO 3 **/


/** para el PUNTO 4 **/
int elimnarUltimosNelementosDeLista_MIO(tLista *pl, unsigned int n)
{
    tNodo *aux, **iniElim = &(*pl);
    int i = 0;

    while()


    return i;
}
/** FIN de PUNTO 4 **/


/** para el PUNTO 5 **/

void mostrarLista(tLista *pl)
{
    while(*pl) //hasta que no llegue al null, no para
    {
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }
}

void mostrar(void *info)
{
    tProducto* merc =(tProducto*)info;
    printf("\n-Id Prod:%ld",merc->idProducto);
    printf("\n\n");

}

int listaVacia(const tLista *pl)
{
    return *pl == NULL;
}

int sacarPrimeroLista(tLista *pl,void *pd,unsigned tam)
{
    tNodo *aux = *pl;

    if(aux == NULL)
        return 0;

    *pl = aux->sig;
    memcpy(pd,aux->info,MIN(tam,aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}



int cmpIDproducto(const void *id1, const void *id2)
{
    int n1 = ((tProducto*)(id1))->idProducto;
    int n2 = ((tProducto*)(id2))->idProducto;

    return n1-n2;
}

int ponerOrdenLista(tLista *pl,const void *pd,unsigned tam,int (*cmp)(const void*, const void*))
{
    tNodo *nue;

    while(*pl && (cmp(pd,(*pl)->info)) >= 0) // LA COMP ENTRE DATO POR PARAM Y LA INFO QUE ESTÁ EN LA LISTA. SI EL DATO PASADO ES MÁS GRANDE QUE LO QUE ESTÁ EN LA LISTA...
        pl = &(*pl)->sig;

    //if(*pl && !rc)
    //    return 0; ///DUPLICADO

    nue = (tNodo*)malloc(sizeof(tNodo));

    if(!nue)
    {
        return 0;  ///LISTA LLENA
    }

    nue->info = (tNodo*)malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0;  ///LISTA LLENA
    }

    nue->tamInfo = tam;
    memcpy(nue->info,pd,tam);
    nue->sig = *pl;

    *pl = nue; //para que apunte al nuevo elemento

    return 1;

}

void ordenarIdProducto(char *nombreArchivoMaestro,tProducto *prod,int (*cmp)(const void*, const void*))
{
    FILE *pMaestro;
    pMaestro = fopen(nombreArchivoMaestro,"r+b");
    tLista lista;

    crearLista(&lista);

    if(!pMaestro)
    {
        exit(printf("\nNO SE PUDO ABRIR EL ARCHIVO MAESTRO PARA ORDEANR"));
    }

    fread(&prod,sizeof(tProducto),1,pMaestro);

    while(!feof(pMaestro))
    {
        ponerOrdenLista(&lista,&prod,sizeof(tProducto),cmpIDproducto);
        fread(&prod,sizeof(tProducto),1,pMaestro);
    }

    rewind(pMaestro);

    while(!listaVacia(&lista))
    {
        sacarPrimeroLista(&lista,&prod,sizeof(tProducto));
        fwrite(&prod,sizeof(tProducto),1,pMaestro);
    }

    fclose(pMaestro);
}

int actualizarMaestroDesdeArchivoDeNovedades_MIO(char *nombreArchivoMaestro,
        char *nombreArchivoNovedades,
        FILE *fpPantalla)
{


}

/** FIN de PUNTO 5 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

