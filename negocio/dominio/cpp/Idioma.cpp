#include "../h/Idioma.h"

Idioma::Idioma() {
	
}

Idioma::Idioma(string nombre) {
	nombreIdioma = nombre;
}

string Idioma::getNombreIdioma() {
	return nombreIdioma;
}

void Idioma::setNombreIdioma(string nombre) {
	nombreIdioma = nombre;
}

Idioma* Idioma::seleccionarIdioma() {
	cout << "Idioma seleccionado" << endl;
	return this;
}
