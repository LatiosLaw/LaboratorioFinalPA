#include "../h/Usuario.h"

Usuario::Usuario(string nick, string pass, string nom, string desc) {
	this->nickname = nick;
	this->password = pass;
	this->descripcion = desc;
	this->nombre = nom;
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
	this->nickname = nick;
}

void Usuario::setNombre(string nom) {
	this->nombre = nom;
}

void Usuario::setPassword(string pass) {
	this->password = pass;
}

void Usuario::setDescripcion(string desc) {
	this->descripcion = desc;
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