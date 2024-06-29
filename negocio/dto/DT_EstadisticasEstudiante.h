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
	
	string getnombreCurso();
	string getavance();
	void setnombreCurso(string nomcur);
	void setavance(string avan);
	
	virtual ~DT_EstadisticasEstudiante();
};
#endif
