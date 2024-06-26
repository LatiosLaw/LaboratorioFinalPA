#ifndef PROFESOR_H
#define PROFESOR_H
#include "Usuario.h"
#include "Idioma.h"
#include "../../dto/DT_EstadisticasProfesor.h"
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
	Profesor(string nick, string pass, string nom, string desc);
	string getInstituto();
	virtual string getNickname();
	virtual string getNombreProfesor();
	virtual void listarInfoUsuario();
	void setInstituto(string inst);
	Profesor* seleccionarProfesor();
	void agregarCurso(Curso* curso);
	void asociarIdioma(Idioma* idioma);
	void listarMisIdiomas();
	void eliminarCursoDeLista(string nombreCurso);

	// Metodos de los casos de Martin, faltan retornos y parametros

	void obtenerDataType();
	set<DT_EstadisticasProfesor*> estadisticasProfesor();

	///////////////////////////////////////////////////////////////
};


#endif
