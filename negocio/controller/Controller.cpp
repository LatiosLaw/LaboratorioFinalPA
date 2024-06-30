#include "Controller.h"
#include "String.h"

Controller *Controller::controlador = nullptr; // Inicializar la variable de clase

void Controller::inicializarDatos()
{
    ListaUsuarios = set<Usuario*>();
    ListaIdiomas = set<Idioma*>();
    ListaCursos = set<Curso*>();
    ListaRegistros = set<Registro*>();

	// Idiomas
    Idioma* I1 = new Idioma("Ingles");
    Idioma* I2 = new Idioma("Aleman");
    Idioma* I3 = new Idioma("Portugues");

	// Crear instancias de fechas para los estudiantes
    Fecha F1(15,7,1995);
    Fecha F2(28,2,1998);
    Fecha F3(10,11,1994);
    Fecha F4(22,4,1997);
    Fecha F5(03,9,1996);
    Fecha F6(12,1,1999);
    Fecha F7(25,6,1993);
    Fecha F8(8,12,1997);
    Fecha F9(17,3,1995);
    Fecha F10(02,8,1998);

    // Crear instancias de Estudiantes
    Usuario* U1 = new Estudiante("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.", F1, "Argentina");
    Usuario* U2 = new Estudiante("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", F2, "Ecuador");
    Usuario* U3 = new Estudiante("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", F3, "Peru");
    Usuario* U4 = new Estudiante("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", F4, "Chile");
    Usuario* U5 = new Estudiante("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", F5, "Uruguay");
    Usuario* U6 = new Estudiante("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.", F6, "Argentina");
    Usuario* U7 = new Estudiante("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", F7, "Colombia");
    Usuario* U8 = new Estudiante("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", F8, "Uruguay");
    Usuario* U9 = new Estudiante("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", F9, "Chile");
    Usuario* U10 = new Estudiante("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme", F10, "Bolivia");

    // Crear instancias de Profesores y asociarles Idiomas
    Profesor* U11 = new Profesor("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas.", "Instituto de Idiomas Moderno");
	U11->asociarIdioma(I1);
	U11->asociarIdioma(I3);

    Profesor* U12 = new Profesor("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Centro Global");
	U12->asociarIdioma(I1);
	U12->asociarIdioma(I2);
	U12->asociarIdioma(I3);

    Profesor* U13 = new Profesor("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas", "Instituto de Idiomas Vanguardia");
	U13->asociarIdioma(I2);
	
    Profesor* U14 = new Profesor("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", "Centro de Idiomas");
	U14->asociarIdioma(I3);

    Profesor* U15 = new Profesor("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", "Instituto de Idiomas Progreso");
	U15->asociarIdioma(I1);

    // Insertar los usuarios en la lista
    ListaUsuarios.insert(U1);
    ListaUsuarios.insert(U2);
    ListaUsuarios.insert(U3);
    ListaUsuarios.insert(U4);
    ListaUsuarios.insert(U5);
    ListaUsuarios.insert(U6);
    ListaUsuarios.insert(U7);
    ListaUsuarios.insert(U8);
    ListaUsuarios.insert(U9);
    ListaUsuarios.insert(U10);

    ListaUsuarios.insert(U11);
    ListaUsuarios.insert(U12);
    ListaUsuarios.insert(U13);
    ListaUsuarios.insert(U14);
    ListaUsuarios.insert(U15);

	
	Curso* Cp = new Curso("cp",". Curso de Prueba", dificultad::principiante, U11, I1, true);
	
	
    Curso* C1 = new Curso("Ingles para principiantes","Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", dificultad::principiante, U11, I1, true);
    Curso* C2 = new Curso("Curso de ingles basico","Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", dificultad::principiante, U11, I1, false);
    Curso* C3 = new Curso("Ingles intermedio: mejora tu nivel","Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", dificultad::media, U12, I1, true);
    Curso* C4 = new Curso("Curso avanzado de ingles","Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", dificultad::avanzado, U12, I1, true);
    Curso* C5 = new Curso("Portugues intermedio","Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", dificultad::media, U12, I3, true);
    Curso* C6 = new Curso("Portugues avanzado","Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", dificultad::avanzado, U14, I3, false);

    //crear lecciones y añadirlas alos cursos
	//USAR 	OPERACION DE ANDRES CON DATOS AQUI.
	
    //Linkear y crear ejercicios con lecciones 1- completar 2- traduccion
	Leccion* L1 = new Leccion(1,"Saludos y Presentaciones","Aprender a saludar y despedirse");
	Leccion* L2 = new Leccion(2,"Comprender y utilizar los articulos definidos e indefinidos","Aprender a formar los plurales regulares e irregulares de sustantivos");
	Leccion* L3 = new Leccion(3,"Comprender y utilizar los articulos definidos e indefinidos","Aprender a formar los plurales regulares e irregulares de sustantivos");
	Leccion* L4 = new Leccion(4,"Presente Simple","Aprender el uso del presente simple");
	Leccion* L5 = new Leccion(5,"Conversaciones cotidianas","Aprender a hacer preguntas y respuestas en situaciones comunes");
	Leccion* L6 = new Leccion(6,"Uso de modales avanzados","Explorar el uso de los modales complejos");
	Leccion* L7 = new Leccion(7,"Lectura y comprension de textos","Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");

    L1->agregarEjercicio("E1","Presentaciones","Mucho gusto en conocerte","Nice to meet you",2);
    L1->agregarEjercicio("E2","Presentaciones formales","Please --- me to introduce ---","allow, myself",1);
    L1->agregarEjercicio("E3","Plurales regulares","I have two brothers and three sisters","Tengo dos hermanos y tres hermanas",2);
    L1->agregarEjercicio("E4","Sustantivos contables en plural","Can I have --- water, please?","some",1);
    L1->agregarEjercicio("E5","Actividades diarias","Wake ---","up",1);
    L1->agregarEjercicio("E6","Consultas de la hora","Q: Do you --- the time?, A: Yes, it is half --- 4","have, past",1);
    L1->agregarEjercicio("E7","Dar consejos o expresar obligacion","You should visit that museum","Deberias visitar ese museo",2);
    L1->agregarEjercicio("E8","Imperativo","Fale comigo","Habla conmigo",2);
	
	
    ListaIdiomas.insert(I1);
    ListaIdiomas.insert(I2);
    ListaIdiomas.insert(I3);

	
    ListaCursos.insert(C1);
    ListaCursos.insert(C2);
    ListaCursos.insert(C3);
    ListaCursos.insert(C4);
    ListaCursos.insert(C5);
    ListaCursos.insert(C6);
    ListaCursos.insert(Cp);
    //C3->linkearProfesor(U12);
}

