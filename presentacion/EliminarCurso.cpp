#include "EliminarCurso.h"



EliminarCurso::EliminarCurso(){
	this->controlador = Controller::getInstance();
	
}
EliminarCurso::~EliminarCurso(){
	cout << "Are you ok? Hee hee." <<endl;
}
void EliminarCurso::eliminarCurso(){
	string nombreCurso;
	cout << endl;
	cout << "Seleccuine el curso al cual quiere eliminar del mapa" <<endl;
	set <string> listaCursosHab = this->controlador->listarNombreCursosHabilitados();
	
	//cout << "autfor"<<endl;
	for (auto curso : listaCursosHab)
	{
		//cout << "Dentro del for" <<endl;
		//cout << "infor"<<endl;
		cout << curso <<endl;
		
	}
	cout << "--------------------------------------------------------" <<endl;
	//cin.ignore();
	getline(cin,nombreCurso);
	
	this->controlador->eliminarCursoYsusDerivados(nombreCurso);
	
	
	
	
	
}

