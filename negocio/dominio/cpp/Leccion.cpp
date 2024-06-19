#include "../h/Leccion.h"

Leccion::Leccion()
{
}

Leccion::Leccion(int numero, string tema, string objetivo)
{
    this->numero = numero;
    this->tema = tema;
    this->objetivo = objetivo;
}

Leccion::~Leccion()
{
}

int Leccion::getNumero()
{
    return this->numero;
    // para no agregar esto si que le temias a la pala XD
}

bool Leccion::Pendiente(set<Ejercicio *> aprobados)
{
    for (Ejercicio* ejercicio : ListaEjercicios)
    {
        if (ejercicio->Pendiente(aprobados))
        {
            return true;
            break;
        }
    }
    return false;
}

set<Ejercicio*> Leccion::buscarEjerciciosPendientes(set<Ejercicio*>aprobados)
{
    set<Ejercicio*>ejerciciosPendientes;
    for (Ejercicio* ejercicio : ListaEjercicios)
    {
        if (ejercicio->Pendiente(aprobados))
        {
            ejerciciosPendientes.insert(ejercicio->obtenerDataType());
        }
    }
    return ejerciciosPendientes;
}