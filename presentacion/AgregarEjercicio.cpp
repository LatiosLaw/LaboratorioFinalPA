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

        // AGREGAR el ejercicio.
        cout << "Que tipo de ejercicio quieres agregar? /n 1- Traduccion /n 2- Completar Palabra" << endl;
        cin >> num;
        // atributos de los ej.
        string nomE;
        string descE;
        string fraseA;
        string fraseB;

        cout << "Ingrese el nombre del ejercicio.." << endl;
        cin >> nomE;
        cout << "Ingrese la descripcion del ejercicio.." << endl;
        cin >> descE;
        if (num == 1)

        { // traduccion

            cout << "Ingrese la frase a traducir del ejercicio.." << endl;
            cin >> fraseA;
            cout << "Ingrese la traduccion correcta del ejercicio.." << endl;
            cin >> fraseB;
        }
        else if (num == 2)
        { // completar palabra

            cout << "Ingrese la frase a completar del ejercicio.." << endl;
            cin >> fraseA;
            cout << "Ingrese la frase correcta del ejercicio.." << endl;
            cin >> fraseB;
        }
        else
        {
            cout << "Opcion invalida..." << endl;
            return;
        }

        
        l->agregarEjercicio(num, nomE, descE, fraseA, fraseB); // agregar leccion responsabilidad de leccion.
    }
}
