#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"
#include "Fecha.h"
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

	void agregarInscripcion(Registro* registro);

	// Metodos de los casos de Martin, faltan retornos y parametros

	void buscarCursosPendientes();
	void buscarCursoYEjercicios();
	void obtenerDataType();
	void estadisticasEstudiante();

	///////////////////////////////////////////////////////////////
};

#endif
