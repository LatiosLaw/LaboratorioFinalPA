#ifndef LECCION_H
#define LECCION_H
#include <set>
#include "Ejercicio.h"
#include "Traduccion.h"
#include "CompletarPalabra.h"
class Leccion{
	
private:
	int numero;
	string tema;
	string objetivo;
	set<Ejercicio*>ListaEjercicios;
	
public:
	Leccion();
	Leccion(int numero, string tema, string objetivo);

	void agregarEjercicio(string nombreEjercicio, string descripcion, string fraseA, string fraseB, int num);

	string getTema();
	string getObjetivo();

	void mostrarInfoEjercicio();
	
	virtual ~Leccion();

	// Metodos de los casos de Martin, faltan retornos y parametros
	Leccion* agregarLeccion();
	int getNumero(); // Esto es un getter, por lo que no es realmente solo mio XD
	bool Pendiente(set<Ejercicio*> aprobados);
	set<Ejercicio*> buscarEjerciciosPendientes(set<Ejercicio*>aprobados); // Esto requiere una lista de ejercicios

	///////////////////////////////////////////////////////////////
};
#endif
