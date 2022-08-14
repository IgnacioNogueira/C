#ifndef NODOD_H
#define NODOD_H

#include <stddef.h>


typedef struct SNodoD
{
	void* elem;
	size_t tamElem;
	struct SNodoD* ant;
	struct SNodoD* sig;
}
NodoD;


#endif // NODOD_H
