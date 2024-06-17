#ifndef PRESENTACION_REALIZAREJERCICIO_H_
#define PRESENTACION_REALIZAREJERCICIO_H_
#include "../negocio/controller/Controller.h"

class RealizarEjercicio {
private:
	Icontroller* controlador;
public:
	RealizarEjercicio();
	virtual ~RealizarEjercicio();
	void cosoEjercicio();
	void listarCursosPendientesDeAlumno();
	void listarEjerciciosPendientesDeCurso();
	void IngresarSolucion();
};

#endif /* PRESENTACION_REALIZAREJERCICIO_H_ */
