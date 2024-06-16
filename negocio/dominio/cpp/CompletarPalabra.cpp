#include "../h/CompletarPalabra.h"

CompletarPalabra::CompletarPalabra()
{

}

CompletarPalabra::CompletarPalabra(string nomE, string desc, string fraseACompletar, string fraseCorrecta) : Ejercicio(nomE,  desc)
{
    this->fraseACompletar = fraseACompletar;
    this->fraseCorrecta = fraseCorrecta;
}
	
CompletarPalabra::~CompletarPalabra(){

}