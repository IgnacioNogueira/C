#include "utils.h"

int ordenMatriz(FILE * archivoMatriz)
{
    char linea[100];
    int f,c;
    tMatrizRala m;

    fgets(linea,sizeof(linea),archivoMatriz);
    trozarLongitudVariableParaOrden(&m,linea);
    f = m.fila;
    c = m.col;

    if( (f == c) && f > 0 ) //falta una condición
        return f;

    return FAIL;
}

void trozarLongitudVariable(tMatrizRala *m, char *linea)
{
    char * aux = strchr(linea,'\n');
    *aux = '\0';

    aux = strrchr(linea,']');
    sscanf(aux+1,"%d",&m->valor);
    *aux = '\0';

    aux = strrchr(linea,'[');
    sscanf(aux+1,"%d",&m->col);
    *aux = '\0';

    aux = strrchr(linea,'[');
    sscanf(aux+1,"%d",&m->fila);
    *aux = '\0';
}

void trozarLongitudVariableParaOrden(tMatrizRala *m, char *linea)
{
    char * aux = strchr(linea,'\n');
    *aux = '\0';

    aux = strrchr(linea,'[');
    sscanf(aux+1,"%d",&m->col);
    *aux = '\0';

    aux = strrchr(linea,'[');
    sscanf(aux+1,"%d",&m->fila);
    *aux = '\0';
}
