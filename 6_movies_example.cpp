#include <iostream>
#include <string>
#include "libs/Movie.hh"


using namespace std;

const int EXIT_ERROR_CODE = -1;

void printMovie(Movie movie){
    cout << "ID: " << movie.id << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Rating: " << movie.rating << endl;
    cout << "Title: " << movie.title << endl << endl; 
}


int main() {

    const char* fileName = "example_reading.txt";

    /* Este ejemplo lo resolveremos en clase. La idea es hacer el siguiente programa:
        Programa que lee un archivo de texto con una lista de películas.
        El archivo tiene el siguiente formato:
        id;year;rating;title
        1;1994;90;The Shawshank Redemption
        2;1972;90;The Godfather

        El programa debe leer el archivo y crear un objeto Movie por cada línea del archivo.
        Luego, debe imprimir por consola los datos de cada película.

        Finalmente, debe generar un reporte de las películas que tienen una calificación mayor a 80.
        El reporte debe estar ordenado por año de lanzamiento (de más reciente a más antiguo) y por calificación (de mayor a menor).
        El reporte debe tener el siguiente formato:
        =========================== Películas con calificación mayor a 80 ===========================
        ID: 1
        Year: 1994
        Rating: 90
        Title: The Shawshank Redemption
        ============================================================================================
        ID: 2
        Year: 1972
        Rating: 90
        Title: The Godfather
        ============================================================================================
        ...
        Número de películas con calificación mayor a 80: 2
        Número total de películas: 100

        Pregunta para la clase:
            ¿Qué habría que hacer si queremos agrupar las películas por año de lanzamiento?
    */
    return 0;
}

