#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{

}

MenuPrincipal::~MenuPrincipal()
{
	
}

void MenuPrincipal::mostrarOpciones()
{
    cout << "*** Menu principal ***" << endl <<endl;
    cout << "1) Alta Usuario" << endl;
    cout << "2) Alta Idioma" << endl;
    cout << "3) Alta Curso" << endl;
    cout << "4) Inscribirse al Curso" << endl;
    cout << "5) Realizar Ejercicio" << endl;
    cout << "6) Siguiente Operacion" << endl;
    cout << "7) Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
}

void MenuPrincipal::mostrarMenu()
{
    int opcion;

    do {
        
        mostrarOpciones();

        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1:
            {
                AltaUsuario pAltaUsuario;
                pAltaUsuario.altaUsuario();
            }
            break;
        case 2:
            {
                AltaIdioma pAltaIdioma;
                pAltaIdioma.altaIdioma();
            }
            break;
        case 3:
            {
                AltaCurso pAltaCurso;
                pAltaCurso.altaCurso();
            }
            break;
        case 4:
            {
               InscribirseAlCurso pInscribirseAlCurso;
               pInscribirseAlCurso.inscribirse();
            }
            break;
        case 5:
            {
                RealizarEjercicio realizarEjercicio;
                realizarEjercicio.realizarEjercicio();
            }
            break;
        case 6:
            {
                //siguiente caso de uso
                //NombreCasoDeUso nombrecasodeuso;
                //nombrecasodeuso.nombreCasoDeUso();
            }
            break;
		case 100:
		{
			AgregarLeccion agregarLeccion;
			agregarLeccion.agregarLeccion();
			
		}
		break;	
			
			
			
        case 7:
            break;
        default:
            cout << "Opcion desconocida." << endl;
            break;
        }
    } while (opcion != 7);

    cout << "Fin del programa." << endl;
}
