#ifndef ELIMINARCURSO_H_
#define ELIMINARCURSO_H_
#include "../negocio/controller/Controller.h"

class EliminarCurso {
private:
	Icontroller* controlador;
public:
	EliminarCurso();
	virtual ~EliminarCurso();
	void eliminarCurso();
	
};

#endif
