#include <iostream>
#include <fstream>
#include <string>
#include "libs/Movie.hh"


using namespace std;

const int EXIT_ERROR_CODE = -1;

void bubbleSortMovies(Movie movies[], int size);

int main() {

    /* Este ejemplo lo resolveremos en clase. La idea es hacer el siguiente programa:
        Programa que lee un archivo de texto con una lista de películas.
        El archivo tiene el siguiente formato:
        id;year;rating;title
        1;1994;90;The Shawshank Redemption
        2;1972;90;The Godfather
        EL archivo tiene 87 líneas

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

    const char* fileName = "example_reading.txt"; 
    
    fstream file; 

    file.open(fileName, ios::in);

    if (file.fail()) {
        cerr << "Ocurrió un error al abrir el archivo" << endl;
        return 1;
    }

    //Hago lo que tengo que hacer con mi archivo
    //2;1972;90;The Godfather
    char line[256] = {};
    Movie movies[87];
    int moviesPosition = 0;
    while(file.getline(line, 256)) {
        //line va a ir guardando "2;1972;90;The Godfather"
        //string tokens[4];
        
        string lineFromChar(line);
        
        stringstream ss(lineFromChar);
        string token;
        char delim = ';';
        int tokenCount = 0;
        
        char tokens[4][50];
        //linefromChar = 2;1994;89;Nombre

        while (getline(ss, token, delim)) {
            if (!token.empty()) {
                strncpy(tokens[tokenCount], token.c_str(), 50);
                tokenCount++;
            }
        }
        
        Movie movie = getMovieFromTokens(tokens);

        movies[moviesPosition] = movie;
        moviesPosition++;
    }

    file.close();
    
    fstream reportFile;
    reportFile.open("movies_report.txt", ios::out);
    //Imprimo las películas con rating mayor a 80
    reportFile << "=========================== Películas con calificación mayor a 80 ===========================\n";
    int count = 0;
    for (int i = 0; i < moviesPosition; i++) {
        if (movies[i].rating > 80) {
            reportFile << "ID: " << movies[i].id << endl;
            reportFile << "Year: " << movies[i].year << endl;
            reportFile << "Rating: " << movies[i].rating << endl;
            reportFile << "Title: " << movies[i].title << endl;
            reportFile << "============================================================================================\n";
            count++;
        }
    }
    
    reportFile << "Número de películas con calificación mayor a 80: " << count << endl;
    reportFile << "Número total de películas: " << moviesPosition << endl;

    reportFile.close();

    //Si quiero ordenar las películas por año y rating, puedo usar un algoritmo de ordenamiento
    // pero debo tener guardadas todas las películas primero, no puedo ir imprimiendo a medida que las leo.

    fstream reportFileSorted;
    reportFileSorted.open("movies_report_sorted.txt", ios::out);
    reportFileSorted << "=========================== Películas ordenadas por año y calificación ===========================\n";
    bubbleSortMovies(movies, moviesPosition);
    count = 0;
    for (int i = 0; i < moviesPosition; i++) {
        if (movies[i].rating >= 80) {
            reportFileSorted << "ID: " << movies[i].id << endl;
            reportFileSorted << "Year: " << movies[i].year << endl;
            reportFileSorted << "Rating: " << movies[i].rating << endl;
            reportFileSorted << "Title: " << movies[i].title << endl;
            reportFileSorted << "============================================================================================\n";
            count++;
        }
    }
    reportFileSorted << "Número de películas con calificación mayor a 80: " << count << endl;
    reportFileSorted << "Número total de películas: " << moviesPosition << endl;
    reportFileSorted.close();


    return 0;
}

void bubbleSortMovies(Movie movies[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (movies[j].year < movies[j + 1].year || 
                (movies[j].year == movies[j + 1].year 
                    && movies[j].rating < movies[j + 1].rating)) {
                // Swap
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}



