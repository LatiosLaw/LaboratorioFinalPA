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

string Ejercicio::getDescripcion(){
    return this->descripcion;
}


string Ejercicio::getnombreEjercicio(){
    return this->nombreEjercicio;
}

bool Ejercicio::Pendiente(set<Ejercicio*> aprobados){
for (Ejercicio* ejercicio_aprobado : aprobados)
    {
        if (ejercicio_aprobado->getnombreEjercicio()==this->getnombreEjercicio())
        {
            return false;
            break;
        }
    }
    return true;
}

Ejercicio *Ejercicio::obtenerDataType()
{
    return this;
}

bool Ejercicio::verificarNombre(string nom){
    if(this->getnombreEjercicio()==nom){
        return true;
    }else{
        return false;
    }
}