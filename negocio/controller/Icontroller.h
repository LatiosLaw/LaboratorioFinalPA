#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <iostream>
#include "../dominio/h/Idioma.h"
#include "../dominio/h/Curso.h"
#include "../dominio/h/Estudiante.h"
#include <list>
#include <set>
using namespace std;

class Icontroller{

public:

	virtual Usuario* buscarUsuario(string nick) = 0;
	virtual Profesor* buscarProfesor(string nick) = 0;
	virtual Estudiante* buscarEstudiante(string nick) = 0;
	virtual Curso* buscarCurso(string nombreCurso) = 0;

	virtual bool verificarNick(string nickname) = 0; // Nueva función para verificar el nick
	virtual void agregarEstudiante(string nickname, string password, string nombre, string desc, string pais) = 0;
	virtual void agregarProfesor(string nickname, string password, string nombre, string desc, string instituto, set<string> idioma) = 0;
	virtual void altaIdioma(string nombre) = 0;

	virtual set<string> listarIdiomas() = 0;
	virtual void ConsultarIdiomas() = 0;
	virtual set<string> listarCursos() = 0;
	virtual set<string> listarNombreProfesores() = 0;
	virtual set<string> listarNickNames() = 0;

	virtual void listarInfoCurso(string nombreCurso) = 0;
	virtual void listarInfoUsuario(string nickname) = 0;


	virtual Curso* ingresaElCurso(string NombreCurso, string descripcion, string dificultad, string nombre, set<string>idiomas) = 0;
	virtual void seleccionarCursosPrevios(set<string> cursos, Curso* nuevoCurso) = 0;
	virtual Idioma* seleccionarIdioma(string nombreIdioma) = 0;
	virtual Leccion* agregarLeccion(Curso* curso, int numero, string tema, string objetivo) = 0;
	virtual void agregarEjercicio(Leccion* leccion, string nombreEjercicio, string descripcion, string fraseA, string fraseB, int opcion) = 0;
	virtual void daDeAltaCurso(Curso* curso) = 0;

	virtual set<string> listarCursosDisponibles(string nick) = 0;
	virtual void inscribirseACurso(string curso, string nick) = 0;

	virtual void cosoEjercicio()=0;
	virtual bool listarCursosPendientesDeAlumno(string nickname)=0;
	virtual set<Ejercicio*> listarEjerciciosPendientesDeCurso(string nom_cur, Estudiante* estudiante)=0;
	virtual void IngresarSolucion()=0;
	virtual void listarNicksEstudiantes()=0;

	virtual set<string> listarCursosNoHabilitados() = 0;
	virtual void habilitarCurso(string nombreCurso) = 0;
};
#endif
