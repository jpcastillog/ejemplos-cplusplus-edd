#include <iostream>

using namespace std;

/* Definición de una función:
tipo_retorno nombre_funcion (lista_parametros) {
    declaracion-var-locales;
    cuerpo-de-la-funcion;
}
*/

// Ej.
int add(int x, int y){
    int r = x + y;
    return r;
}

/* Funciones tipo void:
* Funciones que no retornan ningun valor
* Podemos forzar su termino con "return;"
*/
// Ej.
void printValue(int x) {
    cout << "El valor de la variable es: " << x << endl;
    // return; <- aqui podemos colocar un return si deseamos
}

/* Paso de parámetros:
* Los pasos de parámetros por defecto en c++ es por valor 
(se copian los parámetros reales a los formales), exceptuando los arreglos.
* Para pasar por referencia debemos agregar un & antes del nombre del parámetro.
*/
// Ej. r es pasado por referencia.
void referenceAdd(int x, int y, int &r) {
    r = x + y;
}

/* También se puede simular el paso por referencia utilizando punteros */
// Ej: Función que intercambia los valores de los parametros reales.
void swapR(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapP(int* a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;  
}

/* Pasar arreglos como parámetro:
* Todos los arreglos en c++ se pasan por referencia.
* También se puede usar un puntero del tipo base del arreglo 
para pasar la dirección base del arreglo
* También se debe pasar un parámetro extra para el tamaño del arreglo
*/
// Ej.
// Paso por referencia
float promedioRef(int array[], int n) {
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += array[i];
    }
    return (float)suma/n;
}
// Utilizando un puntero
float promedioPnt(int* p, int n) {
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += p[i]; 
    }
    return (float)suma/n;
}

int main() {
    int a = 5;
    int b = 10;
    int r;
    // Llamamos a una funcion con parametros por valor
    r = add(a, b);
    cout << "add(a, b): " << r << endl;
    // Llamamos una función con parametros por referencia
    r = 0;
    referenceAdd(a, b, r);
    cout << "referenceAdd(a, b): " << r << endl;
    
    /* Podemos modificar los parametros reales utilizando 
    el paso por referencia o utilizando punteros */
    swapR(a, b);
    cout << "* swapR(a, b) ->  a = " << a << " b=" << b << endl;
    swapP(&a, &b);
    cout << "* swapP(a, b) ->  a = " << a << " b=" << b << endl;
    
    /* Pasar arreglos como parámetros */
    int A[] = {1, 2, 6, 8, 9};
    cout << "promedioRef(A, 5): " << promedioRef(A, 5) << endl;
    cout << "promedioPnt(A, 5): " << promedioPnt(A, 5) << endl;
    
    return 0;
}