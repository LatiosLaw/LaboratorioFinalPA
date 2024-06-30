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

void DT_EstadisticasCurso::mostrarDatos(){
cout << "Nombre del Curso : " << this->nombreCurso << " , Descripcion del Curso : " << this->descripcion << " , Dificultad del Curso : " << this->mostrardificultad() << " , Avance Promedio en el Curso : " << this->avance_promedio << endl; 
}

string DT_EstadisticasCurso::mostrardificultad()
{
	if (dificultadCurso == dificultad::principiante)
	{
		return "Principiante";
	}
	else if (dificultadCurso == dificultad::media)
	{
		return "Medio";
	}
	else
	{
		return "Avanzado";
	}
}
