#include "AltaCurso.h"

AltaCurso::AltaCurso()
{
    this->controlador = Controller::getInstance();
}

AltaCurso::~AltaCurso()
{
    // No eliminar el controlador, ya que es un singleton
}

void AltaCurso::altaCurso()
{
    cout << "Bienvenido a Ingresar Curso" << endl;

    string nombreCurso, descripcion, nombreProfe;

    int dificultad = 0;

    cout << "Ingrese nombre del curso: ";
    getline(cin, nombreCurso);
    cout << "Ingrese descripcion: ";
    getline(cin, descripcion);
    cout << "Ingrese dificultad (0 = Principiante. 1 = Medio. 2 = Avanzado.): ";
    cin >> dificultad;

    cout << "Ingrese nombre del profesor: ";
    set<string> nombreProfesores;
    nombreProfesores = this->controlador->listarNombreProfesores();
    cout << "Seleccione un Profesor: ";
    cin.ignore();
    getline(cin, nombreProfe);
    set<string> nombreIdiomas;
    char opcion;

    cout <<"Desea agregar idiomas? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S')
    {
        nombreIdiomas = seleccionarIdiomas();
    }

    Curso *nuevoCurso = this->controlador->ingresaElCurso(nombreCurso, descripcion, dificultad, nombreProfe, nombreIdiomas);

    set<string> nombreCursos;

    cout << "Desea agregar Cursos Previos? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S')
    {
        nombreCursos = seleccionarCursosPrevios();
        this->controlador->seleccionarCursosPrevios(nombreCursos, nuevoCurso);
    }

    cout << "Desea agregar una Leccion? (s/n): ";
    char op;
    cin >> op;

    if (op == 's' || op == 'S')
    {
        do
        {
            agregarLeccion(nuevoCurso);
            cout << "Desea agregar otra Leccion? (s/n): ";
            cin >> op;
        }
        while (op != 'N' && op != 'n');
    }

    nuevoCurso->listarCursosPrevios();

    this->controlador->daDeAltaCurso(nuevoCurso);
}

set<string> AltaCurso::seleccionarIdiomas()
{
    set<string> nombreIdiomas;
    char opcion;

    do {
        cout << "Idiomas disponibles: ";
        set<string> idiomas = this->controlador->listarIdiomas();
        for (auto idioma : idiomas)
        {
            cout << idioma << endl;
        }

        string idiomaSeleccionado;
        cout << "Ingrese el idioma a agregar: ";
        cin >> idiomaSeleccionado;
        nombreIdiomas.insert(idiomaSeleccionado);

        cout << "Desea agregar otro idioma? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return nombreIdiomas;
}

set<string> AltaCurso::seleccionarCursosPrevios()
{
    set<string> nombreCursos;
    char opcion;

    do {
        cout << "Cursos disponibles:\n";
        set<string> cursos = this->controlador->listarCursos();
        for (string curso : cursos)
        {
            cout << curso << endl;
        }

        string cursoSeleccionado;
        cout << "Ingrese el curso a agregar a la lista de previas: ";
        cin.ignore();
        getline(cin, cursoSeleccionado);
        nombreCursos.insert(cursoSeleccionado);

        cout << "Desea agregar otro curso previo? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return nombreCursos;
}

void AltaCurso::agregarLeccion(Curso *curso)
{
    int numero = 0;
    char opcion = 'n';
    string tema, objetivo;

    cout << "Ingrese numero de leccion " << endl;
    cin >> numero;
    cout << "Ingrese tema de leccion " << endl;
    cin >> tema;
    cout << "Ingrese objetivo de leccion " << endl;
    cin >> objetivo;

    Leccion *nuevaLeccion = this->controlador->agregarLeccion(curso, numero, tema, objetivo);

    cout << "Desea agregarle Ejercicios a la Leccion? (s/n) " << endl;
    cin >> opcion;

    if(opcion == 's'){
        while(opcion != 'n'){
            agregarEjercicio(nuevaLeccion);
            cout << "Desea agregarle otro Ejercicio a la Leccion? (s/n) " << endl;
            cin >> opcion;
        }   
    }
}

void AltaCurso::agregarEjercicio(Leccion *leccion)
{

    int num1 = 0;
    string nombreEjercicio, descripcion, fraseA, fraseB;

    cout << "Ingrese el numero 1 para completar palabra o 2 para traducir palabra " << endl;
    cin >> num1;
    if (num1 == 1)
    {
        cout << "Eligio Completar palabra " << endl;
        cout << "Ingrese descripcion " << endl;
        cin >> descripcion;
        cout << "Ingrese la frase, ejemplo \"Mi --- es Javier\" " << endl;
        cin >> fraseA;
        cout << "Ingrese la solucion " << endl;
        cin >> fraseB;
        nombreEjercicio = "Completar Palabra";

        this->controlador->agregarEjercicio(leccion, nombreEjercicio, descripcion, fraseA, fraseB, 1);
    }
    else if (num1 == 2)
    {
        cout << "Eligio Traducir palabra " << endl;
        cout << "Ingrese descripcion " << endl;
        cin >> descripcion;
        cout << "Ingrese la frase a traducir  " << endl;
        cin >> fraseA;
        cout << "Ingrese la solucion " << endl;
        cin >> fraseB;
        nombreEjercicio = "Traducir Palabra";

        this->controlador->agregarEjercicio(leccion, nombreEjercicio, descripcion, fraseA, fraseB, 2);
    }
    else
    {
        cout << "Error, ingreso un numero distinto a 1 o 2" << endl;
        cout << "Ejercicio no agregado" << endl;
    }
}