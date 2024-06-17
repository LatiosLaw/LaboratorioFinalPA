#include "ConsultarEstadistica.h"

//Falta pasar las operaciones al controlador principal, haré eso según tenga idea de los retornos y demás.

ConsultarEstadistica::ConsultarEstadistica()
{
    this->controlador = Controller::getInstance();
}

ConsultarEstadistica::~ConsultarEstadistica()
{
    // No eliminar el controlador, ya que es un singleton
}

void ConsultarEstadistica::listarDataEstudiantes(){

}
	
void ConsultarEstadistica::listarDataCursos(){

}

void ConsultarEstadistica::listarDataProfesores(){

}

void ConsultarEstadistica::ElegirEstudiante(){

}

void ConsultarEstadistica::ElegirCurso(){

}

void ConsultarEstadistica::ElegirProfesor(){
    
}