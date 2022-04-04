#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

/* 
* Los archivos son una secuencia de bytes, que se almacenan en memoria secundaria.
* En c++ se pueden manipular mediante streams.
* Se debe importar la libreria <fstream> para manipular archivos.
* Existen 3 tipos de streams:
** ifstream: soporta operaciones de entrada (leer datos).
** ofstream: soporta operaciones de salida (escribir datos).
** fstream: soporta operaciones tanto de entrada como salida.
*/

using namespace std;

struct empleado {
    int codigo;
    char nombre[10];
    float sueldo;
};

/* Archivos ASCII */
empleado* readEmpleados(std::string input_path, int &n) {
    ifstream in;
    in.open(input_path);
    if (!in.is_open()) {
        cerr << "No se pudo abrir el archivo " << input_path << endl;
    }
    // Leemos la cantidad de elementos a leer
    in >> n;
    empleado* emps = new empleado[n]; // Memoria dinámica
    for (int i = 0; i < n; ++i) {
        int codigo;
        char nombre[10];
        float sueldo;
        in >> codigo;
        in >> nombre;
        in >> sueldo;

        emps[i].codigo = codigo;
        strcpy(emps[i].nombre, nombre);
        // emps[i].nombre = nombre; -> no se puede hacer cuando el string es de cstring (arreglo de chars)
        emps[i].sueldo = sueldo;
    }
    in.close();
    
    return emps;
}


void writeEmpleados(empleado emps[], int n, std::string out_path){
    ofstream fout;
    fout.open(out_path);
    if (!fout.is_open())
        cerr << "No se pudo abrir el archivo" << out_path << endl;
    fout << n << endl;
    for (int i = 0; i < n; ++i) {
        fout << emps[i].codigo << " " 
             << emps[i].nombre << " "
             << emps[i].sueldo << endl;       
    }
    fout.close();
    return;
}


/* Archivos Binarios */
empleado* readEmpleadosBin(std::string input_path, int &n) {
    ifstream in;
    in.open(input_path, ios::in | ios::binary);
    if (!in.is_open()) {
        cerr << "No se pudo abrir el archivo " << input_path << endl;
    }
    in.read((char*)&n, sizeof(int));
    empleado* p_empleado = new empleado[n];
    
    /* Dos formas de leer arreglos */
    // Volcado directo
    // in.read((char*) p_empleado, n*sizeof(empleado));
    // Leer elemento a elemento
    for (int i = 0; i < n; i++) {
        in.read((char*)&p_empleado[i], sizeof(empleado));
    }
    in.close();
    
    return p_empleado;
}

void writeEmpleadosBin(empleado emps[], int n, std::string out_path){
    ofstream fout;
    fout.open(out_path, ios::binary|ios::out);
    if (!fout.is_open())
        cerr << "No se pudo abrir el archivo" << out_path << endl;
    fout.write((char*)&n, sizeof(int));
    // fout.write((char*)emps, n*sizeof(empleado));
    for (int i = 0; i < n; ++i) {
        fout.write((char*)&emps[i], sizeof(empleado));      
    }
    fout.close();
    return;
}


int main(){
    /* Primero se debe declarar el tipo de stream -> fstream, ifstream, ofstream.*/
    fstream fp;
    /* Para abrir el archivo debemos señalar el nombre del archivo y el modo de apertura:
    * fp.open(<nobre_archivo>, <modo>) 
    * Para el modo de apertura existen varios flags:
    * * ios::in     -> archivo para lectura de datos.
    * * ios::out    -> archivo para escritura de datos, si el archivo existe destruye su contenido.
    * * ios::app    -> abre el archivo permitiendo operac iones de escritura sólo al final del archivo.
    * * ios::ate    -> permite comenzando operando al final del archivo.
    * * ios::binary -> abre el archivo en modo binario.
    * */
    fp.open("./data/archivo.txt", ios::in | ios::out ); // Se pueden mezclar los flags usando | (or a nivel de bits)
    if (!fp.is_open()){ // verificamos si el archivo se pudo abrir
        cerr << "No se pudo abrir archivo.txt" << endl;
    }
    // Con el operador "<<" escribimos en el archivo
    fp << "Primera linea" << endl;
    fp << "Segunda linea" << endl;

    /* Operador seekg:
    * seekg(pos): recibe una posicion (en bytes), en donde colocar el cursor
    * seekg(offset, base): recibe un entero "offset" con la diferencia relativa
    respecto a la "base".
    * Las bases pueden ser:
    ** ios::beg -> inicio del archivo
    ** ios::end -> fin del archivo
    ** ios::cur -> posición actual del cursor
    */
    fp.seekg(0); // Movemos el cursor el inicio del archivo(byte 0).

    /* Con el operador >> leemos elemento a elemento 
       que estan separados por un espacio (" ")
    */
    string s1, s2, s3, s4;
    fp >> s1;
    fp >> s2;
    cout << s1 << " " << s2 << endl;
    fp >> s3;
    fp >> s4;
    cout << s3 << " " << s4 << endl;
    // Número de bytes leidos hasta el momento
    int total_character_readed = s1.size()+ s2.size() + s3.size()+ s4.size() + 3; 
    fp.seekg(-(total_character_readed), ios::cur);
    
    /* Con el operador "get" leemos un caracter 
       en donde este ubicado el cursor */
    char c;
    fp.get(c);
    cout << c << endl;
    /* Con getline(f, s), leemos una linea en el archivo "f"
       y la almacenamos en el string "s"
    */
    fp.seekg(-1, ios::cur); // Movemos el cursor en un byte con respecto a la posicion actual

    string line1, line2;
    getline(fp, line1);
    getline(fp, line2);
    cout << line1 << endl;
    cout << line2 << endl;
    
    fp.close(); //Cerramos el archivo

    /* Arreglos en ASCII */
    ifstream in;
    int n_sets;
    in.open("./data/enteros.txt");
    in >> n_sets;
    for (int i = 0; i < n_sets; ++i) {
        int n_ints;
        in >> n_ints;
        for (int j = 0; j < n_ints; ++j) {
            int e;
            in >> e;
            cout << e << " ";
        }
        cout << endl;
    }
    in.close();

    /* Arreglos en Archivos Binarios */
    // implementar en clases ...


    // Structs
    const int num_empleados = 4;
    empleado empleados[num_empleados] ={
        {0, "Pedro", 500.0},
        {1, "Juan" , 100.2},
        {2, "Diego", 200.43},
        {3, "Maria", 499.0}
    };

    empleado* emps;
    int n;
    writeEmpleados(empleados, num_empleados, "./data/empleados.txt");
    emps = readEmpleados("./data/empleados.txt", n);
    cout << "*** Datos leidos desde archivo ASCII ***" << endl;
    cout << "Número de empleados: " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << emps[i].codigo << " "
             << emps[i].nombre << " "
             << emps[i].sueldo << endl;
    }
    delete[] emps;
    /* Archivos Binarios */
    // Structs
    // Función que escribe el arreglo de structs empleado en un archivo binario
    writeEmpleadosBin(empleados, num_empleados, "./data/empleados.bin");
    emps = readEmpleadosBin("./data/empleados.bin", n);
    cout << "*** Datos leidos desde archivo binario ***" << endl;
    cout << "Número de empleados: " << n << endl;
    for (int i = 0; i < n; ++i) {
            cout << emps[i].codigo << " "
                 << emps[i].nombre << " "
                 << emps[i].sueldo << endl;
    }
    delete[] emps;
    return 0;

}
