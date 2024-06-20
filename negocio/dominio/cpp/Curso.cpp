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
		return "facil";
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
		cout << idioma->getNombreIdioma();
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
	
	
	for (Leccion *leccion : this->ListaLecciones){
		
		int token = leccion->getNumero();
		//string tokenTema = 
		cout << "Numero de Leccion:" << std::to_string(token) <<endl;
		cout << "Tema: " << leccion->getTema()<<endl;
		cout << "Objetivo: " << leccion->getObjetivo() <<endl;
		cout << "------------------------------------------" <<endl;
		
	}
	
	return nuevaLeccion;
}
void Curso :: crearEjercicio(string nombreEjer, string desc, int nroLecc){
	
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
