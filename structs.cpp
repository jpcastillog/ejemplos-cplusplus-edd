#include <iostream>
#include <string>

using namespace std;

/*
   * Un struct son conjuntos de una o más varialbles
   que pueden ser de distintos tipos, agrupadas sobre
   un mismo nombre.
   * Definición de un struct:
   struct nombre_struct {
       <tipo_dato> nombre_campo_1;
       <tipo_dato> nombre_campo_2;
            ...
       <tipo_dato> nombre_campo_n;
   } 
*/

//  Ej:
struct empleado {
    int codigo;
    std::string nombre;
    float sueldo;
};

/* También podemos definir structs
   sobre structs */
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


int main() {
    /* Para crear un elemento de un cierto struct:
        <nombre_struct> nombre_var;
    */
    // struct de tipo alumno
    alumno a; // declaranción
    a = {"Sansano", 202073531, 54.5, 'm', {1, 1, 2001}}; // instanciación
    
    /* Podemos acceder a los campos de un struct
       con el operador ".nombre_campo"
    */
    alumno b;
    b.nombre                = "Sansana";
    b.rol                   =  201573570;
    b.nota                  = 54.5;
    b.sexo                  = 'f';
    b.fechaNacimiento.dia   = 20;
    b.fechaNacimiento.mes   = 11;
    b.fechaNacimiento.anio  = 1995;

    cout << "Datos del alumno b: " << endl;
    cout << "* nombre: " << b.nombre << endl;
    cout << "* rol: " << b.rol << endl;
    cout << "* nota: " << b.nota << endl;
    cout << "* sexo: " << b.sexo << endl;
    cout << "* fecha de nacimiento: " << b.fechaNacimiento.dia << "/" 
                                      << b.fechaNacimiento.mes << "/"
                                      << b.fechaNacimiento.anio << endl;
    cout << "----------------------------------------------------" << endl;

    /* Dirección de memoria de un struct 
    * La dirección base de un struct es la dirección del primer campo
    */
    cout << "dirección de mem. del alumno b (&b):                         " << &b << endl;
    cout << "dirección de mem. del campo nombre del alumno b (&b.nombre): " << &b.nombre << endl;
    cout << "----------------------------------------------------" << endl;

    /* Arreglos de structs */
    alumno alumnos[3]; // Arreglo de 3 structs tipo alumno
    
    alumnos[0] = a;
    alumnos[1] = b;
    // Instanciamos directamente los datos del 3er alumno del array
    alumnos[2].nombre = "Sansanito";
    alumnos[2].rol    = 201573559;
    alumnos[2].nota   = 70.2;
    alumnos[2].sexo   = 'm';
    alumnos[2].fechaNacimiento = {2, 3, 1996};

    for (int i = 0; i < 3; ++i) {
        cout << "Datos del alumno " << i << ":" << endl;
        cout << "* nombre: "<< alumnos[i].nombre << endl;
        cout << "* rol: "   << alumnos[i].rol << endl;
        cout << "* nota: "  << alumnos[i].nota << endl;
        cout << "* sexo: "  << alumnos[i].sexo << endl;
        cout << "* fecha de nacimiento: " << alumnos[i].fechaNacimiento.dia << "/" 
                                          << alumnos[i].fechaNacimiento.mes << "/"
                                          << alumnos[i].fechaNacimiento.anio << endl;
    }

    return 0;
}