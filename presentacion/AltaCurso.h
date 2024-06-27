#ifndef PRESENTACION_ALTACURSO_H_
#define PRESENTACION_ALTACURSO_H_
#include "../negocio/controller/Controller.h"

class AltaCurso {
private:
	Icontroller* controlador;
public:
	AltaCurso();
	virtual ~AltaCurso();
	void altaCurso();
	set<string> seleccionarIdiomas();
	set<string> seleccionarCursosPrevios();
	void agregarLeccion(Curso* curso);
	void agregarEjercicio(Leccion* leccion);
};

#endif /* PRESENTACION_ALTACURSO_H_ */
