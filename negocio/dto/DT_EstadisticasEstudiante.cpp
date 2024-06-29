#include "DT_EstadisticasEstudiante.h"

DT_EstadisticasEstudiante::DT_EstadisticasEstudiante(){
	
}

DT_EstadisticasEstudiante::DT_EstadisticasEstudiante(string nomcur, string avan){
	this->nombreCurso = nomcur;
	this->avance = avan;
}

DT_EstadisticasEstudiante::~DT_EstadisticasEstudiante(){
	
}

string DT_EstadisticasEstudiante::getnombreCurso(){
return this->nombreCurso;
}

string DT_EstadisticasEstudiante::getavance(){
return this->avance;
}

void DT_EstadisticasEstudiante::setnombreCurso(string nomcur){
this->nombreCurso = nomcur;
}

void DT_EstadisticasEstudiante::setavance(string avan){
this->avance = avan;
}
