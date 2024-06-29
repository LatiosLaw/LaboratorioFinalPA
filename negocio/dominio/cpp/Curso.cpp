#include "../h/Curso.h"
#include "../h/Profesor.h" //esto soluciona algunos problemas del forward declaration
#include "../h/Registro.h"
#include "../h/Estudiante.h"
#include <iostream>
#include <string>

using namespace std;

Curso::Curso()
{
}

Curso::~Curso()
{
}

Curso::Curso(string nombreCurso, string descripcion, bool habilitado, dificultad df)
{
	this->nombreCurso = nombreCurso;
	this->descripcion = descripcion;
	this->habilitado = habilitado;
	this->dificultadCurso = df;
	this->profe = nullptr;
}

Curso::Curso(string nombreCurso, string descripcion, dificultad df, Profesor* prof, Idioma* i, bool habilitado)
{	
	this->nombreCurso = nombreCurso;
	this->descripcion = descripcion;
	this->habilitado = habilitado;
	this->dificultadCurso = df;
	this->profe = prof;
	this->ListaIdiomas.insert(i);
}

string Curso::getNombreCurso()
{
	return this->nombreCurso;
}

string Curso::getDescripcion()
{
	return this->descripcion;
}

bool Curso::getHabilitado()
{
	return this->habilitado;
}

dificultad Curso::getDificultad()
{
	return this->dificultadCurso;
}

void Curso::setNombreCurso(string nom)
{
	this->nombreCurso = nom;
}

void Curso::setDescripcion(string desc)
{
	this->descripcion = desc;
}

void Curso::setHabilitado(bool v)
{
	this->habilitado = v;
}

void Curso::setDificultad(dificultad df)
{
	this->dificultadCurso = df;
}

string Curso::enumToString(int n)
{
	if (n == 0)
		return "principiante";
	else if (n == 1)
		return "medio";
	else if (n == 2)
		return "avanzado";
	else
		return "Dificultad invalida";
}

void Curso::linkearProfesor(Profesor *p)
{
	this->profe = p;
}

void Curso::agregarIdioma(Idioma *i)
{
	ListaIdiomas.insert(i);
}

void Curso::listarIdiomasDelCurso()
{
	cout << "Idiomas del curso: ";
	for (Idioma *idioma : ListaIdiomas)
	{
		cout << idioma->getNombreIdioma() << ", ";
	}
	cout << endl;
}

void Curso::listarProfesorDelCurso()
{
	if (this->profe != nullptr)
	{
		cout << "Profesor del curso: " << this->profe->getNombreProfesor() << endl;
	}
	else
	{
		cout << "No se ha asignado un profesor a este curso." << endl;
	}
}

void Curso::mostrarInfo()
{
	cout << "Nombre: " << this->nombreCurso << endl;
	cout << "Descripcion: " << this->descripcion << endl;
	cout << "Dificultad: " << enumToString(this->dificultadCurso) << endl;
	listarIdiomasDelCurso();

	if(this->profe == nullptr){
		cout << "Profesor: -----" << endl;
	}else{
		cout << "Profesor: " << this->profe->getNombre() << endl;
	}
	
	if(this->habilitado == true){
		cout << "Habilitado: si" << endl;
	}else{
		cout << "Habilitado: no" << endl;
	}

	if(this->ListaLecciones.empty()){
		cout << "Lecciones: -----" << endl;
	}else{
		cout << "Lecciones: " << endl;
		for(auto leccion : ListaLecciones)
		{
			cout << "Tema: "<< leccion->getTema() << ". " << "Objetivo: " << leccion->getObjetivo() << "." << endl;
			leccion->mostrarInfoEjercicio();
		}
	}
}

void Curso::seleccionarCursoPrevio(Curso* curso)
{
	this->ListaCursosPrevios.insert(curso);
}

void Curso::listarCursosPrevios()
{
	for (auto curso : ListaCursosPrevios)
	{
		cout << curso->getNombreCurso() << endl;
	}
}

void Curso::inscribirse(Estudiante* estudiante)
{
	Registro *r = new Registro(this, estudiante);
	cout << "Registro creado." << endl;
	estudiante->agregarInscripcion(r);
	ListaRegistros.insert(r);
	cout << "Registro agregado a la lista del curso." << endl;
}

