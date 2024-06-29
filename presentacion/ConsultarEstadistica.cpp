#include "ConsultarEstadistica.h"

//Falta pasar las operaciones al controlador principal, haré eso según tenga idea de los retornos y demás.

ConsultarEstadistica::ConsultarEstadistica()
{
    this->controlador = Controller::getInstance();
}

ConsultarEstadistica::~ConsultarEstadistica()
{
    // No eliminar el controlador, ya que es un singleton
}

void ConsultarEstadistica::consultarEstadisticas(){
    int eleccion=0;
    string busqueda;
    cout << "Coso (1=estudiante, 2=curso, 3=profesor)" << endl;
    cin.ignore();
    cin >> eleccion;
        if(eleccion==1){
            Estudiante* estudiante_elegido;
            controlador->nicksEstudiantes();
            cout << "Seleccione el nickname de un estudiante : " << endl;
            getline(cin,busqueda);
            estudiante_elegido = controlador->buscarEstudiante(busqueda);
            //Pedirle al estudiante retornar todos los cursos a los que esta inscrito y su avance en cada uno, esto es un DT
        }else if(eleccion==2){
            Profesor* profesor_elegido;
            controlador->nicksProfesores();
            cout << "Seleccione el nickname de un profesor : " << endl;
            getline(cin,busqueda);
            profesor_elegido = controlador->buscarProfesor(busqueda);
        }else{
            Curso* curso_elegido;
            controlador->nombresCursos();
            cout << "Seleccione el nombre de un curso : " << endl;
            getline(cin,busqueda);
            curso_elegido = controlador->buscarCurso(busqueda);
        }
}

void ConsultarEstadistica::ElegirEstudiante(){

}

void ConsultarEstadistica::ElegirCurso(){

}

void ConsultarEstadistica::ElegirProfesor(){
    
}