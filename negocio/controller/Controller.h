#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Icontroller.h"
#include "../dominio/h/Usuario.h"
#include "../dominio/h/Estudiante.h"
#include "../dominio/h/Registro.h"
#include "../dominio/h/Profesor.h"
#include "../dominio/h/Curso.h"
#include "../dominio/h/Idioma.h" //tuve que agregarlo
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
	
	virtual Profesor* buscarProfesor(string nombreProfesor);
	virtual Curso* buscarCurso(string nombreCurso);
	virtual bool verificarNick(string nickname); // Nueva función para verificar el nick
	virtual void agregarEstudiante(string nickname, string password, string nombre, string desc, string pais);
	virtual void agregarProfesor(string nickname, string password,string nombre,string desc,string instituto, set<string> idioma);
	virtual void altaIdioma(string nombre);
	virtual set<string> listarIdiomas();
	virtual set<string> listarNombreProfesores();
	virtual void listarCursos();
	virtual Curso* ingresaElCurso(string NombreCurso, string descripcion, string dificultad, string nombre, set<string>idiomas);
	virtual Idioma* seleccionarIdioma(string nombreIdioma);
	virtual void daDeAltaCurso(Curso* curso);
	
	virtual ~Controller();
};
#endif
