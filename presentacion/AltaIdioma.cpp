#include "AltaIdioma.h"

using namespace std;

AltaIdioma::AltaIdioma() {
    this->controlador = Controller::getInstance();
}

AltaIdioma::~AltaIdioma() {
   
}

void AltaIdioma::altaIdioma(){
    string nombreIdioma;
    cout << "Ingrese el nuevo Idioma: ";
    cin >> nombreIdioma;
    this->controlador->altaIdioma(nombreIdioma);
}
