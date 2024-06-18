#include "../h/Registro.h"

Registro::Registro()
{

}

Registro::Registro(Fecha fechaInscripcion, string avance)//falta agregarle parametros
{
    this->fechaInscripcion = fechaInscripcion;
    this->avance = avance;
}

Registro::Registro(Curso* curso, Estudiante* estudiante)
{
    this->curso = curso;
    this->estudiante = estudiante;
}
	
Registro::~Registro()
{

}

string Registro::getAvance(){
    return this->avance;
}

Curso* Registro::obtenerDataCursoSiPendiente(){
if(this->curso->Pendiente(this->ListaEjerciciosAprobados)){
    return this->curso->obtenerDataType();
}else{
    return nullptr;
}
}

void Registro::buscarEjerciciosPendientes(){

}

void Registro::IngresarSolucionEjercicio(){

}

void Registro::VerificarRespuesta(){

}

void Registro::obtenerEstadisticasE(){
    
}