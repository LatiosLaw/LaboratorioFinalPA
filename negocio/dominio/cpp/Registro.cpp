#include "../h/Registro.h"

Registro::Registro()
{

}

Registro::Registro(Fecha fechaInscripcion, string avance)//falta agregarle parametros
{
    this->fechaInscripcion = fechaInscripcion;
    this->avance = avance;
}
	
Registro::~Registro()
{

}