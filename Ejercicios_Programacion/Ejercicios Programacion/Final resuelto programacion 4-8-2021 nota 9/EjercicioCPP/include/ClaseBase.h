#ifndef CLASEBASE_H
#define CLASEBASE_H

class ClaseBase {
protected:
    int valor1;
public:
    /*
    Implemento constructor en .h para facilitar la lectura,
     ya que es solo 1 linea.

    Lo mismo para las implementaciones de los 2 destructores derivados
    */
    ClaseBase(int valor1 = 0) {
        this->valor1 = valor1;
    }
    virtual ~ClaseBase() {
        std::cout<<"Destructor ClaseBase\n";
    };
};

#endif // CLASEBASE_H
