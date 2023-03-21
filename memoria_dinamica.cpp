#include <iostream>
#include <time.h> // Solo la utilizaremos para generar un numero random
using namespace std;

struct empleado {
    int codigo;
    std::string nombre;
    float sueldo;
};


int* createArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    return arr;
}

int* createRandomArray(int &n) {
    n = rand()%1000+1; // Número entre 1 y 1000.
    int* arr = new int[n];
    // int arr[n]; No puedo hacer esto!!! (n se define en tiempo de ejecución)
    for (int i=0; i<n; ++i){
        arr[i] = 0;
    }
    return arr;
}

/* Para administrar la memoria dinámica (heap) se
utilizan los operadores: 
* new: pedir memoria -> retorna un puntero
* delete/delete[]: liberar la memoria, 
usamos delete[] para liberar arreglos
*/

int main() {
    int *p;
    p = new int; //pedimos memoria del heap para un int
    *p = 10; // le asignamos un valor
    cout << "El entero pedido mediante new: " << *p << endl; 
    delete p; /* cada new debe ir con su respectivo delete para
    evitar fuga de memoria */
    
    /* Arreglos */ 
    p = new int[10]; // arreglo de 10 ints en el heap
    for (int i = 0; i < 10; ++i) {
        p[i] = i;
    }

    cout << "Arreglo pedido mediante memoria dinámica: ";
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;
    
    /* Funciones pueden retornar punteros a memoria 
    pedida en el heap */
    p = createArray(10);
    cout << "p antes del delete[]: " << p << endl;
    cout << p[1] << endl;
    delete[] p;

    cout << "p despues de un delete[]: " << p << endl;
    cout << p[1] << endl;
    /* Liberar memoria de un puntero que apunta a NULL
    no arroja error, IMPORTANTE MANTENER LAS REFERENCIAS! */ 
    p = NULL;

    delete p;
    return 0;
}