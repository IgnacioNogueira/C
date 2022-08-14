#ifndef EDADEMPLEADOINVALIDAEXCEPTION_H_INCLUDED
#define EDADEMPLEADOINVALIDAEXCEPTION_H_INCLUDED

#include <exception>
using namespace std;

class EdadEmpleadoInvalidaException: public exception
{
    public:
    virtual const char * what() const throw();
};



#endif // EDADEMPLEADOINVALIDAEXCEPTION_H_INCLUDED
