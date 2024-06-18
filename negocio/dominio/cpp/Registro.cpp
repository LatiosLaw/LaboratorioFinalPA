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

string Registro::getAvance(){
    return this->avance;
}

void Registro::obtenerDataCursoSiPendiente(){

}

void Registro::buscarEjerciciosPendientes(){

}

void Registro::IngresarSolucionEjercicio(){

}

void Registro::VerificarRespuesta(){

}

void Registro::obtenerEstadisticasE(){
    
}