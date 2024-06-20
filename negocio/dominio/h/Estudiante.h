#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"
#include "Fecha.h"
#include "Curso.h"
#include <string>
#include <set>

using namespace std;

class Registro;

class Estudiante : public Usuario {
private:
	string pais;
	Fecha fechaNacimiento;
	set<Registro*>ListaRegistros;
	
public:
	Estudiante(string nick, string nom, string pass, string desc, string pai, Fecha fecha);
	Estudiante(string nick, string nom, string pass, string desc, string pai);
	virtual string getNickname();
	virtual string getNombreProfesor();
	string getPais();
	Fecha getFechaNacimiento();
	void setPais(string pai);
	void setFechaNacimiento(Fecha fecha);
	virtual void listarInfoUsuario();

	void agregarInscripcion(Registro* registro);

	Registro* buscarRegistroACurso(string nom_cur);
	
	// Metodos de los casos de Martin, faltan retornos y parametros

	set<Curso*> buscarCursosPendientes();
	set<Ejercicio*> buscarCursoYEjercicios(string nom_cur);
	void obtenerDataType();
	void estadisticasEstudiante();

	///////////////////////////////////////////////////////////////
};

#endif
