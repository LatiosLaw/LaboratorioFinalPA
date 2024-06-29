#include "../h/Registro.h"

Registro::Registro()
{

}

Registro::Registro(Curso* curso, Estudiante* estudiante)
{
    Fecha fechaR(1,1,1);
    this->curso = curso;
    this->estudiante = estudiante;
    this->fechaInscripcion = fechaR;
    this->actualizarTodosEjerciciosDelCurso();
    this->calcularAvance();
}

Registro::Registro(Fecha fecha, Curso* curso, Estudiante* estudiante)
{
    this->curso = curso;
    this->estudiante = estudiante;
    this->fechaInscripcion = fecha;
    this->actualizarTodosEjerciciosDelCurso();
    this->calcularAvance();
}

Registro::~Registro()
{

}

string Registro::getAvance(){
    return this->avance;
}

Curso *Registro::obtenerDataCursoSiPendiente()
{
    if (this->curso->Pendiente(this->ListaEjerciciosAprobados))
    {
        return this->curso->obtenerDataType();
    }
    else
    {
        return nullptr;
    }
}

bool Registro::verificarCurso(string nom_cur){
    if(this->curso->compararNombre(nom_cur)){
        return true;
    }else{
        return false;
    }
}

set<Ejercicio *> Registro::buscarEjerciciosPendientes()
{
    set<Ejercicio *> ejerciciosPendientes = this->curso->buscarEjerciciosLeccionPendiente(ListaEjerciciosAprobados);
    return ejerciciosPendientes;
}

void Registro::VerificarRespuesta(){

}

void Registro::obtenerEstadisticasE(){
    
}

void Registro::aprobar(Ejercicio* ejercicio){
this->ListaEjerciciosAprobados.insert(ejercicio);
this->calcularAvance();
}

void Registro::actualizarTodosEjerciciosDelCurso(){
    set<Ejercicio *> ejerciciosDelCurso = curso->devolverTodosLosEjercicios();
    this->ListaEjercicios = ejerciciosDelCurso;
}

void Registro::calcularAvance(){
    int cantidad_ejercicios=0;
    double valor;
    double avance=0;
    for(Ejercicio* ejercicio : ListaEjercicios){
		cantidad_ejercicios = cantidad_ejercicios+1;
	}
    valor = 100/cantidad_ejercicios;
    for(Ejercicio* ejercicio : ListaEjerciciosAprobados){
		avance = avance+valor;
	}
    this->avance = to_string(avance);
}