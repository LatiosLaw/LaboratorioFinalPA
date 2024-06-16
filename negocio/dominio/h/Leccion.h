#ifndef LECCION_H
#define LECCION_H
#include <set>
#include "Ejercicio.h"
class Leccion{
	
private:
	int numero;
	string tema;
	string objetivo;
	set<Ejercicio*>ListaEjercicios;
	
public:
	Leccion();
	Leccion(int numero, string tema, string objetivo);
	
	virtual ~Leccion();
};
#endif
