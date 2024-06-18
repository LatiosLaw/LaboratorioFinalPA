#include "../h/Ejercicio.h"

Ejercicio::Ejercicio()
{

}

Ejercicio::Ejercicio(string nombreEjercicio, string descripcion)
{
    this->nombreEjercicio = nombreEjercicio;
    this->descripcion = descripcion;
}
	
Ejercicio::~Ejercicio()
{

}

string Ejercicio::getnombreEjercicio(){
    return this->nombreEjercicio;
}

bool Ejercicio::Pendiente(set<Ejercicio*> aprobados){
for (Ejercicio* ejercicio_aprobado : aprobados)
    {
        if (ejercicio_aprobado->getnombreEjercicio()==this->getnombreEjercicio())
        {
            return true;
            break;
        }
    }
    return false;
}

void Ejercicio::obtenerDataType(){

}