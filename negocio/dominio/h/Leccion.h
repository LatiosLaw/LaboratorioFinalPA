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

	// Metodos de los casos de Martin, faltan retornos y parametros

	int getNumero(); // Esto es un getter, por lo que no es realmente solo mio XD
	bool Pendiente(set<Ejercicio*> aprobados);
<<<<<<< Updated upstream
	set<Ejercicio*> buscarEjerciciosPendientes(set<Ejercicio*>aprobados); // Esto requiere una lista de ejercicios

=======
	void buscarEjerciciosPendientes(); // Esto requiere una lista de ejercicios
	void crearEjercicio(string nombreEjer,string desc);
	string getObjetivo();
	string getTema();
>>>>>>> Stashed changes
	///////////////////////////////////////////////////////////////
};
#endif
