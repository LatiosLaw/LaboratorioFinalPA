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
    string solucion;
    string nombre_ejercicio;
    bool existen_pendientes;
    Estudiante* estudiante;
    set<Ejercicio*> ejercicios_pendientes;
    cout << "Seleccione su nickname de estudiante : " << endl;
    this->controlador->listarNicksEstudiantes();
    getline(cin,nickname_estu);
    estudiante = this->controlador->buscarEstudiante_peroCallao(nickname_estu);
    cout << "Seleccione el curso que quiere continuar : " << endl;
    existen_pendientes = this->controlador->listarCursosPendientesDeAlumno(estudiante);
    if(existen_pendientes==true){
    getline(cin,nombre_curso);
    bool bucle=true;
    int confirmacion=0;
    do{
    cout << "Seleccione el ejercicio que quiere realizar : " << endl;
    Registro *registro = estudiante->buscarRegistroACurso(nombre_curso);
    ejercicios_pendientes = this->controlador->listarEjerciciosPendientesDeCurso(estudiante, registro);
    getline(cin,nombre_ejercicio);
    for(Ejercicio* ejercicio : ejercicios_pendientes){
        if(ejercicio->verificarNombre(nombre_ejercicio)){
            ejercicio->mostrarEjercicio();
            getline(cin,solucion);
            if(ejercicio->enviarSolucion(solucion)){
                registro->aprobar(ejercicio);
                cout << "Ejercicio aprobado!" << endl;
            }else{
                cout << "Error en la sintaxis de la respuesta, no aprobado." << endl;
            }
        }
    }
    cout << "Quiere realizar/reintentar otro ejercicio? (1=si , 2=no)" << endl;
    cin.ignore();
    cin >> confirmacion;
    if(confirmacion==2){
        bucle=false;
    }else{
        bucle=true;
    }
    }while(bucle==true);
    }else{
    cout << "-----------------------------------------------" << endl;
    cout << "El estudiante no cuenta con cursos pendientes." << endl;
    }
}