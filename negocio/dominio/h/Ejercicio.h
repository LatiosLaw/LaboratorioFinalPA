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

	// Metodos de los casos de Martin, faltan retornos y parametros

	void Pendiente(); // Esto tambien requiere la lista de ejercicios
	void obtenerDataType();

	///////////////////////////////////////////////////////////////
};
#endif
