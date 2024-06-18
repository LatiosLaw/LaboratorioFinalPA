#ifndef CURSO_H
#define CURSO_H
#include "Ejercicio.h"
#include "Idioma.h"
#include "Estudiante.h"
#include "Leccion.h"
#include <set>

class Registro;
class Profesor;

enum dificultad{
	facil, medio, avanzado
};

class Curso{
	
private:
	string nombreCurso;
	string descripcion;
	bool habilitado;
	dificultad dificultadCurso;
	Profesor* profe;
	set<Idioma*>ListaIdiomas;
	set<Registro*>ListaRegistros;
	set<Curso*>ListaCursosPrevios;
	set<Leccion*>ListaLecciones;
	
public:
	Curso();
	Curso(string nombreCurso, string descripcion, bool habilitado, dificultad df);
	
	string getNombreCurso();
	string getDescripcion();
	bool getHabilitado();
	dificultad getDificultad();
	
	void setNombreCurso(string nom);
	void setDescripcion(string desc);
	void setHabilitado(bool v);
	void setDificultad(dificultad df);
	
	string enumToString(int n);
	void linkearProfesor(Profesor* p);
	void agregarIdioma(Idioma* i);
	void listarIdiomasDelCurso();
	void listarProfesorDelCurso();

	void seleccionarCursoPrevio(Curso* curso);
	void listarCursosPrevios();
	void inscribirse(Estudiante* estudiante);
	virtual ~Curso();

	// Metodos de los casos de Martin, faltan retornos y parametros

	bool Pendiente(set<Ejercicio*> aprobados); // FUNCIONANDO

	void verificarUltimaLeccion();
	Curso* obtenerDataType();
	void buscarEjerciciosLeccionPendiente();
	void obtenerEstadisticasP();
	void estadisticasCurso();

	///////////////////////////////////////////////////////////////
};
#endif
