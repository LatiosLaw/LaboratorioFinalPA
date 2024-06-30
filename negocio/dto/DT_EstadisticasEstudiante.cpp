#include "DT_EstadisticasEstudiante.h"

DT_EstadisticasEstudiante::DT_EstadisticasEstudiante(){
	
}

DT_EstadisticasEstudiante::DT_EstadisticasEstudiante(string nomcur, string avan){
	this->nombreCurso = nomcur;
	this->avance = avan;
}

DT_EstadisticasEstudiante::~DT_EstadisticasEstudiante(){
	
}

void DT_EstadisticasEstudiante::mostrarDatos(){
cout << "Nombre del Curso : " << this->nombreCurso << " , Avance en el Curso : " << this->avance << endl; 
}
