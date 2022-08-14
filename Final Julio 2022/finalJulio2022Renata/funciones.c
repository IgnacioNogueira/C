#include "funciones.h"

int crearLotePrueba(const char *nombreArchivo)
{
    FILE *fp = fopen(nombreArchivo,"wb");

    if(!fp)
        return ERROR_ARCH;

    tPedidos ped[] =
    {
        {"ABC11",'A',60},
        {"ABC12",'B',50},
        {"ABC11",'A',-20},
        {"ABC13",'C',-50},
        {"ABC14",'D',10},
        {"ABC13",'C',60}
    };

    fwrite(ped,sizeof(ped),1,fp);

    fclose(fp);
    return TODO_BIEN;
}

int cargarArchivoALista(const char *nombreArchivo,tLista *lista)
{
    FILE *fp;
    tPedidos ped;
    fp = fopen(nombreArchivo,"rb");

    if(!fp)
        return ERROR_ARCH;

    fread(&ped,sizeof(tPedidos),1,fp);

    while(!feof(fp))
    {
        ponerListaAlFinal(lista,&ped,sizeof(tPedidos));
        fread(&ped,sizeof(tPedidos),1,fp);
    }

    fclose(fp);
    return TODO_BIEN;
}

int listaAArchivo(const char *nombreArchivoFinal,tLista *lista)
{
    tPedidos ped;
    FILE *fp = fopen(nombreArchivoFinal,"wt");

    if(!fp)
        return ERROR_ARCH;

    while(sacarDeListaPrimero(lista,&ped,sizeof(tPedidos)))
    {
        fprintf(fp,"%s|%c|%d\n",
                ped.cod,
                ped.sector,
                ped.cant
               );
    }

    fclose(fp);
    return TODO_BIEN;
}

int registrosPedidos(const char *nombreArchivoLote,
                     const char *nombreArchivoFinal)
{
    if(crearLotePrueba(nombreArchivoLote) != TODO_BIEN)
    {
        printf("\nNo se pudo crear el lote de prueba\n");
        return ERROR_LOTE;
    }
    else
    {
        tLista list;
        crearLista(&list);

        if(cargarArchivoALista(nombreArchivoLote,&list) != TODO_BIEN)
        {
            printf("\nError al cargar el lote de prueba a la lista\n");
            return ERROR_LISTA;
        }

        if(eliminarYAcumDupLista(&list,cmp_codPed,acumularCantidad) != TODO_BIEN)
        {
            printf("\nError al acumular registros\n");
            return SIN_MEM;
        }

        if(listaAArchivo(nombreArchivoFinal,&list) != TODO_BIEN)
        {
            printf("\nError al convertir archivo de salida\n");
            return ERROR_ARCH;
        }

    }

    return TODO_BIEN;
}