Controller::Controller() // Inicializar las listas del Controlador y datos precargados
{
	inicializarDatos();
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

Usuario* Controller::buscarUsuario(string nick)
{
	for (Usuario* usuario : ListaUsuarios)
	{
		if (usuario->getNickname() == nick)
		{
			cout << "Usuario encontrado" << endl;
			return usuario;
			break;
		}
	}
	cout << "Usuario no encontrado" << endl;
	return nullptr;	
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

Estudiante* Controller::buscarEstudiante_peroCallao(string nick){
for (Usuario* usuario : ListaUsuarios)
	{
		Estudiante* student = dynamic_cast<Estudiante*>(usuario);
		if(student != nullptr)
		{
			if (student->getNickname() == nick)
		{
			Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
			return estudiante;
			break;
		}
		}
	}
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

set<string> Controller::listarNickNames()
{
	set<string>nicks;
	for(auto usuario : ListaUsuarios)
	{
		nicks.insert(usuario->getNickname());
	}
	return nicks;
}

void Controller::listarInfoCurso(string nombreCurso)
{
	 /*Luego, el Sistema muestra el nombre del curso,
    la descripción, la dificultad (Principiante, Medio, Avanzado), 
    el nombre del idioma, el nombre del profesor y si se encuentra habilitado o no.*/
	Curso* curso = buscarCurso(nombreCurso);

	if(curso != nullptr){
		curso->mostrarInfo();
	}else{
		cout << "El curso ingresado no existe." << endl;
	}
}

void Controller::listarInfoUsuario(string nickname)
{
	Usuario* usuario = buscarUsuario(nickname);

	if(usuario != nullptr){
		usuario->listarInfoUsuario();
	}else{
		cout << "El Usuario ingresado no existe." << endl;
	}
}

Curso* Controller::ingresaElCurso(string NombreCurso, string descripcion, int dificultad, string nombreP, set<string> idiomasSeleccionados)
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
		curso = new Curso(NombreCurso, descripcion, false, dificultad);

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

Leccion* Controller::agregarLeccion(Curso* curso, int numero, string tema, string objetivo){
	Leccion* lec = curso->agregarLeccion(numero, tema, objetivo);
	return lec;
}

void Controller::agregarEjercicio(Leccion* leccion, string nombreEjercicio, string descripcion, string fraseA, string fraseB, int opcion){
	leccion->agregarEjercicio(nombreEjercicio, descripcion, fraseA, fraseB, opcion);
}

set<string> Controller::listarCursosDisponibles(string nick)
{
	Estudiante* estudiante = buscarEstudiante(nick);
	set<Curso*> cursosAprobados;

	if(estudiante != nullptr){
		cursosAprobados = estudiante->buscarCursosAprobados();
	}

	set<string> cursosDisponibles;

	for(auto curso : ListaCursos)
	{
		bool siCumple = false;
		if(curso->getHabilitado() == true){
			siCumple = curso->cumplePrevias(cursosAprobados);
			if(siCumple == true){
				cursosDisponibles.insert(curso->getNombreCurso());
			}
		}else{
			cout << "El curso no esta habilitado" << endl;
		}
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

bool Controller::listarCursosPendientesDeAlumno(Estudiante* estudiante)
{
	if (estudiante != nullptr)
	{
		set<Curso *> cursosPendientes;
		cursosPendientes = estudiante->buscarCursosPendientes();
		if (cursosPendientes.empty())
		{
			return false;
		}
		else
		{
			for (Curso *curso : cursosPendientes)
			{
				if (curso != nullptr)
				{
					cout << curso->getNombreCurso() << endl;
				}
			}
			return true;
		}
	}
	return false;
}

//<<<<<<< Updated upstream
set<Ejercicio *> Controller::listarEjerciciosPendientesDeCurso(Estudiante *estudiante, Registro* registro)
{
	set<Ejercicio *> EjerciciosPendientes;
	EjerciciosPendientes = estudiante->buscarCursoYEjercicios(registro);
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
Leccion* Controller :: confirmarDatosAgregarLeccion(string cursoNombre,string tema,string objetivo){
	
	bool token = false;
	set<string> cursos;
	string nombreCurso;
	Curso *cursoEncontrado;
	Leccion* lecci;
	for (Curso *curso : ListaCursos)
	{
		if(curso->getNombreCurso() == cursoNombre){
			token = true;
			nombreCurso = curso->getNombreCurso();
			cursoEncontrado = curso;
		}
		if(token == true){
			break;
		}
	}
	
	if (token == true){
		
		lecci = cursoEncontrado->crearLeccion(tema, objetivo);
	}else{
		cout << "No existe curso con ese nombre" <<endl;
		lecci = nullptr;
	}
	
	
	
	
	return lecci;
}


set<string> Controller::listarNombreCursosHabilitados(){
	set<string> cursos;
	for (Curso *curso : ListaCursos)
	{
		if(curso->getHabilitado() == true){
			cursos.insert(curso->getNombreCurso());
		}
	}
	return cursos;
}



	// Falta un metodo para seleccionar el ejercicio de la lista :v (Me olvide de lo mas boludo), este metodo tambien debería de generar la visual del ejercicio para que la persona realice y demás.

void Controller::IngresarSolucion(){
    // Al ejercicio selecionado en especifico, pedirle que verifique si la solucion que escribio el usuario es igual a la que el esperaba, en caso de que ahi sea, retorna true y por lo tanto el ejercicio deberia ser agregado a la lista de ejercicios aprobados del estudiante en ese curso. 
}

void Controller::cosoEjercicio(){

}


set<string> Controller::listarCursosNoHabilitados(){
	set<string> nombresCursos;
	for (auto c : ListaCursos){
		if (c->getHabilitado() == false){
			nombresCursos.insert(c->getNombreCurso());
		}
	}
	return nombresCursos;
}

void Controller::habilitarCurso(string nombreCurso){
	// busco el curso.
	Curso *c;
	c = buscarCurso(nombreCurso);
	if (c == nullptr){
		cout << "error Curso no existe. " << endl;
	}
	else{
		// si existe pregunto si cumple los requisitos
		// si tiene lecciones
		if (c->tieneLecciones()){
			// si toda leccion tiene almenos un ejercicio

			if (c->todasLasLeccionesTienenEjercicios()){
				c->Habilitate();
				cout << "Curso Habilitado! " << endl;
			}
		}
	}
}

void Controller::nicksEstudiantes()
{
	cout << endl << "Nicknames de los Estudiantes existentes: " << endl;
	set<Estudiante*> estudiantes;

	for (Usuario* usuario : ListaUsuarios)
	{
		Estudiante* student = dynamic_cast<Estudiante*>(usuario);
		if(student != nullptr)
		{
			cout << student->getNickname() << endl;
		}
	}
}

void Controller::nicksProfesores()
{
	cout << endl << "Nicknames de los Profesores existentes: " << endl;
	set<Profesor*> profesores;

	for (Usuario* usuario : ListaUsuarios)
	{
		Profesor* teacher = dynamic_cast<Profesor*>(usuario);
		if(teacher != nullptr)
		{
			cout << teacher->getNickname() << endl;
		}
	}
}

void Controller::nombresCursos()
{
	cout << endl << "Nicknames de los Cursos existentes: " << endl;
	set<Curso*> cursos;

	for (Curso* curso : ListaCursos)
	{
			cout << curso->getNombreCurso() << endl;
	}
}
void Controller::eliminarCursoYsusDerivados(string nombreCurso){
	Curso *c;
	c = buscarCurso(nombreCurso);
	
	
	if (c == nullptr){
		cout << "error Curso no existe. " << endl;
	}
	else{
		eliminarDeProfe(nombreCurso);
		
		c->nukearRegistros();
		c->nukearLecciones();
		
		ListaCursos.erase(c);
		c->chao();
		
		cout << "Curso y sus derivados eliminados correctamente" <<endl;
		
	}
	
}
void Controller::eliminarDeProfe(string nombreCurso){
	set <Usuario*> profes = listaProfes();
	/*int pepe = 0;
	for (Usuario* prro : profes)
	{
	pepe ++;
	
	cout << pepe << prro->getNombreProfesor() << endl;
	
	}
	*/
	for (Usuario* pof : profes)
	{
		dynamic_cast<Profesor*>(pof)->eliminarCursoDeLista(nombreCurso);
	}
}

set<Usuario*> Controller::listaProfes()
{
	set<Usuario*> profesores;
	
	for (Usuario* usuario : ListaUsuarios)
	{
		string nombreProfe = usuario->getNombreProfesor();
		if (nombreProfe != "")
		{
			profesores.insert(usuario);
		}
	}
	return profesores;
	
}








