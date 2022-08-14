#include "utils.h"

int cmp_cp(const void *v1,const void *v2)
{
    const tPedidos * ped1 = (tPedidos *)v1;
    const tPedidos *ped2 = (tPedidos *)v2;

    return strcmp(ped1->codProd,ped2->codProd);
}

int cmpSectorYprod(const void *v1,const void *v2)
{
    const tPedidos *ped1 = (tPedidos *)v1;
    const tPedidos *ped2 = (tPedidos *)v2;
    int r;

    if(ped1->codSector == ped2->codSector)
    {
        if( (r = strcmp(ped1->codProd,ped2->codProd)) == 0 )
        {
            if( (r = strcmp(ped1->oficina,ped2->oficina)) == 0)
            {
                return 0;
            }
            else if(r < 0)
            {
                return -1;
            }

            return 1;
        }
        else if (r < 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if(ped1->codSector < ped2->codSector)
    {
        return -1;
    }

    return 1;
}

int cmpCodProdSectorYOficina(const void *v1,const void *v2)
{
    const tPedidos *ped1 = (tPedidos *)v1;
    const tPedidos *ped2 = (tPedidos *)v2;
    int r;

    if( (r = strcmp(ped1->codProd,ped2->codProd)) == 0)
    {
        if(ped1->codSector == ped2->codSector)
        {
            if( (r = strcmp(ped1->oficina,ped2->oficina)) == 0)
            {
                return 0;
            }
            else if(r < 0)
            {
                return -1;
            }

            return 1;
        }
        else if(ped1->codSector < ped2->codSector)
        {
            return -1;
        }

        return 1;
    }
    else if(r < 0)
    {
        return -1;
    }

    return 1;
}

int acumularCantidadPedida(void ** info1,unsigned *tamInfo1,
                           const void *info2,unsigned tamInfo2)
{
    tPedidos ** ped1 = (tPedidos **)info1;
    const tPedidos *ped2 = (tPedidos *)info2;

    (*ped1)->cantPedida+=ped2->cantPedida;
    return TODO_BIEN;
}

int crearLotePrueba(const char *nombreArchivo)
{
    FILE *fp = fopen(nombreArchivo,"wt");
    int i;

    if(!fp)
        return FAIL;

    tPedidos ped[]=
    {
        {1,"ABC121",15,'B',"OFICINA 1"},
        {2,"ABC121",15,'A',"OFICINA 2"},
        {3,"ABC121",30,'A',"OFICINA 2"},
        {4,"ABC122",10,'B',"OFICINA 2"},
        {5,"ABC122",10,'X',"OFICINA 5"},
        {6,"ABC122",10,'D',"OFICINA 5"},
        {7,"ABC123",18,'A',"OFICINA 3"},
        {8,"ABC124",30,'D',"OFICINA 4"},
        {9,"ABC122",22,'B',"OFICINA 2"}
    };

    for(i = 0; i<sizeof(ped)/sizeof(tPedidos); ++i)
    {
        fprintf(fp,"%d|%s|%d|%c|%s\n",
                ped[i].nroPedido,
                ped[i].codProd,
                ped[i].cantPedida,
                ped[i].codSector,
                ped[i].oficina
               );
    }
    fclose(fp);
    return TODO_BIEN;
}

void mostrarPedidos(const void *d)
{
    const tPedidos *p = (tPedidos *)d;

    if(p == NULL)
    {
        printf("\nARCHIVO FINAL:\n");
        return;
    }

    printf("%02d %-*.*s %03d - %c %-*.*s\n",
           p->nroPedido,
           (int)sizeof(p->codProd)-1,
           (int)sizeof(p->codProd)-1,
           p->codProd,
           p->cantPedida,
           p->codSector,
           (int)sizeof(p->oficina)-1,
           (int)sizeof(p->oficina)-1,
           p->oficina
          );
}

int mostrarArchivoFinal(char * nombreArchivoFinal)
{
    tPedidos ped;

    FILE *fp = fopen(nombreArchivoFinal,"rb");

    if(!fp)
        return ERROR_ARCH;

    fread(&ped,sizeof(tPedidos),1,fp);
    mostrarPedidos(NULL);

    while(!feof(fp))
    {
        mostrarPedidos(&ped);
        fread(&ped,sizeof(tPedidos),1,fp);
    }

    fclose(fp);
    return TODO_BIEN;
}


void trozarLongitudVariable(tPedidos *ped,char *s)
{
    char *aux = strchr(s,'\n');
    *aux = '\0';

    aux = strrchr(s,'|');
    strcpy(ped->oficina,aux+1);
    *aux = '\0';

    aux = strrchr(s,'|');
    sscanf(aux+1,"%c",&ped->codSector);
    *aux = '\0';

    aux = strrchr(s,'|');
    sscanf(aux+1,"%d",&ped->cantPedida);
    *aux = '\0';

    aux = strrchr(s,'|');
    strcpy(ped->codProd,aux+1);
    *aux = '\0';

    sscanf(s,"%d",&ped->nroPedido);
}
