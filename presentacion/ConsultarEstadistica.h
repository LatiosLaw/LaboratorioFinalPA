#ifndef PRESENTACION_CONSULTARESTADISTICA_H_
#define PRESENTACION_CONSULTARESTADISTICA_H_
#include "../negocio/controller/Controller.h"

class ConsultarEstadistica{
private:
	Icontroller* controlador;
public:
	ConsultarEstadistica();
	virtual ~ConsultarEstadistica();
	void consultarEstadisticas();
};

#endif /* PRESENTACION_CONSULTARESTADISTICA_H_ */
