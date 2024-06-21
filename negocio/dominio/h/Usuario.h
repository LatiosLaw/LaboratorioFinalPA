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
	Usuario(string nick, string pass, string nom, string desc);
	
	virtual string getNickname();
	string getNombre();
	virtual string getNombreProfesor();
	string getPassword();
	string getDescripcion();

	void setNickname(string nick);
	void setNombre(string nom);
	void setPassword(string pass);
	void setDescripcion(string desc);

	virtual void listarInfoUsuario();
};

#endif
