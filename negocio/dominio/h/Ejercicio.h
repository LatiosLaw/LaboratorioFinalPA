#ifndef EJERCICIO_H
#define EJERCICIO_H
#include <iostream>
#include <string>

using namespace std;

class Ejercicio{
	
private:
	string descripcion;
	string nombreEjercicio;
	
public:
	Ejercicio();
	Ejercicio(string nombreEjercicio, string descripcion);
	
	virtual ~Ejercicio();
};
#endif
