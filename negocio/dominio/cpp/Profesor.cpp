#include "../h/Profesor.h"
#include <iostream>
using namespace std;

Profesor::Profesor(string nick, string pass, string nom, string desc, string inst, set<Idioma*>ListaIdiomas) : Usuario(nick, nom, pass, desc) {
	instituto = inst;
	ListaIdiomas = set<Idioma*>();
}

Profesor::Profesor(string nick, string pass, string nom, string desc, string inst) : Usuario(nick, nom, pass, desc) {
	instituto = inst;
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

void Profesor::listarInformacion()
{
	Usuario::listarInformacion();
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

void Profesor::estadisticasProfesor(){

}