#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"
#include "../../dto/DT_EstadisticasEstudiante.h"
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
	Estudiante(string nick, string nom, string pass, string desc, Fecha fecha, string pai);
	Estudiante(string nick, string nom, string pass, string desc, string pai);
	Estudiante(string nick, string pass, string nom, string desc);
	virtual string getNickname();
	virtual string getNombreProfesor();
	string getPais();
	Fecha getFechaNacimiento();
	void setPais(string pai);
	void setFechaNacimiento(Fecha fecha);
	virtual void listarInfoUsuario();

	void agregarInscripcion(Registro* registro);

	set<Curso*> buscarCursosAprobados();

	Registro* buscarRegistroACurso(string nom_cur);
	
	// Metodos de los casos de Martin, faltan retornos y parametros

	set<Curso*> buscarCursosPendientes();
	set<Ejercicio*> buscarCursoYEjercicios(Registro* registro);
	void obtenerDataType();
	set<DT_EstadisticasEstudiante*> estadisticasEstudiante();

	///////////////////////////////////////////////////////////////
};

#endif
