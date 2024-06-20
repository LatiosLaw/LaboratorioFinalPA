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
    cout << "6) Consulta de Usuario" << endl;
    cout << "7) Consultar Curso" << endl;
    cout << "8) Siguiente Operacion" << endl;
    cout << "9) Salir" << endl << endl;
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
                ConsultaDeUsuario consulta;
                consulta.consultarUsuarios();
            }
            break;
        case 7:
            {
                ConsultarCurso consultaC;
                consultaC.consultarCurso();
            }
        case 8:
            {
                //siguiente caso de uso
                //NombreCasoDeUso nombrecasodeuso;
                //nombrecasodeuso.nombreCasoDeUso();
            }
            break;
        case 9:
            break;
        default:
            cout << "Opcion desconocida." << endl;
            break;
        }
    } while (opcion != 9);

    cout << "Fin del programa." << endl;
}