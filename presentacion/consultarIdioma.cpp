#include "consultarIdioma.h"

consultarIdioma::consultarIdioma()
{
    this->controlador = Controller::getInstance();
}

consultarIdioma::~consultarIdioma()
{

}

void consultarIdioma::listarIdomas()
{

	set<string> idiomas = this->controlador->listarIdiomas();
	
	if (idiomas.empty())
	{
		cout << "No hay idiomas en el sistema." << endl;
	}
	else
	{
		cout << "Listando idiomas..." << endl;
		int i = 0;
		for (auto idioma : idiomas)
		{
			i++;
			cout << i << "-" << idioma << endl;
		}
	}
	
	
	
	
}
