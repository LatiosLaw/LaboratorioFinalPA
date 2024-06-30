#ifndef DT_ESTADISTICASPROFESOR_H
#define DT_ESTADISTICASPROFESOR_H
#include <iostream>
#include <string>

using namespace std;

class DT_EstadisticasProfesor{
	
private:
	string nombreCurso;
	string avance_promedio;
public:
	DT_EstadisticasProfesor();
	DT_EstadisticasProfesor(string nomcur, string avan_prom);
	
	void mostrarDatos();
	
	virtual ~DT_EstadisticasProfesor();
};
#endif
