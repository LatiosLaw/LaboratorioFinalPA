#include "../h/Fecha.h"

Fecha::Fecha(){
	
}

Fecha::Fecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

Fecha::~Fecha(){
	
}

int Fecha::getDia(){
	return this->dia;
}

int Fecha::getMes(){
	return this->mes;
}

int Fecha::getAnio(){
	return this->anio;
}

void Fecha::setDia(int dia){
	this->dia = dia;
}

void Fecha::setMes(int mes){
	this->mes = mes;
}

void Fecha::setAnio(int anio){
	this->anio = anio;
}
