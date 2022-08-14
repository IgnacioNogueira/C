#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(const string &,int);
    virtual ~Persona();
    const string& getNombre() const;
    int getEdad() const;






};

#endif // PERSONA_H_INCLUDED
