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
	//cout << "DESTRUCTOR DE LECCION" <<endl;
}

int Leccion::getNumero()
{
    return this->numero;
    // para no agregar esto si que le temias a la pala XD
}

string Leccion::getTema()
{
    return this->tema;
}

string Leccion::getObjetivo()
{
    return this->objetivo;
}

void Leccion::mostrarInfoEjercicio()
{
    if (ListaEjercicios.empty())
    {
        cout << "Esta leccion no tiene ejercicios." << endl;
    }
    else
    {
        cout << "Ejercicios: " << endl;
        for (auto ejercicio : ListaEjercicios)
        {
            cout << "Descripcion: " << ejercicio->getDescripcion() << endl;
        }
    }
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
	if(yaExisteEj(nombreEjercicio) == false){
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
		
	}else{
		cout <<"No se pudo agregar ejercicio porque ya existe uno con el mismo nombre en esta leccion"<<endl;
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

set<Ejercicio*> Leccion::retornarEjercicios(){
set<Ejercicio*>ejercicios;
    for (Ejercicio* ejercicio : ListaEjercicios)
    {
            ejercicios.insert(ejercicio);
    }
    return ejercicios;
}

set<Ejercicio*> Leccion::obtenerEjercicios(){
return this->ListaEjercicios;
}

void Leccion:: nukearEejers(){
	
	for (Ejercicio *lista : ListaEjercicios)
	{
		ListaEjercicios.erase(lista);
		lista->solonggaybowser();
		
	}
	
}
void Leccion::chao(){
	delete this;
}

bool Leccion::yaExisteEj(string nomE)
{

    for (auto &&i : this->ListaEjercicios)
    {
        if (i->getnombreEjercicio() == nomE)
        {

            return true;
        }
    }
    return false;
}
