#ifndef COMPLETARPALABRA_H
#define COMPLETARPALABRA_H
#include "Ejercicio.h"
class CompletarPalabra : public Ejercicio{
	
private:
	string fraseACompletar;
	string fraseCorrecta;
	
public:
	CompletarPalabra();
	CompletarPalabra(string nombreEjercicio, string descripcion, string fraseACompletar, string fraseCorrecta);
	
	virtual ~CompletarPalabra();
};
#endif
