#include "DT_EstadisticasProfesor.h"

DT_EstadisticasProfesor::DT_EstadisticasProfesor(){
	
}

DT_EstadisticasProfesor::DT_EstadisticasProfesor(string nomcur, string avan){
	this->nombreCurso = nomcur;
	this->avance_promedio = avan;
}

DT_EstadisticasProfesor::~DT_EstadisticasProfesor(){
	
}

void DT_EstadisticasProfesor::mostrarDatos(){
cout << "Nombre del Curso : " << this->nombreCurso << " , Avance Promedio en el Curso : " << this->avance_promedio << endl; 
}
