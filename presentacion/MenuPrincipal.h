#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_
#include "AltaUsuario.h" //Aqui hay que incluir la Presentacion de los Casos de Uso
#include "AltaIdioma.h"
#include "AltaCurso.h"
#include "RealizarEjercicio.h"
#include "InscribirseAlCurso.h"
#include "ConsultaDeUsuario.h"
#include "HabilitarCurso.h"
#include "ConsultarCurso.h"
#include "AgregarLeccion.h"
#include <iostream>

using namespace std;

class MenuPrincipal {

public:
	MenuPrincipal();
	virtual ~MenuPrincipal();
	void mostrarOpciones();
	void mostrarMenu();
};

#endif /* MENUPRINCIPAL_H_ */
