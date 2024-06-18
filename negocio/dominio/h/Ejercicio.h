#ifndef EJERCICIO_H
#define EJERCICIO_H
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Ejercicio{
	
private:
	string descripcion;
	string nombreEjercicio;
	
public:
	Ejercicio();
	Ejercicio(string nombreEjercicio, string descripcion);
	string getnombreEjercicio();
	virtual ~Ejercicio();

	// Metodos de los casos de Martin, faltan retornos y parametros

	bool Pendiente(set<Ejercicio*> aprobados); // FUNCIONANDO
	void obtenerDataType();

	///////////////////////////////////////////////////////////////
};
#endif
