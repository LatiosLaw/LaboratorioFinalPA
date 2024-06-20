#include "../h/Usuario.h"

Usuario::Usuario(string nick, string nom, string pass, string desc) {
	nickname = nick;
	nombre = nom;
	password = pass;
	descripcion = desc;
}

string Usuario::getNickname() {
	return nickname;
}

string Usuario::getNombre() {
	return nombre;
}

string Usuario::getPassword() {
	return password;
}

string Usuario::getDescripcion() {
	return descripcion;
}

void Usuario::setNickname(string nick) {
	nickname = nick;
}

void Usuario::setNombre(string nom) {
	nombre = nom;
}

void Usuario::setPassword(string pass) {
	password = pass;
}

void Usuario::setDescripcion(string desc) {
	descripcion = desc;
}

string Usuario::getNombreProfesor(){
	return "";
}

void Usuario::listarInfoUsuario(){
	cout << "Usuario: " << this->nickname << endl;
	cout << "Nombre: " <<this->nombre << endl;
	cout << "Contrasenia: " << this->password << endl;
	cout << "Descripcion: " << this->descripcion << endl;
}