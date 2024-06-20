#include "Controller.h"
#include "String.h"

Controller *Controller::controlador = nullptr; // Inicializar la variable de clase

Controller::Controller() // Inicializar las listas del Controlador
{
	ListaUsuarios = set<Usuario*>();
	ListaIdiomas = set<Idioma*>();
	ListaCursos = set<Curso*>();
	ListaRegistros = set<Registro*>();

	Usuario* user1 = new Profesor("pepe","123","Pepe","Alto","Instituto1");
	Usuario* user2 = new Profesor("juan","456","Juan","Bajo","Instituto2");
	Usuario* user3 = new Estudiante("pedro","Pedro","789","Bajo","Uruguay");

	Idioma* nuevoIdioma1 = new Idioma("ingles");
	Idioma* nuevoIdioma2 = new Idioma("chino");
	Idioma* nuevoIdioma3 = new Idioma("japones");

	Curso* curso1 = new Curso("curso1","buenCurso",false,medio);

	ListaUsuarios.insert(user1);
	ListaUsuarios.insert(user2);
	ListaUsuarios.insert(user3);

	ListaIdiomas.insert(nuevoIdioma1);
	ListaIdiomas.insert(nuevoIdioma2);
	ListaIdiomas.insert(nuevoIdioma3);

	ListaCursos.insert(curso1);
}

Controller::~Controller() // destructor
{
}

Controller* Controller::getInstance() // Singleton, se crea la instancia del controlador si no existe, y si ya existe simplemente la retorna.
{
	if (controlador == nullptr)
	{
		controlador = new Controller();
	}
	return controlador;
}

Profesor* Controller::buscarProfesor(string nombreProfesor)
{
	bool profesorEncontrado = false;

	for (Usuario* usuario : ListaUsuarios)
	{
		if (usuario->getNombreProfesor() == nombreProfesor)
		{
			cout << "Profesor encontrado" << endl;
			profesorEncontrado = true;
			Profesor *profesor = dynamic_cast<Profesor*>(usuario);
			return profesor;
			break;
		}
	}

	if (!profesorEncontrado)
	{
		cout << "Profesor no encontrado" << endl;
		return nullptr;
	}
	return nullptr;
}

Estudiante* Controller::buscarEstudiante(string nick)
{
	for (Usuario* usuario : ListaUsuarios)
	{
		Estudiante* student = dynamic_cast<Estudiante*>(usuario);
		if(student != nullptr)
		{
			if (student->getNickname() == nick)
		{
			cout << "Estudiante encontrado" << endl;
			Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
			return estudiante;
			break;
		}
		}
	}
	cout << "Estudiante no encontrado" << endl;
	return nullptr;	
}

Curso *Controller::buscarCurso(string nombreCurso)
{
	for (Curso *curso : ListaCursos)
	{
		if (curso->getNombreCurso() == nombreCurso)
		{
			cout << "Curso encontrado" << endl;
			return curso;
		}
	}
	return nullptr;
}

bool Controller::verificarNick(string nickname) // Recibe nickname y se fija si ya existe en la ListaUsuarios
{
	for (Usuario *usuario : ListaUsuarios)
	{
		if (usuario->getNickname() == nickname)
		{
			return true;
		}
	}
	return false;
}

void Controller::agregarEstudiante(string nickname, string password, string nombre, string desc, string pais) // ver este metodo luego, porque se supone que ya verifique que el usuario no exista
{
	Estudiante *nuevoEstudiante = new Estudiante(nickname, password, nombre, desc, pais);
	ListaUsuarios.insert(nuevoEstudiante);
	cout << "Estudiante agregado exitosamente." << endl;
}

void Controller::altaIdioma(string nombre) // Recibe nombre del idioma, se fija que no exista, y lo agrega a la ListaIdiomas
{
	bool idiomaEncontrado = false;

	for (Idioma* idioma : ListaIdiomas)
	{
		if (idioma->getNombreIdioma() == nombre)
		{
			cout << "El Idioma ingresado ya existe en el Sistema, error." << endl;
			idiomaEncontrado = true;
			break;
		}
	}

	if (!idiomaEncontrado)
	{
		Idioma *nuevoIdioma = new Idioma(nombre);
		ListaIdiomas.insert(nuevoIdioma);
		cout << "Idioma agregado exitosamente"<< endl;
	}
}

