#ifndef DT_ESTADISTICASCURSO_H
#define DT_ESTADISTICASCURSO_H
#include <iostream>
#include <string>
#include "../dominio/h/dificultad.h"

using namespace std;

class DT_EstadisticasCurso{
	
private:
	string nombreCurso;
	string descripcion;
	dificultad dificultadCurso;
	string avance_promedio;
	
public:
	DT_EstadisticasCurso();
	DT_EstadisticasCurso(string nomcur, string descri, dificultad dificu, string avanc);
	void mostrarDatos();
	string mostrardificultad();
	virtual ~DT_EstadisticasCurso();
};
#endif
