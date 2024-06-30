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

    this->controlador->listarNicksEstudiantes();
    
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
