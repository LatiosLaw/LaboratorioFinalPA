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
    string nombre_curso;
    string nombre_ejercicio;
    bool existen_pendientes;
    Estudiante* estudiante;
    cout << "Seleccione su nickname de estudiante : " << endl;
    this->controlador->listarNicksEstudiantes();
    cin >> nickname_estu;
    estudiante = this->controlador->buscarEstudiante(nickname_estu);
    cout << "Seleccione el curso que quiere continuar : " << endl;
    existen_pendientes = this->controlador->listarCursosPendientesDeAlumno(nickname_estu);
    if(existen_pendientes==true){
    cin >> nombre_curso;
    cout << "Seleccione el ejercicio que quiere realizar : " << endl;
    this->controlador->listarEjerciciosPendientesDeCurso(nombre_curso, estudiante);
    cin >> nombre_ejercicio;
    }else{
    cout << "Vos sabes que el estudiante esta re-zarpado y no tiene na' pa' hacer." << endl;
    }
    cout << "Final de la Demo - Work In Progress" << endl;
}