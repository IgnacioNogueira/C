#ifndef OPERACIONINVALIDAEXCEPTION_H_INCLUDED
#define OPERACIONINVALIDAEXCEPTION_H_INCLUDED
#include <exception>

using namespace std;

class OperacionInvalidaException : public exception
{
public:
    const char *what() const throw();
};

#endif // OPERACIONINVALIDAEXCEPTION_H_INCLUDED
