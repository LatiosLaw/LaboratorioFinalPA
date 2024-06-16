#ifndef IDIOMA_H
#define IDIOMA_H
#include <iostream>
#include <string>

using namespace std;

class Idioma {
private:
	string nombreIdioma;
	
public:
	Idioma();
	Idioma(string nombre);
	
	string getNombreIdioma();
	
	void setNombreIdioma(string nombre);
	
	Idioma* seleccionarIdioma();
};

#endif
