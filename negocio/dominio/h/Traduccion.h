#ifndef TRADUCCION_H
#define TRADUCCION_H
#include "Ejercicio.h"
class Traduccion : public Ejercicio{
	
private:
	string fraseATraducir;
	string traduccionCorrecta;
	
public:
	Traduccion();
	Traduccion(string nombreE, string desc, string fraseT, string traduccion);
	
	virtual ~Traduccion();
};
#endif