void Controller::agregarProfesor(string nickname, string password, string nombre, string desc, string instituto, set<string> idioma)
{

	Profesor *nuevoProfesor = new Profesor(nickname, password, nombre, desc, instituto);
	ListaUsuarios.insert(nuevoProfesor);

	cout << "Profesor agregado exitosamente." << endl;

	bool idiomaEncontrado = false;
	set<string>::iterator itI;

	if (!idioma.empty())
	{
		for (itI = idioma.begin(); itI != idioma.end(); ++itI)
		{
			string idiomaActual = *itI;
			Idioma *elIdioma = nullptr;

			// Buscar el idioma en la ListaIdiomas
			for (Idioma *i : ListaIdiomas)
			{
				if (i->getNombreIdioma() == idiomaActual)
				{
					elIdioma = i;
					break;
				}
			}

			if (elIdioma != nullptr)
			{
				nuevoProfesor->asociarIdioma(elIdioma);
				idiomaEncontrado = true;
			}
			else
			{
				cout << "El idioma '" << idiomaActual << "' no se encontró en la lista de idiomas." << endl;
			}
		}
		if (idiomaEncontrado)
		{
			cout << "Idiomas asociados al profesor " << nuevoProfesor->getNickname() << ":" << endl;
			nuevoProfesor->listarMisIdiomas();
		}
		else
		{
			cout << "No se encontraron idiomas válidos para asociar al profesor." << nuevoProfesor->getNombreProfesor() << endl;
		}
	}
}

set<string> Controller::listarIdiomas() // Lista los nombres de los idiomas existentes en ListaIdiomas
{
	set<string> idiomasDisponibles;
	for (Idioma* idioma : ListaIdiomas)
	{
		idiomasDisponibles.insert(idioma->getNombreIdioma());
	}
	return idiomasDisponibles;
}

void Controller::ConsultarIdiomas()
{
	for (Idioma* idioma : ListaIdiomas)
	{
		cout << idioma->getNombreIdioma() << ", ";
	}
}

set<string> Controller::listarNombreProfesores()
{
	cout << endl << "Nombres de los Profesores existentes: " << endl;
	set<string> profesores;

	for (Usuario* usuario : ListaUsuarios)
	{
		string nombreProfe = usuario->getNombreProfesor();
		if (nombreProfe != "")
		{
			cout << nombreProfe << endl;
			profesores.insert(usuario->getNombreProfesor());
		}
	}
	return profesores;

	// void Controller::listarNombreProfesores() {
	//	std::list<Usuario*>::iterator itU;
	//	for (itU = ListaUsuarios.begin(); itU != ListaUsuarios.end(); ++itU) {
	//		Profesor *profesor = dynamic_cast<Profesor*>(*itU);
	//		if (profesor != nullptr) {
	//			std::cout << profesor->getNombre() << std::endl;
	//		}
	//	}
	// }
}

set<string> Controller::listarCursos()
{
	set<string> cursos;
	for (Curso *curso : ListaCursos)
	{
		//cout << curso->getNombreCurso() << endl;
		cursos.insert(curso->getNombreCurso());
	}
	return cursos;
}

Curso* Controller::ingresaElCurso(string NombreCurso, string descripcion, string dificultad, string nombreP, set<string> idiomasSeleccionados)
{
	Profesor *profesor = buscarProfesor(nombreP);
	if (profesor == nullptr)
	{
		return nullptr;
	}

	Curso *curso = buscarCurso(NombreCurso);
	if (curso != nullptr)
	{
		cout << "El curso ingresado ya existe." << endl;
		return curso;
	}
	else
	{
		curso = new Curso(NombreCurso, descripcion, false, facil);

		// Agregar los idiomas seleccionados al curso
		for (string idiomaSeleccionado : idiomasSeleccionados)
		{
			bool idiomaEncontrado = false;
			for (Idioma *idioma : ListaIdiomas)
			{
				if (idioma->getNombreIdioma() == idiomaSeleccionado)
				{
					curso->agregarIdioma(idioma);
					idiomaEncontrado = true;
					break;
				}
			}
			if (!idiomaEncontrado)
			{
				cout << "El idioma " << idiomaSeleccionado << " no se encontró en la lista de idiomas." << endl;
			}
		}

		curso->linkearProfesor(profesor);
		profesor->agregarCurso(curso);
		cout << "Curso creado exitosamente" << endl;
	}
	return curso;
}

void Controller::seleccionarCursosPrevios(set<string> cursos, Curso* nuevoCurso)
{
    for (string nombreCurso : cursos)
    {
        Curso* cEncontrado = buscarCurso(nombreCurso);
        if (cEncontrado != nullptr)
        {
            nuevoCurso->seleccionarCursoPrevio(cEncontrado);
        }
    }
}

void Controller::daDeAltaCurso(Curso *curso)
{
	this->ListaCursos.insert(curso);
}

