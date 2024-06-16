#include "AltaCurso.h"

AltaCurso::AltaCurso()
{
    this->controlador = Controller::getInstance();
}

AltaCurso::~AltaCurso()
{
    // No eliminar el controlador, ya que es un singleton
}

void AltaCurso::altaCurso() //faltan varios detalles
{
    cout << "Bienvenido a Ingresar Curso" << endl;
    
    string nombreCurso, descripcion, dificultad, nombreProfe;
    
    cout << "Ingrese nombre del curso: ";
    cin >> nombreCurso;
    cout << "Ingrese descripcion: ";
    cin >> descripcion;
    cout << "Ingrese dificultad: ";
    cin>>dificultad;
    cout << "Ingrese nombre del profesor: ";
    set<string> nombreProfesores;
    set<string> nombreIdiomas;
    nombreProfesores = this->controlador->listarNombreProfesores();
    cout << "Seleccione un Profesor: ";
    cin >> nombreProfe;

    char opcion;
    do {
        cout << "¿Desea agregar idiomas? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            cout << "Seleccione los idiomas disponibles:\n";
            set<string> idiomas = this->controlador->listarIdiomas();
            for (string idioma : idiomas) {
                cout << idioma << endl;
            }
            
            string idiomaSeleccionado;
            cout << "Ingrese el idioma a agregar: ";
            cin >> idiomaSeleccionado;
            nombreIdiomas.insert(idiomaSeleccionado);
        }
    } while (opcion == 's' || opcion == 'S');
    

    Curso *nuevoCurso = this->controlador->ingresaElCurso(nombreCurso, descripcion, dificultad, nombreProfe, nombreIdiomas);

    this->controlador->daDeAltaCurso(nuevoCurso);

    nuevoCurso->listarIdiomasDelCurso();
    nuevoCurso->listarProfesorDelCurso();

    cout << endl;

    this->controlador->listarCursos();
}

set<string> AltaCurso::seleccionarIdiomas()
{
    set<string> idiomasExistentes = this->controlador->listarIdiomas();
    set<string> idiomasSeleccionados;

    for (string idioma : idiomasExistentes) {
        cout << "Idioma: " << idioma << endl;
    }

    string idioma;
    bool quiereIngresarIdiomas = true;
    while (quiereIngresarIdiomas) {
        cout << "Ingrese un idioma de la lista: (S/s para salir) ";
        cin >> idioma;
        if (idioma != "S" && idioma != "s") {
            if (idiomasExistentes.find(idioma) != idiomasExistentes.end()) {
                idiomasSeleccionados.insert(idioma);
                cout << "Idioma ingresado: " << idioma << endl;
            } else {
                cout << "El idioma ingresado no existe" << endl;
            }
        } else {
            quiereIngresarIdiomas = false;
        }
    }
    return idiomasSeleccionados;
}
