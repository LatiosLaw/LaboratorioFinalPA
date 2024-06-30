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
	Registro(Curso* curso, Estudiante* estudiante);
	Registro(Fecha fecha, Curso* curso, Estudiante* estudiante);

	Curso* devolverCursoAprobado();
	
	virtual ~Registro();
	void chao();

	// Metodos de los casos de Martin, faltan retornos y parametros

	Curso* obtenerDataCursoSiPendiente(); // FUNCIONANDO(? Falta reemplazar Curso por el DT con los mismos parametros pero menos.
	bool verificarCurso(string nom_cur);
	set<Ejercicio*> buscarEjerciciosPendientes();
	void aprobar(Ejercicio* ejercicio);
	void VerificarRespuesta();
	void obtenerEstadisticasE();
	void actualizarTodosEjerciciosDelCurso();
	void calcularAvance();
	string getAvance(); // Esto es un getter, por lo que no es realmente solo mio XD
	string pedirNombreACurso();

	///////////////////////////////////////////////////////////////
};
#endif
