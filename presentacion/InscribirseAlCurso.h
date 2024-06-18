#ifndef PRESENTACION_INSCRIBIRSEALCURSO_H_
#define PRESENTACION_INSCRIBIRSEALCURSO_H_
#include "../negocio/controller/Controller.h"

class InscribirseAlCurso {
private:
	Icontroller* controlador;
public:
	InscribirseAlCurso();
	virtual ~InscribirseAlCurso();
	void inscribirse();
	set<string> listarCursosDisponibles();
};

#endif /* PRESENTACION_INSCRIBIRSEALCURSO_H_ */
