#ifndef AGREGARLECCION_H
#define AGREGARLECCION_H
#include "../negocio/controller/Controller.h"

class AgregarLeccion{
private:
	Icontroller* controlador;
public:
	AgregarLeccion();
	virtual ~AgregarLeccion();
	void agregarLeccion();
	//set<string> seleccionarIdiomas();
	//set<string> seleccionarCursosPrevios();
};

#endif
