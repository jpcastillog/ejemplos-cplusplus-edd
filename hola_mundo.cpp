#include <iostream>
int a;
/* Espacios de nombres, para evitar agregar std:: */
using namespace std;

/* Este programa imprime Hola mundo en pantalla */
int main () {
    // Sin usar "using namespace std;"
    // std::cout << "Hola mundo" << std::endl;
    // Sin usar "using namespace std"
    cout << "Hola mundo" << endl;
    /* Valor de return indica al sistema operativo si el programa finalizo correctamente
        0:     El programa finaliza exitosamente
        != 0:  El programa no pudo finalizar correctamente (ERROR) */
    return 0;
}
