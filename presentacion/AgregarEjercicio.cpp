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
        //Leccion *l = c->buscarLeccion(num); //instanciarlo si se precisa para el if de abajo, y comparar esa l con el nullptr si no funciona

        if (c->buscarLeccion(num) == nullptr) // control que no exista la leccion
        {
            cout << "El numero de la leccion ingresada no existe..." << endl;
            return;
        }

        //DATOS DEL EJ
        cout << "Ingrese el nombre del ejercicio.." << endl;
        cin >> nomE;
        cout << "Ingrese la descripcion del ejercicio.." << endl;
        cin >> descE;

        cout << "Que tipo de ejercicio quieres agregar? /n 1- Completar Palabra  /n 2- Traduccion " << endl;
        cin >> num;
        if (num == 1)
        { // Completar Palabra
            cout << "Ingrese la frase a completar del ejercicio.." << endl;
            cin >> fraseA;
            cout << "Ingrese la frase correcta del ejercicio.." << endl;
            cin >> fraseB;
        }
        else if (num == 2)
        { // Traduccion
            cout << "Ingrese la frase a traducir del ejercicio.." << endl;
            cin >> fraseA;
            cout << "Ingrese la traduccion correcta del ejercicio.." << endl;
            cin >> fraseB;
        }
        else
        {
            cout << "Opcion invalida..." << endl;
            return;
        }
        c->buscarLeccion(num)->agregarEjercicio(nomE,descE,fraseA, string fraseB,num)
        
    }
}
