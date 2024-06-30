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
    int eleccion = 0;
    string busqueda;
    cout << "Seleccione que tipo de estadisticas quiere ver. (1=Estudiante, 2=Profesor, 3=Curso)" << endl;
    cin >> eleccion;
    if (eleccion == 1)
    {
        Estudiante *estudiante_elegido;
        controlador->nicksEstudiantes();
        cout << "Seleccione el nickname de un estudiante : " << endl;
        cin.ignore();
        getline(cin, busqueda);
        estudiante_elegido = controlador->buscarEstudiante(busqueda);
        if (estudiante_elegido != nullptr)
        {
            set<DT_EstadisticasEstudiante *> estadisticas_e;
            estadisticas_e = estudiante_elegido->estadisticasEstudiante();
            cout << "Estadisticas del Estudiante : " << endl;
            for (DT_EstadisticasEstudiante *stat : estadisticas_e)
            {
                stat->mostrarDatos();
            }
        }
        else
        {
            cout << "Error de sintaxis." << endl;
        }
        system("pause"); 
    }
    else if (eleccion == 2)
    {
        Profesor *profesor_elegido;
        controlador->nicksProfesores();
        cout << "Seleccione el nickname de un profesor : " << endl;
        cin.ignore();
        getline(cin, busqueda);
        profesor_elegido = controlador->buscarProfesor2(busqueda);
        if (profesor_elegido != nullptr)
        {
            set<DT_EstadisticasProfesor *> estadisticas_p;
            estadisticas_p = profesor_elegido->estadisticasProfesor();
            cout << "Estadisticas del Profesor : " << endl;
            for (DT_EstadisticasProfesor *stat : estadisticas_p)
            {
                stat->mostrarDatos();
            }
        }
        else
        {
            cout << "Error de sintaxis." << endl;
        }
        system("pause"); 
    }
    else if (eleccion==3)
    {
        Curso *curso_elegido;
        controlador->nombresCursos();
        cout << "Seleccione el nombre de un curso : " << endl;
        cin.ignore();
        getline(cin, busqueda);
        curso_elegido = controlador->buscarCurso(busqueda);
        if (curso_elegido != nullptr)
        {
            DT_EstadisticasCurso *estadisticas_c;
            estadisticas_c = curso_elegido->estadisticasCurso();
            cout << "Estadisticas del Curso : " << endl;
            estadisticas_c->mostrarDatos();
        }
        else
        {
            cout << "Error de sintaxis." << endl;
        }
        system("pause"); 
    }
}