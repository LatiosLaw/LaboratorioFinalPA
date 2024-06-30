#include "../h/CompletarPalabra.h"

CompletarPalabra::CompletarPalabra()
{

}

CompletarPalabra::CompletarPalabra(string nomE, string desc, string fraseACompletar, string fraseCorrecta) : Ejercicio(nomE,  desc)
{
    this->fraseACompletar = fraseACompletar;
    this->fraseCorrecta = fraseCorrecta;
}
	
CompletarPalabra::~CompletarPalabra(){

}

string CompletarPalabra::getFrase(){
return this->fraseACompletar;
}

string CompletarPalabra::getFraseCompleta(){
return this->fraseCorrecta;
}

void CompletarPalabra::mostrarEjercicio(){
cout << "Ejercicio : " << this->getnombreEjercicio() << endl;
cout << "Complete las palabras faltantes en la siguiente frase de la siguiente manera 'ejemplo, ejemplo' " << endl;
cout << "Los espacios faltantes seran marcados con guiones." << endl;
cout << "Frase a completar : " << endl;
cout << this->getFrase() << endl;
}

bool CompletarPalabra::enviarSolucion(string solu){
    if(this->getFraseCompleta()==solu){
        return true;
    }else{
        return false;
    }
}