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

void Leccion::agregarEjercicio(string nombreEjercicio, string descripcion, string fraseA, string fraseB, int opcion)
{

    if (opcion == 1)
    {
        Ejercicio *ejercicio = new CompletarPalabra(nombreEjercicio, descripcion, fraseA, fraseB);
        cout << "Ejercicio Creado Exitosamente " << endl;
        ListaEjercicios.insert(ejercicio);
        cout << "Ejercicio Agregado a la lista" << endl;
    }
    else if (opcion == 2)
    {
        Ejercicio *ejercicio = new Traduccion(nombreEjercicio, descripcion, fraseA, fraseB);
        cout << "Ejercicio Creado Exitosamente " << endl;
        ListaEjercicios.insert(ejercicio);
        cout << "Ejercicio Agregado a la lista" << endl;
    }
    else
    {
        cout << "Tipo de ejercicio no reconocido" << endl;
    }
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