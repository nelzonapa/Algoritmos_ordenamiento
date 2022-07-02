#include "CUADRADO.h"
#include "iostream"
using namespace std;
CUADRADO::CUADRADO(string _color, string _nombre_figura, float _menor, float _mayor):RECTANGULO(_color, _nombre_figura, _menor, _mayor){}
CUADRADO::~CUADRADO(){}

void CUADRADO::imprimir(){
    RECTANGULO::imprimir();
    if (lado_menor==lado_mayor)//vemos si se obtuvo un cuadrado o un rectangulo
    {
        cout<<"\tSu figura es un CUADRADO"<<endl;
    }
    else
    {
        cout<<"\tSu figura es un RECTANGULO"<<endl;

    }
    
}