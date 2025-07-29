/*
 * En este archivo veremos cómo agregar contenido a archivos.
 * De manera similar a iostream (input stream y output stream), 
 * fstream (file stream) se utiliza para leer y escribir archivos.
 */
#include <iostream> 
#include <fstream>

using namespace std; 


int main(){

    const char* sfileName = "example_writing_append_1.txt";
    fstream file;
    
    file.open(sfileName, ios::out); // Abrimos el archivo en modo escritura.
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    
        
    file<<"Hello World!\n";
    file<<"This is a new line.\n";
    file<<"This is another new line.\n";
    file<<"This is the last line.\n";
    
    file.close();
   
    /*
     * ¿Qué pasa si tratamos de escribir más información al archivo?
     * El archivo ya está abierto, así que no podemos escribir en él.
     * Entonces, vamos a abrirlo nuevamente en modo escritura.
     */
    file.open (sfileName, ios::out); // escribir
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    // Podemos escribir al archivo.
    file<<"Hello Again!\n";
    file.close();
  
    

    return 0;
}