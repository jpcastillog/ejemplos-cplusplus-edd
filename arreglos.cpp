#include <iostream>

using namespace std;
/* 
    Los arreglos son estructuras básicas, que nos
    permiten almacenar un conjunto de elementos del
    mismo tipo en memoria contigua.
*/

int main () {
    /* 
    * Para declarar cualquier arreglo debemos
    especificar el tipo de dato base del mismo.
    * <tipo_dato_base> nombre_arreglo[tamaño];
     */

    int array1 [10]; // declaramos un arreglo de 10 ints.
    int array2 [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // declaramos e instanciamos el arreglo
    int array3 []   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // declaramos e instanciamos el arreglo sin especificar el tamaño

    /* Dirección de memoria
    * El nombre del arreglo indica la dirección base del arreglo
    * Dirección base: es la dirección de memoria del primer elemento del arreglo
    * &(var): obtenemos la dirección de memoria de var.
    */
    cout << "Dirección base del array:                           " << array2 << endl;
    cout << "Dirección de memoria del primer elemento del array: " << &array2[0] << endl;
    cout << "Dirección de memoria del tercer elemento del array: " << &array2[2] << endl;
    cout << "&array[0] - &array[3]: " << (&array2[2] - &array2[0]) * sizeof(array2[0]) 
         << " bytes de diferencia entre la dirección del primer y tercer elemento" << endl; 
    /* Hay dos enteros de 4 bytes almacenados entre esas direcciones
       (array almacenado de forma contigua en memoria). */
   
    /* Iterar sobre arreglos */
    // Inicializar los valores de un arreglo "vacio"
    for (int i = 0; i < 10; ++i) {
        array1[i] = i;
    }
    // Mostrar su contenido
    cout << "Contenido del array es: ";
    for (int i = 0; i < 10; ++i) {
        cout << array1[i] << " ";
    }
    cout << endl;

    return 0;
}