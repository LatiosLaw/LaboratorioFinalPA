#ifndef PROFESOR_H
#define PROFESOR_H
#include "Usuario.h"
#include "Idioma.h"
#include "Curso.h"
#include <string>
#include <set>
#include <list>

class Curso;

using namespace std;

class Profesor : public Usuario {
private:
	string instituto;
	set<Idioma*>ListaIdiomas;
	set<Curso*>ListaCursos;
	
public:
	Profesor(string nick, string pass, string nom, string desc, string inst, set<Idioma*>ListaIdiomas);
	Profesor(string nick, string pass, string nom, string desc, string inst);
	string getInstituto();
	virtual string getNickname();
	virtual string getNombreProfesor();
	void setInstituto(string inst);
	Profesor* seleccionarProfesor();
	void agregarCurso(Curso* curso);
	void asociarIdioma(Idioma* idioma);
	void listarMisIdiomas();

};


#endif
