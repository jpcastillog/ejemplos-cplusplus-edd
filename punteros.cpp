#include <iostream>
#include <string>

using namespace std;

struct alumno {
    std::string nombre;
    int rol;
    float nota;
    char sexo;
    struct fecha {
        int dia;
        int mes;
        int anio;
    } fechaNacimiento;
};


/* Los punteros almacenan direcciones 
de memoria de las variables a las que apuntan
*/

int main () {
    int i = 100;
    /* Para declarar un puntero es:
    <tipo_dato>* nombre_puntero;
    */
    // ej. puntero a int
    int* p;
    /* p almacena la dirección de memoria de i */
    p = &i; //&(variable) obtenemos dirección de memoria de un variable
    cout << "La dirección de memoria de i es: " << p << endl;
   
    /* Se puede obtener el contenido de la dirección 
    que almacena el puntero con: *nombre_puntero
    */
    cout << "Lo que hay almacenado en la dirección p es: " << *p << endl;
    cout << "Lo que hay almacenado en i es: " << i << endl;

    /* Punteros en arreglos:
    * Nombre del arreglo: representa la dirección base del arreglo
    * Dirección base: la dirección base de un arreglo es la dirección
     del primer elemento del arreglo
    */


    /* También podemos tener punteros a structs:
    * <nombre_struct>* nombre_puntero; 
    */
    alumno a = {"sansano", 201573531, 54.5, 'm',
                 {1, 1, 2001}};
    alumno* p_alumno;
    p_alumno = &a;
    /* Podemos acceder a los registros a lo
     que apunta el puntero utilizando "->"
    */
    cout  << "Nombre del alumno en la direccion p_alumno: " << p_alumno -> nombre << endl;
    cout  << "Rol del alumno en la direccion p_alumno: " << p_alumno -> rol << endl;
    cout  << "Fecha de nacimiento del alumno en la direccion p_alumno: " 
          << p_alumno -> fechaNacimiento.dia << "/" 
          << p_alumno -> fechaNacimiento.mes << "/"
          << p_alumno -> fechaNacimiento.anio << endl;

    return 0;

}