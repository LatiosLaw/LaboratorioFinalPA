#ifndef PRESENTACION_ALTAUSUARIO_H_
#define PRESENTACION_ALTAUSUARIO_H_
#include "../negocio/controller/Controller.h"

class AltaUsuario {
private:
	Icontroller* controlador;
public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
	void ingresarEstudiante(string nick);
	void ingresarProfesor(string nick);
	set<string> seleccionarIdiomas();
};

#endif /* PRESENTACION_ALTAUSUARIO_H_ */
