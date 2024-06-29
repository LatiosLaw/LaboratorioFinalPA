#include "DT_EstadisticasCurso.h"

DT_EstadisticasCurso::DT_EstadisticasCurso(){
	
}

DT_EstadisticasCurso::DT_EstadisticasCurso(string nomcur, string descri, dificultad dificu, string avanc){
	this->nombreCurso = nomcur;
	this->descripcion = descri;
	this->dificultadCurso = dificu;
	this->avance_promedio = avanc;
}

DT_EstadisticasCurso::~DT_EstadisticasCurso(){
	
}

string DT_EstadisticasCurso::getnombreCurso(){
return this->nombreCurso;
}

string DT_EstadisticasCurso::getavance_promedio(){
return this->avance_promedio;
}

string DT_EstadisticasCurso::getdescripcion(){
return this->descripcion;
}

dificultad DT_EstadisticasCurso::getdificultadCurso(){
return this->dificultadCurso;
}

void DT_EstadisticasCurso::setnombreCurso(string nomcur){
this->nombreCurso = nomcur;
}

void DT_EstadisticasCurso::setdescripcion(string descri){
this->descripcion = descri;
}

void DT_EstadisticasCurso::setdificultadCurso(dificultad dificu){
this->dificultadCurso = dificu;
}

void DT_EstadisticasCurso::setavance_promedio(string avanc){
this->avance_promedio = avanc;
}