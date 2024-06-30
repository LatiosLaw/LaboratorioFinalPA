#include "../h/Traduccion.h"

Traduccion::Traduccion()
{

}
	
Traduccion::Traduccion(string nombreE, string desc, string fraseT, string traduccion) : Ejercicio(nombreE,  desc)
{   
    this->fraseATraducir = fraseT;
    this->traduccionCorrecta = traduccion;
}
	
Traduccion::~Traduccion()
{

}

string Traduccion::getFrase(){
return this->fraseATraducir;
}

string Traduccion::getTraduccionCorrecta(){
return this->traduccionCorrecta;
}

void Traduccion::mostrarEjercicio(){
cout << "Ejercicio : " << this->getnombreEjercicio() << endl;
cout << "Traduzca la siguiente frase a idioma español." << endl;
cout << "Frase a traducir : " << endl;
cout << this->getFrase() << endl;
}

bool Traduccion::enviarSolucion(string solu){
    if(this->getTraduccionCorrecta()==solu){
        return true;
    }else{
        return false;
    }
}