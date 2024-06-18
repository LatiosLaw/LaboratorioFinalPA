#ifndef REGISTRO_H
#define REGISTRO_H
#include "Fecha.h"
#include "Leccion.h"
#include "Ejercicio.h"
#include "Curso.h"
#include "Estudiante.h"

class Registro{
	
private:
	Fecha fechaInscripcion;
	string avance;
	Leccion* ultimaLeccion;
	set<Ejercicio*>ListaEjercicios;
	set<Ejercicio*>ListaEjerciciosAprobados;
	Curso* curso;
	Estudiante* estudiante;
	
public:
	Registro();
	Registro(Fecha fechaInscripcion, string avance);
	Registro(Curso* curso, Estudiante* estudiante);
	
	virtual ~Registro();

	// Metodos de los casos de Martin, faltan retornos y parametros

	Curso* obtenerDataCursoSiPendiente(); // FUNCIONANDO(? Falta reemplazar Curso por el DT con los mismos parametros pero menos.
	void buscarEjerciciosPendientes();
	void IngresarSolucionEjercicio();
	void VerificarRespuesta();
	void obtenerEstadisticasE();
	string getAvance(); // Esto es un getter, por lo que no es realmente solo mio XD

	///////////////////////////////////////////////////////////////
};
#endif
