#include "DT_EstadisticasProfesor.h"

DT_EstadisticasProfesor::DT_EstadisticasProfesor(){
	
}

DT_EstadisticasProfesor::DT_EstadisticasProfesor(string nomcur, string avan){
	this->nombreCurso = nomcur;
	this->avance_promedio = avan;
}

DT_EstadisticasProfesor::~DT_EstadisticasProfesor(){
	
}

string DT_EstadisticasProfesor::getnombreCurso(){
return this->nombreCurso;
}

string DT_EstadisticasProfesor::getavance_promedio(){
return this->avance_promedio;
}

void DT_EstadisticasProfesor::setnombreCurso(string nomcur){
this->nombreCurso = nomcur;
}

void DT_EstadisticasProfesor::setavance_promedio(string avan){
this->avance_promedio = avan;
}
