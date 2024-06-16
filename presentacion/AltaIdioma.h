#ifndef PRESENTACION_ALTAIDIOMA_H_
#define PRESENTACION_ALTAIDIOMA_H_
#include "../negocio/controller/Controller.h"
#include <set>

class AltaIdioma {
private:
	Icontroller* controlador;
	//puntero a la interface, seria lo mismo apuntar al controlador, aunque es mas correcto esto, 
	//debido a ventajas que tendria con patrones como Factory, ventajas que no llegaremos a notar ahora, pero que es una buena practica
public:
	AltaIdioma();
	virtual ~AltaIdioma();
	void altaIdioma();
};

#endif /* PRESENTACION_ALTAIDIOMA_H_ */
