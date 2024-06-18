#include "../h/Leccion.h"

Leccion::Leccion()
{

}

Leccion::Leccion(int numero, string tema, string objetivo)
{
    this->numero = numero;
    this->tema = tema;
    this->objetivo = objetivo;
}
	
Leccion::~Leccion()
{

}

int Leccion::getNumero(){
    return this->numero;
    //para no agregar esto si que le temias a la pala XD
}

void Leccion::buscarEjerciciosPendientes(){

}