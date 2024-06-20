#include "ConsultaDeUsuario.h"

ConsultaDeUsuario::ConsultaDeUsuario()
{
    this->controlador = Controller::getInstance();
}

ConsultaDeUsuario::~ConsultaDeUsuario()
{

}

void ConsultaDeUsuario::consultarUsuarios(){
    
    listarNicks();

    string nick;
    cin >> nick;

    this->controlador->listarInformacion(nick);
}

void ConsultaDeUsuario::listarNicks()
{
    set<string> nicks = this->controlador->listarNickNames();

    if (nicks.empty())
    {
        cout << "No hay usuarios en el sistema." << endl;
    }
    else
    {
        cout << "Listando nicknames..." << endl;

        for (auto nick : nicks)
        {
            cout << nick << ",";
        }
        cout << endl << "Seleccione un Usuario: " << endl;
    }
}