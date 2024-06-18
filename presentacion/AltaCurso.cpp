#include "AltaCurso.h"

AltaCurso::AltaCurso()
{
    this->controlador = Controller::getInstance();
}

AltaCurso::~AltaCurso()
{
    // No eliminar el controlador, ya que es un singleton
}

void AltaCurso::altaCurso() //faltan varios detalles
{
    cout << "Bienvenido a Ingresar Curso" << endl;
    
    string nombreCurso, descripcion, dificultad, nombreProfe;
    
    cout << "Ingrese nombre del curso: ";
    cin >> nombreCurso;
    cout << "Ingrese descripcion: ";
    cin >> descripcion;
    cout << "Ingrese dificultad: ";
    cin >> dificultad;

    cout << "Ingrese nombre del profesor: ";
    set<string> nombreProfesores;
    nombreProfesores = this->controlador->listarNombreProfesores();
    cout << "Seleccione un Profesor: ";
    cin >> nombreProfe;

    set<string> nombreIdiomas;
    char opcion;

    cout << "¿Desea agregar idiomas? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        nombreIdiomas = seleccionarIdiomas();
    }

    Curso *nuevoCurso = this->controlador->ingresaElCurso(nombreCurso, descripcion, dificultad, nombreProfe, nombreIdiomas);

    set<string> nombreCursos;

    cout << "¿Desea agregar Cursos Previos? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        nombreCursos = seleccionarCursosPrevios();
        this->controlador->seleccionarCursosPrevios(nombreCursos, nuevoCurso);
    }

    

    nuevoCurso->listarCursosPrevios();

    this->controlador->daDeAltaCurso(nuevoCurso);

    //nuevoCurso->listarIdiomasDelCurso();
    //nuevoCurso->listarProfesorDelCurso();

    //cout << endl;

    //this->controlador->listarCursos();
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

        cout << "¿Desea agregar otro idioma? (s/n): ";
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
        for (const string& curso : cursos)
        {
            cout << curso << endl;
        }

        string cursoSeleccionado;
        cout << "Ingrese el curso a agregar a la lista de previas: ";
        cin >> cursoSeleccionado;
        nombreCursos.insert(cursoSeleccionado);

        cout << "¿Desea agregar otro curso previo? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return nombreCursos;
}