Leccion* Curso::agregarLeccion(int numero, string tema, string objetivo){
	Leccion* leccion = new Leccion(numero, tema, objetivo);
	cout<<"Leccion Creada Exitosamente "<<endl;
	ListaLecciones.insert(leccion);
	cout<<"Leccion Agregada a la lista"<<endl;
	
	return leccion;
}

bool Curso::Pendiente(set<Ejercicio *> aprobados)
{
	for (Leccion* leccion : ListaLecciones)
	{
		if (leccion->Pendiente(aprobados))
		{
			return true;
			break;
		}
	}
	return false;
}

bool Curso::compararNombre(string nom_cur){
if(this->getNombreCurso()==nom_cur){
	return true;
}else{
	return false;
}
}

void Curso::verificarUltimaLeccion()
{
}

Curso *Curso::obtenerDataType()
{ // Temporal sabiendo que voy a tener que agregar un DATATYPE, por ahora se retorna a si misma (Osea Curso literal)
	return this;
}

set<Ejercicio*> Curso::buscarEjerciciosLeccionPendiente(set<Ejercicio*>aprobados)
{
	set<Ejercicio*>ejerciciosPendientes;
	for (Leccion* leccion : ListaLecciones)
	{
		if (leccion->Pendiente(aprobados))
		{
			ejerciciosPendientes = leccion->buscarEjerciciosPendientes(aprobados);
			return ejerciciosPendientes;
			break;
		}
	}
	return ejerciciosPendientes;
}

void Curso::obtenerEstadisticasP()
{
}

void Curso::estadisticasCurso()
{
}

bool Curso::tieneLecciones()
{
	if (this->ListaLecciones.empty())
	{
		cout << "El curso no tiene lecciones. " << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool Curso::todasLasLeccionesTienenEjercicios()
{
	if (this->ListaLecciones.empty())
	{
		cout << "El curso no tiene lecciones. " << endl;
		return false;
	}
	else
	{
		// si tiene almenos una leccion recorro todas las lecciones preguntando si tienen ejercicios.
		for (auto l : ListaLecciones)
		{
			if (l->obtenerEjercicios().empty())
			{
				// Si almenos una leccion no tiene ejercicio return false
				return false;
			}
		}
		// toda leccion tiene ejerecicios
		return true;
	}
}

// habilitar el curso
void Curso::Habilitate()
{
	this->setHabilitado(true);
}

int Curso :: calcularNumLeccion(){
	int tokenCount = 1;
	for (Leccion *leccion : ListaLecciones)
	{
		tokenCount ++;
	}
	return tokenCount;
}

Leccion* Curso :: crearLeccion(string tema, string objetivo){
	
	int numLecc = calcularNumLeccion();
	
	Leccion *nuevaLeccion = new Leccion(numLecc, tema, objetivo);
	
	ListaLecciones.insert(nuevaLeccion);
	
	/*
	for (Leccion *leccion : this->ListaLecciones){
		
		int token = leccion->getNumero();
		//string tokenTema = 
		cout << "Numero de Leccion:" << std::to_string(token) <<endl;
		cout << "Tema: " << leccion->getTema()<<endl;
		cout << "Objetivo: " << leccion->getObjetivo() <<endl;
		cout << "------------------------------------------" <<endl;
	
	}
	*/
	return nuevaLeccion;
}

set<Leccion*> Curso::obtenerLecciones(){

	return this->ListaLecciones;
}

Leccion* Curso::buscarLeccion(int n){
set<Leccion*> l = this->ListaLecciones;
for (auto &&i : l)
{
	if (i->getNumero() == n){
		return i;
	}
}

	return nullptr;
}

set<Ejercicio*> Curso::devolverTodosLosEjercicios(){
set<Ejercicio*> todosLosEjercicios;
for (Leccion *leccion : ListaLecciones)
	{
		set<Ejercicio*> EjerciciosDeLeccion;
		EjerciciosDeLeccion = leccion->retornarEjercicios();
		for(Ejercicio* ejercicio : EjerciciosDeLeccion){
			todosLosEjercicios.insert(ejercicio);
		}
	}
	return todosLosEjercicios;
}

