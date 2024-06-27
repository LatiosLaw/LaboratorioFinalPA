#include "AgregarEjercicio.h"

AgregarEjercicio::AgregarEjercicio()
{
    this->controlador = Controller::getInstance();
}

AgregarEjercicio::~AgregarEjercicio() {}

void AgregarEjercicio::agregarEjercicio()
{

    // listamos los cursos no habilitados
    set<string> nombres;
    string nomC;
    nombres = this->controlador->listarCursosNoHabilitados();

    for (auto n : nombres)
    {

        cout << endl << n;
    }

    cout << endl << "Elije un curso.." << endl;
    cin >> nomC;

    Curso *c;
    c = this->controlador->buscarCurso(nomC);

    if (c == nullptr){
        cout << "El curso ingresado no existe" << endl;
        return;
    }

    if (c->tieneLecciones() == true)
    {

        // LISTAR LECCIONES DEL CURSO
        set<Leccion *> lecciones = c->obtenerLecciones();

        // dataLeccion ayuda !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        int num;
        string tema;
        string obj;

        cout << "Lecciones del curso " << nomC << " --- " << endl << endl;

        for (auto &&i : lecciones)
        {

            num = i->getNumero();
            tema = i->obtenerTema();
            obj = i->obtenerObjetivo();

            cout << endl
                 << num << " - " << tema << " - " << obj;
        }

        cout << "Selecciona el numero de la leccion la cual quieres agregar el ejercicio.." << endl;
        cin >> num;
        Leccion *l = c->buscarLeccion(num); // obtener la leccion

        if (l == nullptr) // control que no este vacio.
        {
            cout << "El numero de la leccion ingresada no existe..." << endl;
            return;
        }

    }
}
