#include "funciones.h"

int PuntoALista(const char *nombreArchivo,
                tListaD * lista,
                int (*cmp)(const void *,const void*),
                int (*acum)(void **,unsigned *,const void *,unsigned))
{

    FILE *fp;
    tPedidos ped;
    char linea[100];

    fp = fopen(nombreArchivo,"rt");

    if(!fp)
        return ERROR_ARCH;

    while(fgets(linea,sizeof(linea),fp))
    {
        trozarLongitudVariable(&ped,linea);
        insertarYAcumularListaDoble(lista,&ped,sizeof(ped),cmp,acum);
    }

    fclose(fp);
    return TODO_BIEN;
}

int puntoBNodos(tListaD *lista, unsigned cantNodosElim)
{
    int r,c3;
    if( (r = eliminarNUltimosListaDoble(lista,cantNodosElim)) == TODO_BIEN)
    {
        printf("\nLista eliminada:\n");
        c3 = recorrerListaIzqADer(lista,mostrarPedidos);
        printf("\nCantidad de elementos lista eliminada: %d\n",c3);
        return TODO_BIEN;
    }
    else if( r == ERR_EXC)
    {
        printf("\n*****ERROR REVISE LA CANTIDAD DE ELEMENTOS QUE INGRESO*****\n");
    }
    else
    {
        printf("\n*****NO HAY ELEMENTOS QUE SE PUEDAN ELIMINAR DE LA LISTA*****\n");
    }

    return 0;
}

int PuntoCArchivo(const char *nombreArchivoFinal,
                  tListaD *lista)
{

    tPedidos ped;
    FILE *fp = fopen(nombreArchivoFinal,"wb");

    if(!fp)
        return ERROR_ARCH;

    while(sacarPrimeroDeListaDoble(lista,&ped,sizeof(tPedidos)))
    {
        fwrite(&ped,sizeof(tPedidos),1,fp);
    }

    fclose(fp);
    return TODO_BIEN;
}
