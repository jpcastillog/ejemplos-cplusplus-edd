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
    /* Para declarar un puntero es: <tipo_dato>* nombre_puntero;
    */
    // ej. puntero a int
    int* p;
    /* p almacena la dirección de memoria de i */
    p = &i; //&(variable) obtenemos dirección de memoria de un variable.
    cout << "La dirección de memoria de i es: " << p << endl;
    
    /* Los punteros almacenan direcciones,
    que que están en el rango [0, 2^64) 
    */
    cout << "Sizeof(int*): " <<  sizeof(p) << " bytes" << endl;
    // Esto no depende a que apunte.
    bool bValue = false;
    bool* pbool = &bValue;
    cout << "Sizeof(bool*): " <<  sizeof(pbool) << " bytes" << endl;

    /* Se puede obtener el contenido de la dirección 
        que almacena el puntero con: *nombre_puntero
    */
    cout << "Lo que hay almacenado en la dirección p es: " << *p << endl;
    cout << "Lo que hay almacenado en i es: " << i << endl;

    /* Punteros en arreglos:
    * Nombre del arreglo: representa la dirección base del arreglo
    * Dirección base: la dirección base de un arreglo es la dirección
        del primer elemento del arreglo.
    */


    /* También podemos tener punteros a structs:
        <nombre_struct>* nombre_puntero; 
    */
    alumno a = {"sansano", 201573531, 54.5, 'm',
                    {1, 1, 2001}};
    alumno* p_alumno;
    p_alumno = &a;
    /* Podemos acceder a los registros a lo  que apunta el puntero
        utilizando "->"
    */
    cout  << "Nombre del alumno en la direccion p_alumno: " << p_alumno -> nombre << endl;
    cout  << "Rol del alumno en la direccion p_alumno: " << p_alumno -> rol << endl;
    cout  << "Fecha de nacimiento del alumno en la direccion p_alumno: " 
            << p_alumno -> fechaNacimiento.dia << "/" 
            << p_alumno -> fechaNacimiento.mes << "/"
            << p_alumno -> fechaNacimiento.anio << endl;

    /* También podemos realizar operaciones
    aritméticas sobre los punteros
    */
    int arr[10];
    int* p2;
    i=0;
    // Llenamos el arreglo "arr" con valores 0 a 9.    
    for(p2 = arr; p2 != &arr[9]+1; p2++) { // Note como p2++ salta 4 bytes (sizeof(int))
        *p2 = i;
        ++i;
    }
    // Recorremos e imprimimos el arreglo en reversa
    cout << "Contenido del arreglo (en reversa):" << endl;
    for (p2 = &arr[9]; p2 != (arr-1); p2--) {
        cout << *p2 << " ";
    }
    cout << endl;
    /*
    Podemos saber cuanto espacio ocupa un arreglo en bytes
    (aunque sea una dirección el nombre del arreglo),
    OJO esto solo sirve para arreglos estaticos 
    (pedidos al momento de compilar)
    */
    cout << "sizeof(arr): " << sizeof(arr) << " bytes" << endl;
    /* También podemos operar entre punteros*/
    int dif;
    int *pa , *pb;
    pa = &arr[0];
    pb = &arr[5];
    cout << "La diferencia entre a y b: " << pb-pa << endl;
    return 0;

}