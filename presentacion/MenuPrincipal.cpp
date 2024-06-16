#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{

}

MenuPrincipal::~MenuPrincipal()
{
	
}

void MenuPrincipal::mostrarMenu()
{
    int opcion;

    do {
        cout << "*** Menu principal ***" << endl;
        cout << "1) Alta Usuario" << endl;
        cout << "2) Alta Idioma" << endl;
        cout << "3) Alta Curso" << endl;
        cout << "4) Siguiente Operacion" << endl;
        cout << "5) Salir" << endl << endl;
        cout << "Ingrese una opcion: ";

        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            {
                AltaUsuario altaUsuario;
                altaUsuario.altaUsuario();
            }
            break;
        case 2:
            {
                AltaIdioma presentacionAltaIdioma;
                presentacionAltaIdioma.altaIdioma();
            }
            break;
        case 3:
            {
                AltaCurso presentacionAltaCurso;
                presentacionAltaCurso.altaCurso();
            }
            break;
        case 4:
            {
                //siguiente caso de uso
                //RealizarEjercicio realizarEjercicio;
                //realizarEjercicio.realizarEjercicio();
            }
            break;
        case 5:
            break;
        default:
            cout << "Opcion desconocida" << endl;
            break;
        }
    } while (opcion != 5);

    cout << "Fin del programa." << endl;
}