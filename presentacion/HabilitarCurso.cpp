#include "HabilitarCurso.h"

// Made by Jesus-.

// constructor
HabilitarCurso::HabilitarCurso()
{
    this->controlador = Controller::getInstance();
}

// destructor
HabilitarCurso::~HabilitarCurso()
{
}

void HabilitarCurso::habilitar()
{
    set<string> nombres;
    nombres = this->controlador->listarCursosNoHabilitados();
    cout << endl;
    for (auto n : nombres)
    {
        cout << n << endl;
    }

    string nn;
    cout << "Ingrese el nombre del curso a Habilitar..." << endl;
    cin >> nn ;


    this->controlador->habilitarCurso(nn);

}
