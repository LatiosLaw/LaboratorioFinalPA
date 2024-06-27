#ifndef PRESENTACION_AGREGAREJERCICIO_H_
#define PRESENTACION_AGREGAREJERCICIO_H_
#include "../negocio/controller/Controller.h"

class AgregarEjercicio {
private:
	Icontroller* controlador;
public:
	AgregarEjercicio();
	virtual ~AgregarEjercicio();
	void agregarEjercicio();
	
};

#endif
