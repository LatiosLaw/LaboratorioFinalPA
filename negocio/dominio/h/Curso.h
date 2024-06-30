#ifndef CURSO_H
#define CURSO_H
#include "Ejercicio.h"
#include "../../dto/DT_EstadisticasCurso.h"
#include "Idioma.h"
#include "Leccion.h"
#include <set>

class Estudiante;
class Registro;
class Profesor;

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
	Curso(string nombreCurso, string descripcion, bool habilitado, int df);
	Curso(string nombreCurso, string descripcion, dificultad df, Profesor* prof, Idioma* i, bool habilitado);
	
	string getNombreCurso();
	string getDescripcion();
	bool getHabilitado();
	dificultad getDificultad();
	dificultad convertirDificultad(int n);

	string nombreDificultad();
	
	void setNombreCurso(string nom);
	void setDescripcion(string desc);
	void setHabilitado(bool v);
	void setDificultad(dificultad df);
	
	string enumToString(int n);
	void linkearProfesor(Profesor* p);
	void agregarIdioma(Idioma* i);
	void listarIdiomasDelCurso();
	void listarProfesorDelCurso();
	void mostrarInfo();

	void seleccionarCursoPrevio(Curso* curso);
	void listarCursosPrevios();
	void inscribirse(Estudiante* estudiante);
	Leccion* agregarLeccion(int numero, string tema, string objetivo);

	bool estasAprobado(set<Ejercicio*>ListaEjerciciosAprobados);
	bool cumplePrevias(set<Curso*> cursos);
	virtual ~Curso();

	// Metodos de los casos de Martin, faltan retornos y parametros

	bool Pendiente(set<Ejercicio*> aprobados); // FUNCIONANDO

	void verificarUltimaLeccion();
	bool compararNombre(string nom_cur);
	Curso* obtenerDataType();
	set<Ejercicio*> buscarEjerciciosLeccionPendiente(set<Ejercicio*>aprobados);
	void obtenerEstadisticasP();
	DT_EstadisticasCurso* estadisticasCurso();
	bool tieneLecciones();
	bool todasLasLeccionesTienenEjercicios();
	void Habilitate();
	int calcularNumLeccion();
	Leccion* crearLeccion(string tema, string objetivo);
	set<Leccion*> obtenerLecciones();
	Leccion* buscarLeccion(int n);
	set<Ejercicio*> devolverTodosLosEjercicios();

	string obtenerAvancePromedio();
	void nukearLecciones();
	void nukearRegistros();
	void chao();

	///////////////////////////////////////////////////////////////
};
#endif
