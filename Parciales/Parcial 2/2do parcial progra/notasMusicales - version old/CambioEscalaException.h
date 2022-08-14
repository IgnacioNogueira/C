#ifndef CAMBIOESCALAEXCEPTION_H_INCLUDED
#define CAMBIOESCALAEXCEPTION_H_INCLUDED

#include <exception>

using namespace std;

// fuente: https://cplusplus.com/doc/tutorial/exceptions/

class CambioEscalaException : public exception
{
    public:
    virtual const char * what() const throw();

};

#endif // CAMBIOESCALAEXCEPTION_H_INCLUDED
