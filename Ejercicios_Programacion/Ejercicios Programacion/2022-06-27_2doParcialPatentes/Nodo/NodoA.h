#ifndef NODOA_H
#define NODOA_H

#include <stddef.h>


typedef struct SNodoA
{
	void* elem;
	size_t tamElem;
	struct SNodoA* hIzq;
	struct SNodoA* hDer;
}
NodoA;


#endif // NODOA_H
