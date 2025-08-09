/*
 * En este archivo veremos cómo leer archivos.
 * De manera similar a iostream (input stream y output stream), 
 * fstream (file stream) se utiliza para leer y escribir archivos.
 */
#include <iostream> 
#include <fstream>

#include <string>


using namespace std; 


int main(){

    const char* fileName = "example_reading.txt";
    /*
     * Creamos un objeto file stream.
     * Un objeto file stream es un objeto que nos ayudará a leer y escribir archivos.
     * ifstream es la clase que nos ayudará a leer archivos.
     * ofstream es la clase que nos ayudará a escribir archivos.
     * fstream es la clase que nos ayudará a leer y escribir archivos.
     * En general, un stream es una secuencia de elementos de datos disponibles a lo largo del tiempo.
     * En este caso, los elementos de datos son los caracteres del archivo.
     */
    fstream file;

    /*
     * Abrimos el archivo.
     * Usamos la función open() del objeto file stream.
     */
    file.open(fileName, ios::in); // Abrimos el archivo en modo lectura.
    
    // Verificamos si el archivo se abrió correctamente.
    if (file.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    char line[256];
    // getline(file, line); <- con strings
    while (file.getline(line, 256)) {
        cout << line << endl;
    }
    file.close();

    return 0;
}