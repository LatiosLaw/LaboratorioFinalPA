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
	
	string getnombreCurso();
	string getavance_promedio();
	void setnombreCurso(string nomcur);
	void setavance_promedio(string avan);
	
	virtual ~DT_EstadisticasProfesor();
};
#endif
