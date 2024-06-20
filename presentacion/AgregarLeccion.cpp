#include "AgregarLeccion.h"


AgregarLeccion::AgregarLeccion(){
	this->controlador = Controller::getInstance();
	
}
AgregarLeccion::~AgregarLeccion(){
	
}
void AgregarLeccion::agregarLeccion(){
	
	string nombreCurso;
	string tema;//Data taip p1
	string objetivo;//Data taip p2
	

	cout << endl;
	cout << "Seleccuine el curso al cual le quiere agregar una nueva leccion:" <<endl;
	set <string> listaCursosHab = this->controlador->listarNombreCursosHabilitados();

	
	for (auto curso : listaCursosHab)
	{
		//cout << "Dentro del for" <<endl;
		cout << curso <<endl;
	
	}
	cout << "--------------------------------------------------------" <<endl;
	
	
	
	cin >> nombreCurso;
	cout <<"Ingrese el tema de la Leccion nueva"<<endl;
	cin >> tema;
	cout <<"Ingrese el objetivo de la Leccion nueva"<<endl;
	cin >> objetivo;
	
	Leccion* tokenLec = this->controlador->confirmarDatosAgregarLeccion(nombreCurso,tema,objetivo);
	if(tokenLec == nullptr){
		cout << "No se pudo ingresar de manera correcta, corrobore los datos e eintenet otra vez." <<endl;
	}else{
		cout << "Leccion ingresada correcta mente " <<endl;
		
		cout << "Desea ingresarle a la leccion creada Ejercios?" <<endl;
		cout << "1-Si"<< endl;
		cout << "2-No"<< endl;
		int token;
		cin >> token;
		if(token == 1){
			string nombreEjer;
			string desc;
			int tokenopt;
				while (true){
					cout << "Ingrese nombre para el nuevo ejerciso" <<endl;
					cin >> nombreEjer;
					cout << "Ingrese descripcion para el mismo" <<endl;
					cin >> desc;
					
					tokenLec->crearEjercicio(nombreEjer,desc);
					
					cout << "Desea continuar agregando ejercicios?" <<endl;
					cout << "1-Si" <<endl;
					cout << "2-No" <<endl;
					
					cin >> tokenopt;
					
					if(tokenopt == 2){
						break;
					}
				}
		}
		
		
		
	}
}
