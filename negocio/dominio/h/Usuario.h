#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

using namespace std;

class Usuario {
protected:
	string nickname;
	string nombre;
	string password;
	string descripcion;
	
public:
	Usuario(string nick, string nom, string pass, string desc);
	
	virtual string getNickname() = 0;
	string getNombre();
	virtual string getNombreProfesor() = 0;
	string getPassword();
	string getDescripcion();

	void setNickname(string nick);
	void setNombre(string nom);
	void setPassword(string pass);
	void setDescripcion(string desc);
};

#endif
