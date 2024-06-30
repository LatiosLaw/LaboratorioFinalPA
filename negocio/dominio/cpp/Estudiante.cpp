#include "../h/Estudiante.h"
#include "../h/Curso.h"
#include "../h/Registro.h"

Estudiante::Estudiante(string nick, string pass, string nom, string desc, Fecha fecha, string pai ) : Usuario(nick, pass, nom, desc) {
	pais = pai;
	fechaNacimiento = fecha;
}

Estudiante::Estudiante(string nick, string nom, string pass, string desc, string pai) : Usuario(nick, nom, pass, desc) {
	pais = pai;
}

Estudiante::Estudiante(string nick, string pass, string nom, string desc) : Usuario(nick, pass, nom, desc)
{

}

string Estudiante::getPais() {
	return this->pais;
}

Fecha Estudiante::getFechaNacimiento() {
	return this->fechaNacimiento;
}

void Estudiante::setPais(string pai) {
	pais = pai;
}

void Estudiante::setFechaNacimiento(Fecha fecha) {
	fechaNacimiento = fecha;
}

string Estudiante::getNickname(){
	return this->nickname;
}

string Estudiante::getNombreProfesor(){
	return "";
}

void Estudiante::listarInfoUsuario()
{
	Usuario::listarInfoUsuario();
	cout << "Pais: " << this->pais << endl;
	cout << "Fecha Nacimiento: " << this->fechaNacimiento.getDia() << "/" << this->fechaNacimiento.getMes() << "/" << this->fechaNacimiento.getAnio() << endl;
}

void Estudiante::agregarInscripcion(Registro* registro)
{
	this->ListaRegistros.insert(registro);
	cout << "Registro agregado a la lista del estudiante." << endl;
}

Registro* Estudiante::buscarRegistroACurso(string nom_cur){
for (Registro* registro : ListaRegistros){
	{
		if (registro->verificarCurso(nom_cur))
		{
			return registro;
			break;
		}
	}
  }
  return nullptr;
}

set<Curso *> Estudiante::buscarCursosPendientes()
{
	set<Curso *> cursosPendientes;
	Curso *resultado;
	for (Registro *registros : ListaRegistros)
	{
		resultado = registros->obtenerDataCursoSiPendiente();
		if (resultado != nullptr)
		{
			cursosPendientes.insert(resultado);
		}
	}
	return cursosPendientes;
}

set<Ejercicio *> Estudiante::buscarCursoYEjercicios(Registro* registro)
{
	set<Ejercicio *> ejercicioPendientes;
	if (registro != nullptr)
	{
		ejercicioPendientes = registro->buscarEjerciciosPendientes();
	}
	return ejercicioPendientes;
}

void Estudiante::obtenerDataType(){

}

set<Curso*> Estudiante::buscarCursosAprobados(){
	set<Curso*> cursosAprobados;
	for(auto registro : ListaRegistros)
	{
		cursosAprobados.insert(registro->devolverCursoAprobado());
	}

	return cursosAprobados;

}

set<DT_EstadisticasEstudiante*> Estudiante::estadisticasEstudiante(){
set<DT_EstadisticasEstudiante*> estadisticas;
string nombre_curso;
string avance;
for (Registro *registros : ListaRegistros)
{
		nombre_curso = registros->pedirNombreACurso();
		avance = registros->getAvance();
		estadisticas.insert(new DT_EstadisticasEstudiante(nombre_curso,avance));
}
return estadisticas;
}