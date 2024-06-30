#include "AgregarEjercicio.h"

AgregarEjercicio::AgregarEjercicio(){this->controlador = Controller::getInstance();}
AgregarEjercicio::~AgregarEjercicio(){}

void AgregarEjercicio::agregarEjercicio()
{

    // listamos los cursos no habilitados
    set<string> nombres;
    string nomC;
    nombres = this->controlador->listarCursosNoHabilitados();

    cout << "Cursos no habilitados : " << endl;
    for (auto n : nombres)
    {

        cout << endl
             << n;
    }
    cout << endl;

    // seleccionamos el curso por nombre
    cout << endl
         << "Elije un curso ingresando su nombre..." << endl;
    // leer variable con espacios.
    getline(cin, nomC);
    // limpiar buffer

    Curso *c;
    c = this->controlador->buscarCurso(nomC);

    if (c == nullptr)
    {
        cout << "El curso ingresado no existe" << endl;
        return;
    }

    // si el curso tiene leccioens
    if (c->tieneLecciones() == true)
    {

        // LISTAR LECCIONES DEL CURSO
        set<Leccion *> lecciones = c->obtenerLecciones();

        // dataLeccion ayuda !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        int numL;
        int numOpcion;
        string tema;
        string obj;

        cout << "Lecciones del curso " << nomC << " --- " << endl
             << endl;

        for (auto &&i : lecciones)
        {

            numL = i->getNumero();
            tema = i->getTema();
            obj = i->getObjetivo();

            cout << endl
                 << numL << " - " << tema << " - " << obj;
        }

        cout << endl << "  Selecciona el numero de la leccion la cual quieres agregar el ejercicio.." << endl;
        cin.ignore();
        cin >> numL;
        // Leccion *l = c->buscarLeccion(num); //instanciarlo si se precisa para el if de abajo, y comparar esa l con el nullptr si no funciona

        if (c->buscarLeccion(numL) == nullptr) // control que no exista la leccion
        {
            cout << "El numero de la leccion ingresada no existe..." << endl;
            return;
        }

        // DATOS DEL EJ
        string nomE;
        string descE;
        string fraseA;
        string fraseB;
        cout << "Ingrese el nombre del ejercicio.." << endl;
        cin.ignore();
        cin >> nomE;
        
        cout << "Ingrese la descripcion del ejercicio.." << endl;
        cin.ignore();
        cin >> descE;
        

        cout << "Que tipo de ejercicio quieres agregar? /n 1- Completar Palabra  /n 2- Traduccion " << endl;
        cin.ignore();
        cin >> numOpcion;
        if (numOpcion == 1)
        { // Completar Palabra
            cout << "Ingrese la frase a completar del ejercicio.." << endl;
            cin.ignore();
            getline(cin, fraseA);
            
            cout << "Ingrese la frase correcta del ejercicio.." << endl;
            cin.ignore();
            getline(cin, fraseB);
            
        }
        else if (numOpcion == 2)
        { // Traduccion
            cout << "Ingrese la frase a traducir del ejercicio.." << endl;
            cin.ignore();
            getline(cin, fraseA);
            cout << "Ingrese la traduccion correcta del ejercicio.." << endl;
            cin.ignore();
            getline(cin, fraseB);
        }
        else
        {
            cout << "Opcion invalida..." << endl;
            return;
        }

        c->buscarLeccion(numL)->agregarEjercicio(nomE, descE, fraseA, fraseB, numOpcion);

    }
}
