#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{

}

MenuPrincipal::~MenuPrincipal()
{
	
}

void MenuPrincipal::mostrarOpciones()
{
    cout << endl;
    cout << "*** Menu principal ***" << endl <<endl;
    cout << "1) Cargar Datos" << endl;
    cout << "2) Alta Usuario" << endl;
    cout << "3) Alta Idioma" << endl;
    cout << "4) Alta Curso" << endl;
    cout << "5) Inscribirse al Curso" << endl;
    cout << "6) Realizar Ejercicio" << endl;
    cout << "7) Consulta de Usuario" << endl;
    cout << "8) Consultar Curso" << endl;
    cout << "9) Habilitar Curso" << endl;
    cout << "10) Siguiente Operacion" << endl;
    cout << "11) Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void MenuPrincipal::mostrarMenu()
{
    int opcion;

    do {
        
        mostrarOpciones();
        
        cin >> opcion;
        cout << endl;

        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            {
                Controller *c = Controller::getInstance();
                c->inicializarDatos();
            }
            break;
        case 2:
            {
                AltaUsuario pAltaUsuario;
                pAltaUsuario.altaUsuario();
            }
            break;
        case 3:
            {
                AltaIdioma pAltaIdioma;
                pAltaIdioma.altaIdioma();
            }
            break;
        case 4:
            {
                AltaCurso pAltaCurso;
                pAltaCurso.altaCurso();
            }
            break;
        case 5:
            {
               InscribirseAlCurso pInscribirseAlCurso;
               pInscribirseAlCurso.inscribirse();
            }
            break;
        case 6:
            {
                RealizarEjercicio realizarEjercicio;
                realizarEjercicio.realizarEjercicio();
            }
            break;
        case 7:
            {
                ConsultaDeUsuario consulta;
                consulta.consultarUsuarios();
            }
            break;
        case 8:
            {
                ConsultarCurso consultaC;
                consultaC.consultarCurso();
            }
        case 9:
            {
                HabilitarCurso habilitarCurso;
                habilitarCurso.habilitar();
            }
	case 10:
            {
                //siguiente caso de uso
                //NombreCasoDeUso nombrecasodeuso;
                //nombrecasodeuso.nombreCasoDeUso();
            }
            break;
        case 11:
            break;
        default:
            cout << "Opcion desconocida." << endl;
            break;
        }
    } while (opcion != 10);

    cout << "Fin del programa." << endl;
}
