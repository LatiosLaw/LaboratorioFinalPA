#include "../h/Estudiante.h"
#include "../h/Curso.h"
#include "../h/Registro.h"

Estudiante::Estudiante(string nick, string nom, string pass, string desc, string pai, Fecha fecha) : Usuario(nick, nom, pass, desc) {
	pais = pai;
	fechaNacimiento = fecha;
}

Estudiante::Estudiante(string nick, string nom, string pass, string desc, string pai) : Usuario(nick, nom, pass, desc) {
	pais = pai;
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
	return nullptr;
}
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

set<Ejercicio*> Estudiante::buscarCursoYEjercicios(string nom_cur){
set<Ejercicio*>ejercicioPendientes;
Registro* registro = this->buscarRegistroACurso(nom_cur); // De la lista de regitros del estudiante devuelve el registro vinculado al curso en cuestion
if(registro!=nullptr){
	ejercicioPendientes = registro->buscarEjerciciosPendientes();
}
return ejercicioPendientes;
}

void Estudiante::obtenerDataType(){

}

void Estudiante::estadisticasEstudiante(){

}