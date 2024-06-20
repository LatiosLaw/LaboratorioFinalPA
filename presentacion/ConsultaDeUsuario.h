#ifndef PRESENTACION_CONSULTADEUSUARIO_H_
#define PRESENTACION_CONSULTADEUSUARIO_H_
#include "../negocio/controller/Controller.h"

class ConsultaDeUsuario {
private:
	Icontroller* controlador;
public:
	ConsultaDeUsuario();
	virtual ~ConsultaDeUsuario();
	void consultarUsuarios();
	void listarNicks();
};

#endif /* PRESENTACION_CONSULTADEUSUARIO_H_ */
