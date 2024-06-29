#ifndef DT_ESTADISTICASCURSO_H
#define DT_ESTADISTICASCURSO_H
#include <iostream>
#include <string>

using namespace std;

enum dificultad{
	principiante, medio, avanzado
};

class DT_EstadisticasCurso{
	
private:
	string nombreCurso;
	string descripcion;
	dificultad dificultadCurso;
	string avance_promedio;
	
public:
	DT_EstadisticasCurso();
	DT_EstadisticasCurso(string nomcur, string descri, dificultad dificu, string avanc);
	
	string getnombreCurso();
	string getavance_promedio();
	string getdescripcion();
	dificultad getdificultadCurso();
	void setnombreCurso(string nomcur);
	void setdescripcion(string descri);
	void setdificultadCurso(dificultad dificu);
	void setavance_promedio(string avanc);
	
	virtual ~DT_EstadisticasCurso();
};
#endif
