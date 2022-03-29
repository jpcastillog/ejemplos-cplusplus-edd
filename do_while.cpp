#include <iostream>

using namespace std;

int main(){
    int i = 10;
    /* El do while nos asegura que se ejecute
    una vez el contenido del loop, se ejecuta
    el contenido del loop y luego revisa la condición
    */ 
    do{   
        cout << "do while -> i: " << i << endl;
    } while (i < 10);
    
    /* While revisa la condición y luego ejecuta el
    contenido del looop
    */
    while (i < 10) {
        cout << "while -> i:" << i << endl;
    }
        
    return 0;
        
}