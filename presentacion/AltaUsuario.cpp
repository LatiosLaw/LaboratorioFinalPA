#include "AltaUsuario.h"

AltaUsuario::AltaUsuario()
{
    this->controlador = Controller::getInstance();
}

AltaUsuario::~AltaUsuario()
{
}

void AltaUsuario::altaUsuario()
{
    string nick;
    cout << "Ingrese nick: ";
    cin >> nick;

    bool existe = this->controlador->verificarNick(nick);
    if (!existe)
    {
        cout << "¿Es estudiante o profesor? (1 estudiante, 2 profesor): " << endl;
        int tipoUsuario;
        cin >> tipoUsuario;

        if (tipoUsuario == 1)
        {
            ingresarEstudiante(nick);
        }
        else
        {
            ingresarProfesor(nick);
        }

        cout << "Fin ingreso de usuario" << endl;
    }
    else
    {
        cout << "Ya existe el usuario. Imposible continuar..." << endl;
    }
}

void AltaUsuario::ingresarEstudiante(string nick)
{
    string pass, nom, descrip, pais;

    cout << "Ingresar pass: ";
    cin >> pass;
    cout << "Ingresar nombre: ";
    cin >> nom;
    cout << "Ingresar descripcion: ";
    cin >> descrip;
    cout << "Ingresar pais: ";
    cin >> pais;

    this->controlador->agregarEstudiante(nick, pass, nom, descrip, pais);
}

void AltaUsuario::ingresarProfesor(string nick)
{
    string pass, nom, descrip, instituto;
    set<string> idiomas;

    cout << "Ingresar pass: ";
    cin >> pass;
    cout << "Ingresar nombre: ";
    cin >> nom;
    cout << "Ingresar descripcion: ";
    cin >> descrip;
    cout << "Ingresar instituto: ";
    cin >> instituto;

    int opcion;
    cout << "¿Desea agregar idiomas? (1=si, 2=no): ";
    cin >> opcion;
    if (opcion == 1)
    {
        idiomas = seleccionarIdiomas();
    }
    this->controlador->agregarProfesor(nick, pass, nom, descrip, instituto, idiomas);
}

set<string> AltaUsuario::seleccionarIdiomas()
{
    set<string> idiomasExistentes = this->controlador->listarIdiomas();
    set<string> idiomasSeleccionados;

    for (string idioma : idiomasExistentes)
    {
        cout << "Idioma: " << idioma << endl;
    }

    string idioma;
    bool quiereIngresarIdiomas = true;
    while (quiereIngresarIdiomas)
    {
        cout << "Ingrese un idioma de la lista: (S/s para salir): ";
        cin >> idioma;
        if (idioma != "S" && idioma != "s")
        {
            if (idiomasExistentes.find(idioma) != idiomasExistentes.end())
            {
                idiomasSeleccionados.insert(idioma);
                cout << "Idioma ingresado: " << idioma << endl;
            }
            else
            {
                cout << "El idioma ingresado no existe" << endl;
            }
        }
        else
        {
            quiereIngresarIdiomas = false;
        }
    }
    return idiomasSeleccionados;
}
