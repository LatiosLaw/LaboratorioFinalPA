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
	string getDescripcion();
	virtual ~Ejercicio();

	// Metodos de los casos de Martin, faltan retornos y parametros

	bool Pendiente(set<Ejercicio*> aprobados); // FUNCIONANDO
	Ejercicio* obtenerDataType();

	///////////////////////////////////////////////////////////////
};
#endif
