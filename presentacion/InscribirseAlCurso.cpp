#include "InscribirseAlCurso.h"

InscribirseAlCurso::InscribirseAlCurso()
{
    this->controlador = Controller::getInstance();
}

InscribirseAlCurso::~InscribirseAlCurso()
{

}

void InscribirseAlCurso::inscribirse() //en proceso
{
    cout << "Bienvenido a Inscribirse a Curso" << endl;
    
    cout << "Ingrese nickname del estudiante: ";
    string nickname;
    cin >> nickname;

    set<string> cursosDisponibles;

    cursosDisponibles = this->controlador->listarCursosDisponibles(nickname);

    cout << "Curso disponibles: ";

    for(auto curso : cursosDisponibles)
    {
        cout << curso << ", ";
    }
    cout << endl << "Ingrese nombre del curso: ";
    string nombreCurso;
    cin.ignore();
    getline(cin, nombreCurso);

    this->controlador->inscribirseACurso(nombreCurso, nickname);
}
/*
set<string> InscribirseAlCurso::listarCursosDisponibles()
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
        cin >> cursoSeleccionado;
        nombreCursos.insert(cursoSeleccionado);

        cout << "Desea agregar otro curso previo? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return nombreCursos;
}
*/