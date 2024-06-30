#include "../h/Registro.h"
#include <ctime>

Registro::Registro()
{

}

Registro::Registro(Curso* curso, Estudiante* estudiante)
{
    ListaEjercicios = set<Ejercicio *>();
    ListaEjerciciosAprobados = set<Ejercicio *>();

    // Obtener la fecha actual
    time_t now = time(0);
    tm *localTime = localtime(&now);

    // Crear un objeto Fecha con la fecha actual
    Fecha fechaR(localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);

    this->curso = curso;
    this->estudiante = estudiante;
    this->fechaInscripcion = fechaR;
    this->actualizarTodosEjerciciosDelCurso();
    //this->calcularAvance();
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
	//cout << "DESTRUCTOR DE REGISTRO" <<endl;
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
    int cantidad_ejercicios = 0;
    double valor = 0;
    double avance = 0;
    for(Ejercicio* ejercicio : ListaEjercicios){
		cantidad_ejercicios = cantidad_ejercicios+1;
	}
    valor = 100/cantidad_ejercicios;
    for(Ejercicio* ejercicio : ListaEjerciciosAprobados){
		avance = avance+valor;
	}
    this->avance = to_string(avance);
}

Curso *Registro::devolverCursoAprobado()
{
    bool aprobado = this->curso->estasAprobado(this->ListaEjerciciosAprobados);

    if (aprobado)
    {
        return this->curso;
    }
    else
    {
        return nullptr;
    }
}

string Registro::pedirNombreACurso(){
    string retorno;
    retorno = curso->getNombreCurso();
    return retorno;
}
void Registro::chao (){
	delete this;
	
}

