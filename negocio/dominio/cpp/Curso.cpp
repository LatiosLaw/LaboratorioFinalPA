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
	//cout << "DESTRUCTOR DE CURSO" <<endl;
}

Curso::Curso(string nombreCurso, string descripcion, bool habilitado, int df)
{
	this->nombreCurso = nombreCurso;
	this->descripcion = descripcion;
	this->habilitado = habilitado;
	this->dificultadCurso = convertirDificultad(df);
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

dificultad Curso::convertirDificultad(int n)
{
	if (n == 0)
		return dificultad::principiante;
	else if (n == 1)
		return dificultad::media;
	else if (n == 2)
		return dificultad::avanzado;
	else
		return dificultad::principiante;
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

string Curso::nombreDificultad()
{
	if (dificultadCurso == dificultad::principiante)
	{
		return "Principiante";
	}
	else if (dificultadCurso == dificultad::media)
	{
		return "Medio";
	}
	else
	{
		return "Avanzado";
	}
}

void Curso::mostrarInfo()
{
	cout << "Nombre: " << this->nombreCurso << endl;
	cout << "Descripcion: " << this->descripcion << endl;
	cout << "Dificultad: " << this->nombreDificultad() << endl;
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

DT_EstadisticasCurso* Curso::estadisticasCurso()
{
	DT_EstadisticasCurso* estadisticas_curso;
	string avance_promedio;
	avance_promedio = this->obtenerAvancePromedio();
	estadisticas_curso = new DT_EstadisticasCurso(this->getNombreCurso(), this->getDescripcion(), this->getDificultad(), avance_promedio);
	return estadisticas_curso;
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
	Leccion *nuevaLeccion = nullptr;
	bool token = true;
	for (Leccion *leccion : this->ListaLecciones){
		if (leccion->getTema() == tema){
			token = false;
		}
	}
	
	if(token == true){
		int numLecc = calcularNumLeccion();
		
		nuevaLeccion = new Leccion(numLecc, tema, objetivo);
		ListaLecciones.insert(nuevaLeccion);
	}
	
	
	
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

bool Curso::estasAprobado(set<Ejercicio *> ListaEjerciciosAprobados)
{
	int cantLecciones = 0;
	int cantEjercicios = 0;

	for (auto cantLec : ListaLecciones)
	{
		cantLecciones = cantLecciones + 1;
		for (auto cantEjer : cantLec->obtenerEjercicios())
		{
			cantEjercicios = cantEjercicios + 1;
		}
	}
	
	int misEjercicios = 0;
	
	for (auto lec : ListaLecciones)
	{
		for (auto ejercicio : lec->obtenerEjercicios())
		{
			for (auto ejer : ListaEjerciciosAprobados)
			{
				if (ejercicio->getnombreEjercicio() == ejer->getnombreEjercicio())
				{
					misEjercicios = misEjercicios + 1;
				}
			}
		}
	}
	
	if (cantEjercicios == misEjercicios)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
	

	
void Curso::nukearLecciones(){
	
	for (Leccion *lista : ListaLecciones)
	{
		//cout << "nokear Lecciones" <<endl;
		lista->nukearEejers();
		ListaLecciones.erase(lista);
		lista->chao();
	}
}
void Curso::nukearRegistros(){
	
	for (Registro *lista : ListaRegistros)
	{
		ListaRegistros.erase(lista);
		lista->chao();
	}
	
	
	
	
}
void Curso::chao(){
	delete this;
}

	

bool Curso::cumplePrevias(set<Curso *> cursos)
{
	if (ListaCursosPrevios.empty())
	{
		return true;
	}
	else
	{
		for (auto elCurso : ListaCursosPrevios)
		{
			for (auto cursoPrevio : cursos)
			{
				if (cursos == ListaCursosPrevios)
				{
					return true;
				}
			}
		}
	}
	return false;

}

string Curso::obtenerAvancePromedio()
{
	int cantidad_registros = 0;
	float suma_avances = 0;
	string promedio;
	for (Registro *registro : ListaRegistros)
	{
		float avance_singular = stof(registro->getAvance());
		suma_avances = suma_avances + avance_singular;
		cantidad_registros = cantidad_registros + 1;
	}
	return to_string(suma_avances / cantidad_registros);
}
