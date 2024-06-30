#include "ConsultarCurso.h"

ConsultarCurso::ConsultarCurso()
{
    this->controlador = Controller::getInstance();
}

ConsultarCurso::~ConsultarCurso()
{

}

void ConsultarCurso::consultarCurso()
{

    listarCursos();

    string nombreCurso;
    getline(cin, nombreCurso);

    this->controlador->listarInfoCurso(nombreCurso);
}

void ConsultarCurso::listarCursos()
{
    set<string> cursos = this->controlador->listarCursos();

    if (cursos.empty())
    {
        cout << "No hay cursos en el sistema." << endl;
    }
    else
    {
        cout << "Listando cursos..." << endl;
		
        for (auto curso : cursos)
        {
            cout <<  "-" << curso << endl;;
        }
        cout << endl << "Seleccione un Curso: ";
    }
}
