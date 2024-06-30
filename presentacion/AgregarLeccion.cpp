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
	
	
	
	getline(cin,nombreCurso);
	cout <<"Ingrese el tema de la Leccion nueva"<<endl;
	getline(cin,tema);
	cout <<"Ingrese el objetivo de la Leccion nueva"<<endl;
	getline(cin,objetivo);
	Leccion* tokenLec = this->controlador->confirmarDatosAgregarLeccion(nombreCurso,tema,objetivo);
	if(tokenLec == nullptr){
		cout << "No se pudo ingresar de manera correcta, corrobore los datos e eintenet otra vez." <<endl;
	}else{
		cout << "Leccion ingresada correctamente " <<endl;
		
		cout << "Desea ingresarle a la leccion creada Ejercios?" <<endl;
		cout << "1-Si"<< endl;
		cout << "2-No"<< endl;
		int token;
		cin >> token;
		cin.ignore();
		switch (token) {
		case 1:
		{
			string nombreEjer;
			string desc;
			string fraseA;
			string fraseB;
			int num;
			int tokenopt;
			while (true){
				cout << "Que tipo de ejercicio quieres agregar?"<< endl << "1- Completar Palabra " << endl << "2- Traduccion " << endl;
				//cin.ignore();
				cin >> num;
				cout << "Ingrese nombre para el nuevo ejerciso" <<endl;
				cin.ignore();
				getline(cin,nombreEjer);
				cout << "Ingrese descripcion para el mismo" <<endl;
				cin.ignore();
				getline(cin,desc);
				if (num == 1)
				{ // Completar Palabra
					cout << "Ingrese la frase a completar del ejercicio.." << endl;
					cin.ignore();
					getline(cin,fraseA);
					cout << "Ingrese la frase correcta del ejercicio.." << endl;
					
					getline(cin,fraseB);
				}
				
				else if (num == 2)
				{ // Traduccion
					cout << "Ingrese la frase a traducir del ejercicio.." << endl;
					cin.ignore();
					getline(cin,fraseA);
					cout << "Ingrese la traduccion correcta del ejercicio.." << endl;
					cin.ignore();
					getline(cin,fraseB);
				}
				else
				{
					cout << "Opcion invalida..." << endl;
					return;
				}
				
				tokenLec->agregarEjercicio(nombreEjer, desc, fraseA, fraseB, num);
				
				cout << "Desea continuar agregando ejercicios?" <<endl;
				cout << "1-Si" <<endl;
				cout << "2-No" <<endl;
				
				cin >> tokenopt;
				
				if(tokenopt != 1){
					if(tokenopt != 2){
						cout << "Opt incorrecta saliendo del sub menu" <<endl;
					}
					break;
				}
			}
		}
		break;
		default:
		{
			cout << "Opt incorrecta saliendo del sub menu" <<endl;
			break;
		}
		
		
		
		}
	}

		
}
