#include "utils.h"

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

    sscanf(linea,"%d",&m->fila);
}

int concatenarPosicion(const tMatrizRala *m)
{
    char s1[2];
    char s2[2];

    sprintf(s1,"%d",m->fila);
    sprintf(s2,"%d",m->col);
    strcat(s1,s2);

    int c = atoi(s1);
    return c;
}

int esMatrizCuadrada(const tMatrizRala *m)
{
    return m->fila == m->col;
}
