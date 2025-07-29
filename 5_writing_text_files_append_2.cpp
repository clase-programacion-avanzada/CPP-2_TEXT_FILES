/*
 * En este archivo veremos cómo agregar contenido a archivos.
 * De manera similar a iostream (input stream y output stream), 
 * fstream (file stream) se utiliza para leer y escribir archivos.
 */
#include <iostream> 
#include <fstream>

using namespace std; 


int main(){

    const char* fileName = "example_writing_append_2.txt";
    fstream file;
    
    file.open(fileName, ios::out | ios::app); // Abrimos el archivo en modo escritura.
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    /*
     * El proceso de escribir en un archivo se hace usando la función write().
     * El enfoque es muy similar a escribir en la consola.
     * En la consola, usamos el operador << (i.e cout << "Hello World!"),
     * con archivos, reemplazamos cout con file.
     */
    file<<"Hello World!\n";
    file<<"This is a new line.\n";
    file<<"This is another new line.\n";
    file<<"This is the last line.\n";
    // Debemos asegurarnos de cerrar el archivo cuando terminemos de escribir en él.
    file.close();

    
    /*
     * Cada vez que usamos ios::out estamos sobrescribiendo el archivo.
     * Si queremos agregar información al archivo, necesitamos usar ios::app.
     * La función open() puede usarse para abrir un archivo en modo append.
     */
    file.open (fileName, ios::app); // append
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    // Podemos agregar información al archivo.
    file<<"Hello Again in append mode!\n";
    file.close();


    return 0;
}