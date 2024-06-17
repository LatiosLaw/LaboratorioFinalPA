#include "RealizarEjercicio.h"

//Falta pasar las operaciones al controlador principal, haré eso según tenga idea de los retornos y demás.

RealizarEjercicio::RealizarEjercicio()
{
    this->controlador = Controller::getInstance();
}

RealizarEjercicio::~RealizarEjercicio()
{
    // No eliminar el controlador, ya que es un singleton
}

void RealizarEjercicio::listarCursosPendientesDeAlumno(){

}

void RealizarEjercicio::listarEjerciciosPendientesDeCurso(){

}

void RealizarEjercicio::IngresarSolucion(){
    
}
