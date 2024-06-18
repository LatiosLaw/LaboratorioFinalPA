#include "RealizarEjercicio.h"

//Falta pasar las operaciones al controlador principal, haré eso según tenga idea de los retornos y demás.

RealizarEjercicio::RealizarEjercicio()
{
    this->controlador = Controller::getInstance();
}

RealizarEjercicio::~RealizarEjercicio()
{
    // No eliminar el controlador, ya que es un singleton
}

void RealizarEjercicio::realizarEjercicio()
{
    //del menu venimos aca, y aca empezamos a hacer las operaciones que necesitemos

    listarNicksEstudiantes();
    listarCursosPendientesDeAlumno();
    listarEjerciciosPendientesDeCurso();
    IngresarSolucion();
}

void RealizarEjercicio::listarNicksEstudiantes(){
    // Al controller le pido una lista de los nicks de los usuarios de tipo estudiante
}

void RealizarEjercicio::listarCursosPendientesDeAlumno(){
    // Al controller, le pido la lista de cursos pendientes del alumno con el nick que seleccione de la lista anterior
    // Esto significa que registro en primer lugar deberá verificar si el avance es 100, en caso contrario, retornando el curso.
}

void RealizarEjercicio::listarEjerciciosPendientesDeCurso(){
    // En este caso le pasamos directamente a un curso que sabemos que esta pendiente, la lista de ejercicios completados del alumno desde el registro, para posteriormente pedirle al curso que pase por cada una de sus lecciones y verifique si todos sus ejercicios se encuentran en la lista
    // En caso de que todos los ejercicios de la leccion se encuentren en la lista, se sale de la leccion y se la considera completada (Cosa que no se refleja en ningun lado), pasando a la siguiente leccion y repitiendo, si todas las lecciones estan completadas, el curso no esta pendiente sino completado y el avance debe ser cambiado a 100.
    // En caso de que un ejercicio de una leccion no este en la lista de aprobados, se guarda hasta que se completa el for dentro de la leccion y se retorna la lista de aquellos ejercicios que no esten en la lista de aprobados.
}

    // Falta un metodo para seleccionar el ejercicio de la lista :v (Me olvide de lo mas boludo), este metodo tambien debería de generar la visual del ejercicio para que la persona realice y demás.

void RealizarEjercicio::IngresarSolucion(){
    // Al ejercicio selecionado en especifico, pedirle que verifique si la solucion que escribio el usuario es igual a la que el esperaba, en caso de que ahi sea, retorna true y por lo tanto el ejercicio deberia ser agregado a la lista de ejercicios aprobados del estudiante en ese curso. 
}
