/*
 * En este archivo veremos cómo leer archivos.
 * De manera similar a iostream (input stream y output stream), 
 * fstream (file stream) se utiliza para leer y escribir archivos.
 */
#include <iostream> 
#include <fstream>
// Incluir la librería string.
#include <string>
#include <sstream>

using namespace std; 

int main(){

    const char* fileName = "example_reading_with_spaces.txt";
    fstream file;


    file.open(fileName, ios::in); // Abrimos el archivo en modo lectura.
    
    if (file.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    char line[256];

    while (!file.eof()) {
        file >> line;
        cout << line << endl; 
    }
    file.close();
    
    return 0;
}