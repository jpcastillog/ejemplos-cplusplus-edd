#include <iostream>

using namespace std;

int main() {
    int i = 0;
    /* ++(postfijo):
    primero se evalua y luego se
    se añade una unidad */
    if (i++ == 1) {
        cout << "i++ = " << i << endl;
    }
    
    /* ++(prefijo): 
    primero se suma una unidad
    y luego se evalua*/
    if (++i == 2) {
        cout << "++i = " << i << endl;
    }

    return 0;
}