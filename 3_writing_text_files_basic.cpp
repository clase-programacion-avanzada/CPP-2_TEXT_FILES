/*
 * En este archivo veremos cómo escribir archivos.
 * De manera similar a iostream (input stream y output stream), 
 * fstream (file stream) se utiliza para leer y escribir archivos.
 */
#include <iostream> 
#include <fstream>

using namespace std; 


int main(){

    const char* fileName = "example_writing.txt";
    fstream file;
    /*
     * Podemos abrir un archivo usando la función open().
     * El primer parámetro es el nombre del archivo, el segundo parámetro es el modo.
     * El modo puede ser ios::in (solo lectura) o ios::out (solo escritura).
     */
    file.open(fileName, ios::out); // Abrimos el archivo en modo escritura.
    /*
     * La función open() retorna un valor booleano.
     * Si el archivo se abre exitosamente, la función retorna true.
     * Si el archivo no se abre, la función retorna false.
     * Necesitamos asegurarnos de que este stream se abra exitosamente antes de poder escribir en él.
     */
    
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

    return 0;
}