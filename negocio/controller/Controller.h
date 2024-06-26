#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Icontroller.h"
#include "../dominio/h/Usuario.h"
#include "../dominio/h/Estudiante.h"
#include "../dominio/h/Registro.h"
#include "../dominio/h/Profesor.h"
#include "../dominio/h/Curso.h"
#include "../dominio/h/Idioma.h" //tuve que agregarlo
#include <iostream>
#include <list>
#include <set>

class Controller : public Icontroller{
	
private:
	Controller(); // Paso 1 para cumplir el Patron Singleton
	static Controller* controlador; // Paso 2
	set<Usuario*>ListaUsuarios;
	set<Idioma*>ListaIdiomas;
	set<Curso*>ListaCursos;
	set<Registro*>ListaRegistros;

public:
	static Controller* getInstance(); // Paso 3
	virtual void inicializarDatos();
	
	virtual Usuario* buscarUsuario(string nick);
	virtual Profesor* buscarProfesor(string nombreProfesor);
	virtual Profesor* buscarProfesor2(string nickprofe);
	virtual Estudiante* buscarEstudiante(string nick);
	virtual Curso* buscarCurso(string nombreCurso);

	virtual Estudiante* buscarEstudiante_peroCallao(string nick);

	virtual bool verificarNick(string nickname); // Nueva función para verificar el nick
	virtual void agregarEstudiante(string nickname, string password, string nombre, string desc, string pais, Fecha fecha);
	virtual void agregarProfesor(string nickname, string password,string nombre,string desc,string instituto, set<string> idioma);
	virtual void altaIdioma(string nombre);

	virtual set<string> listarIdiomas();
	virtual void ConsultarIdiomas();
	virtual set<string> listarNombreProfesores();
	virtual set<string> listarCursos();
	virtual set<string> listarNickNames();


	virtual void listarInfoCurso(string nombreCurso);
	virtual void listarInfoUsuario(string nickname);

	virtual Curso* ingresaElCurso(string NombreCurso, string descripcion, int dificultad, string nombre, set<string>idiomas);
	virtual void seleccionarCursosPrevios(set<string> cursos, Curso* nuevoCurso);
	virtual Idioma* seleccionarIdioma(string nombreIdioma);
	virtual Leccion* agregarLeccion(Curso* curso, int numero, string tema, string objetivo);
	virtual void agregarEjercicio(Leccion* leccion, string nombreEjercicio, string descripcion, string fraseA, string fraseB, int opcion);
	virtual void daDeAltaCurso(Curso* curso);

	virtual set<string> listarCursosDisponibles(string nick);
	virtual void inscribirseACurso(string curso, string nick);

	virtual void cosoEjercicio();
	virtual bool listarCursosPendientesDeAlumno(Estudiante* estudiante); // FUNCIONANDO (Aparte de lo que ya dije de los cursos)
	virtual set<Ejercicio*> listarEjerciciosPendientesDeCurso(Estudiante *estudiante, Registro* registro);
	virtual void IngresarSolucion();
	virtual void listarNicksEstudiantes();

	virtual set<string> listarCursosNoHabilitados();
	virtual void habilitarCurso(string nombreCurso);

	virtual void nicksEstudiantes();
	virtual void nicksProfesores();
	virtual void nombresCursos();

	virtual Leccion* confirmarDatosAgregarLeccion(string cursoNombre,string tema,string objetivo);
	virtual set<string> listarNombreCursosHabilitados();
	virtual void eliminarCursoYsusDerivados(string nombreCurso);
	virtual set<Usuario*> listaProfes();
	virtual void eliminarDeProfe(string nombreCurso);
	virtual ~Controller();
};
#endif
