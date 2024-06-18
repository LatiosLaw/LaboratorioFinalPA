#include "RealizarEjercicio.h"

//Falta pasar las operaciones al controlador principal, haré eso según tenga idea de los retornos y demás.

RealizarEjercicio::RealizarEjercicio()
{
    this->controlador = Controller::getInstance();
}

RealizarEjercicio::~RealizarEjercicio()
{
    // No eliminar el controlador, ya que es un singleton
}

void RealizarEjercicio::realizarEjercicio()
{
    string nickname_estu;
    cout << "Seleccione su nickname de estudiante : " << endl;
    this->controlador->listarNicksEstudiantes();
    cin >> nickname_estu;
    cout << "Seleccione el curso que quiere continuar : " << endl;
    this->controlador->listarCursosPendientesDeAlumno(nickname_estu);
    
    cout << "Final de la Demo - Work In Progress" << endl;
}