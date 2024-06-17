#include "../h/Estudiante.h"

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

void Estudiante::buscarCursosPendientes(){

}

void Estudiante::buscarCursoYEjercicios(){

}

void Estudiante::obtenerDataType(){

}

void Estudiante::estadisticasEstudiante(){

}