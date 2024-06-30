#ifndef PRESENTACION_CONSULTARIDIOMA_H_
#define PRESENTACION_CONSULTARIDIOMA_H_
#include "../negocio/controller/Controller.h"

class consultarIdioma {
private:
	Icontroller* controlador;
public:
	consultarIdioma();
	virtual ~consultarIdioma();
	//void consultarCurso();
	void listarIdomas();
};

#endif /* PRESENTACION_CONSULTARCURSO_H_ */
