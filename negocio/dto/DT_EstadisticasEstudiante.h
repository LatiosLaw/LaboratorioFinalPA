#ifndef DT_ESTADISTICASESTUDIANTE_H
#define DT_ESTADISTICASESTUDIANTE_H
#include <iostream>
#include <string>

using namespace std;

class DT_EstadisticasEstudiante{
	
private:
	string nombreCurso;
	string avance;
	
public:
	DT_EstadisticasEstudiante();
	DT_EstadisticasEstudiante(string nomcur, string avan);
	
	void mostrarDatos();

	virtual ~DT_EstadisticasEstudiante();
};
#endif