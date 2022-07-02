#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "FORMA.h"

//CReamos la clase HIJA RECTANGULO de FORMA
class RECTANGULO: public FORMA{
    protected:
        float lado_menor,lado_mayor;
    public:
        RECTANGULO(string,string, float, float);//constructor
        ~RECTANGULO();//destructor
        virtual void imprimir();
        void area();//calcula area
        float get_area();//devuelve el area
        void perimetro();//calcula perimetro

};

#endif