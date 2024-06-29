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
    cout << "*** Menu principal ***" << endl << endl;
    cout << "1) Cargar Datos" << endl;
    cout << "2) Alta Usuario" << endl;
    cout << "3) Alta Idioma" << endl;
    cout << "4) Alta Curso" << endl;
    cout << "5) Agregar Leccion" << endl;
    cout << "6) Inscribirse al Curso" << endl;
    cout << "7) Realizar Ejercicio" << endl;
    cout << "8) Consulta de Usuario" << endl;
    cout << "9) Consultar Curso" << endl;
    cout << "10) Habilitar Curso" << endl;
    cout << "11) Siguiente Operacion" << endl;
    cout << "12) Salir" << endl << endl;
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
			    AgregarLeccion agregarLeccionn;
			    agregarLeccionn.agregarLeccion();
		    }
        case 6:
            {
                InscribirseAlCurso pInscribirseAlCurso;
                pInscribirseAlCurso.inscribirse();
            }
            break;
        case 7:
            {
                RealizarEjercicio realizarEjercicio;
                realizarEjercicio.realizarEjercicio();
            }
            break;
        case 8:
            {
                ConsultaDeUsuario consulta;
                consulta.consultarUsuarios();
            }
            break;
        case 9:
            {
                ConsultarCurso consultaC;
                consultaC.consultarCurso();
            }
            break;
        case 10:
            {
                HabilitarCurso habilitarCurso;
                habilitarCurso.habilitar();
            }
            break;
		case 11:
			{
                AgregarEjercicio agregarEjercicio;
                agregarEjercicio.agregarEjercicio();
				//Sampletext
			}
			break;
		case 12:
			break;
        default:
            cout << "Opcion desconocida." << endl;
            break;
        }
    } while (opcion != 12);

    cout << "Fin del programa." << endl;
}
