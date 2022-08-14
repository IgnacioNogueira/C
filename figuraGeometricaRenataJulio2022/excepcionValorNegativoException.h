#ifndef EXCEPCIONVALORNEGATIVOEXCEPTION_H_INCLUDED
#define EXCEPCIONVALORNEGATIVOEXCEPTION_H_INCLUDED

#include <exception>

using namespace std;

class excepcionValorNegativoException:public exception
{
    public:
        virtual const char * what() const throw();

};



#endif // EXCEPCIONVALORNEGATIVOEXCEPTION_H_INCLUDED