Idioma* Controller::seleccionarIdioma(string nombreIdioma) // Recibe el nombre de un idioma, lo busca en la ListaIdiomas, y retorna puntero a una instancia de Idioma
{
	cout << "Realizando Seleccionar Idioma" << endl;

	bool idiomaEncontrado = false;

	Idioma* idiomaSeleccionado;

	for (auto idioma : ListaIdiomas)
	{
		if (idioma->getNombreIdioma() == nombreIdioma)
		{
			cout << "Idioma encontrado" << endl;
			idiomaEncontrado = true;
			idiomaSeleccionado->seleccionarIdioma();
			break;
		}
	}

	if (!idiomaEncontrado)
	{
		cout << "Idioma no encontrado" << endl;
		return nullptr;
	}

	return idiomaSeleccionado;
	//creo que funciona, toque algo
}

set<string> Controller::listarCursosDisponibles(string nick)
{
	set<string>cursosDisponibles;
	for(auto curso : ListaCursos)
	{
		cout << curso->getNombreCurso() << ", " << endl;
		cursosDisponibles.insert(curso->getNombreCurso());
	}
	return cursosDisponibles;
}

void Controller::inscribirseACurso(string curso, string nick)
{	
	Curso* elCurso = buscarCurso(curso);
	if (elCurso != nullptr)
	{
		Estudiante* elEstudiante = buscarEstudiante(nick);
		if(elEstudiante != nullptr){
			elCurso->inscribirse(elEstudiante);
		}else{
			cout << "Estudiante no encontrado." << endl;
		}
	} else {
		cout << "Curso no encontrado." << endl;
	}
}

void Controller::listarNicksEstudiantes(){
    // Al controller le pido una lista de los nicks de los usuarios de tipo estudiante
	for (Usuario* usuario : ListaUsuarios) //Esto lo deberiamos hacer con dynamic cast, por lo que convendria usar iteradores
	{
		Estudiante* student = dynamic_cast<Estudiante*>(usuario);
		if(student != nullptr)
		{
			cout << usuario->getNickname() << endl;
		}
	}
}

bool Controller::listarCursosPendientesDeAlumno(string nickname){
	Estudiante* estudiante = this->buscarEstudiante(nickname);
	if(estudiante!=nullptr){
		cout << "entre al if" << endl;
	set<Curso*>cursosPendientes;
	cursosPendientes = estudiante->buscarCursosPendientes();
		if(cursosPendientes.empty()){
			cout << "El estudiante no tiene cursos pendientes." << endl;
			return false;
		}else {
			for (Curso* curso : cursosPendientes)
		{
			cout << "entre al for" << endl;
			if(curso!=nullptr){
				cout << curso->getNombreCurso() << endl;
			}
		}
		return true;
		}
	}
}

set<Ejercicio *> Controller::listarEjerciciosPendientesDeCurso(string nom_cur, Estudiante *estudiante)
{
	set<Ejercicio *> EjerciciosPendientes;
	EjerciciosPendientes = estudiante->buscarCursoYEjercicios(nom_cur);
	cout << "El programa ahora listara los ejercicios pendientes de la ultima leccion que aun no ha completado en este curso, queda avisado, no todos los ejercicios pendientes DEL CURSO seran visibles." << endl;
	cout << "Inicio de la lista de Ejercicios Pendientes" << endl;
	for (Ejercicio *ejercicio : EjerciciosPendientes) // Esto lo deberiamos hacer con dynamic cast, por lo que convendria usar iteradores
	{
		if (ejercicio != nullptr)
		{
			cout << ejercicio->getnombreEjercicio() << endl;
		}
	}
	cout << "Fin de la lista de Ejercicios Pendientes" << endl;
	return EjerciciosPendientes;
	// En este caso le pasamos directamente a un curso que sabemos que esta pendiente, la lista de ejercicios completados del alumno desde el registro, para posteriormente pedirle al curso que pase por cada una de sus lecciones y verifique si todos sus ejercicios se encuentran en la lista
	// En caso de que todos los ejercicios de la leccion se encuentren en la lista, se sale de la leccion y se la considera completada (Cosa que no se refleja en ningun lado), pasando a la siguiente leccion y repitiendo, si todas las lecciones estan completadas, el curso no esta pendiente sino completado y el avance debe ser cambiado a 100.
	// En caso de que un ejercicio de una leccion no este en la lista de aprobados, se guarda hasta que se completa el for dentro de la leccion y se retorna la lista de aquellos ejercicios que no esten en la lista de aprobados.
}

	// Falta un metodo para seleccionar el ejercicio de la lista :v (Me olvide de lo mas boludo), este metodo tambien debería de generar la visual del ejercicio para que la persona realice y demás.

void Controller::IngresarSolucion(){
    // Al ejercicio selecionado en especifico, pedirle que verifique si la solucion que escribio el usuario es igual a la que el esperaba, en caso de que ahi sea, retorna true y por lo tanto el ejercicio deberia ser agregado a la lista de ejercicios aprobados del estudiante en ese curso. 
}

void Controller::cosoEjercicio(){

}