#include "../h/Traduccion.h"

Traduccion::Traduccion()
{

}
	
Traduccion::Traduccion(string nombreE, string desc, string fraseT, string traduccion) : Ejercicio(nombreE,  desc)
{   
    this->fraseATraducir = fraseT;
    this->traduccionCorrecta = traduccion;
}
	
Traduccion::~Traduccion()
{

}