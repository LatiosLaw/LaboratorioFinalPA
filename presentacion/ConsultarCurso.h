#ifndef PRESENTACION_CONSULTARCURSO_H_
#define PRESENTACION_CONSULTARCURSO_H_
#include "../negocio/controller/Controller.h"

class ConsultarCurso {
private:
	Icontroller* controlador;
public:
	ConsultarCurso();
	virtual ~ConsultarCurso();
	void consultarCurso();
	void listarCursos();
};

#endif /* PRESENTACION_CONSULTARCURSO_H_ */
