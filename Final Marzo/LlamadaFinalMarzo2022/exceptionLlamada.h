#ifndef EXCEPTIONLLAMADA_H_INCLUDED
#define EXCEPTIONLLAMADA_H_INCLUDED

#include <exception>
using namespace std;

class exceptionLlamada:public exception
{
public:

    virtual const char *what() const throw();

};

#endif // EXCEPTIONLLAMADA_H_INCLUDED
