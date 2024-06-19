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

void Registro::IngresarSolucionEjercicio(){

}

void Registro::VerificarRespuesta(){

}

void Registro::obtenerEstadisticasE(){
    
}