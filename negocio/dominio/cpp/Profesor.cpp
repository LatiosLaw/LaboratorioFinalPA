#include "../h/Profesor.h"
#include <iostream>
using namespace std;

Profesor::Profesor(string nick, string pass, string nom, string desc, string inst, set<Idioma*>ListaIdiomas) : Usuario(nick, pass, nom, desc) {
	this->instituto = inst;
	this->ListaIdiomas = ListaIdiomas;
}

Profesor::Profesor(string nick, string pass, string nom, string desc, string inst) : Usuario(nick, pass, nom, desc) {
	this->instituto = inst;
}

Profesor::Profesor(string nick, string pass, string nom, string desc) : Usuario(nick, pass, nom, desc) {

}

string Profesor::getInstituto() {
	return this->instituto;
}

void Profesor::setInstituto(string inst) {
	instituto = inst;
}

void Profesor::asociarIdioma(Idioma* idioma) {
	ListaIdiomas.insert(idioma);
	cout << "El idioma " << idioma->getNombreIdioma() << " fue asociado exitosamente al profesor." << endl;
}

void Profesor::listarMisIdiomas() {
	set<Idioma*>::iterator itI;
	for (itI = ListaIdiomas.begin(); itI != ListaIdiomas.end(); ++itI) {
		cout << (*itI)->getNombreIdioma() << endl;
	}
}

string Profesor::getNickname(){
	return this->nickname;
}

string Profesor::getNombreProfesor()
{
	return this->nombre;
}

void Profesor::listarInfoUsuario()
{
	Usuario::listarInfoUsuario();
	cout << "Instituto: " <<this->instituto << endl;

	cout << "Idiomas: ";
	for(auto idioma : ListaIdiomas)
	{
		cout << idioma->getNombreIdioma() << ", ";
	}
	cout << endl;
}


Profesor* Profesor::seleccionarProfesor()
{
	cout << "Profesor seleccionado" << endl;
	return this;
}

void Profesor::agregarCurso(Curso* curso){
	ListaCursos.insert(curso);
}

void Profesor::obtenerDataType(){

}

set<DT_EstadisticasProfesor*> Profesor::estadisticasProfesor(){
set<DT_EstadisticasProfesor*> estadisticas;
string nombre_curso;
string av_promedio;
for (Curso *cursos : ListaCursos)
{
		nombre_curso = cursos->getNombreCurso();
		av_promedio = cursos->obtenerAvancePromedio();
		estadisticas.insert(new DT_EstadisticasProfesor(nombre_curso, av_promedio));
}
return estadisticas;
}

void Profesor::eliminarCursoDeLista(string nombreCurso){
	
	for (Curso *curso : ListaCursos)
	{
		if (curso->getNombreCurso() == nombreCurso)
		{
			ListaCursos.erase(curso);
		}
	}
	
}
