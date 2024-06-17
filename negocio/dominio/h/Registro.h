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
	Curso* curso;
	Estudiante* estudiante;
	
public:
	Registro();
	Registro(Fecha fechaInscripcion, string avance);
	
	virtual ~Registro();

	// Metodos de los casos de Martin, faltan retornos y parametros

	void obtenerDataCursoSiPendiente();
	void buscarEjerciciosPendientes();
	void IngresarSolucionEjercicio();
	void VerificarRespuesta();
	void obtenerEstadisticasE();
	string getAvance(); // Esto es un getter, por lo que no es realmente solo mio XD

	///////////////////////////////////////////////////////////////
};
#endif
