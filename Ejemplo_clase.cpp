#include <iostream>
#include <fstream>
#include "libs/List.h"
#include <string>
#include <sstream>

using namespace std;

struct Movie {
    int id;
    int yearOfRelease;
    int rating;
    string name;
};

List<string> readFile(string fileName);
List<Movie> getMoviesFromList(List<string> lines);
List<Movie> filterMoviesByYear(List<Movie> movies, int year);
float getRatingAverage(List<Movie> movies);
List<string> split(string line, char delimiter);
List<string> getAverageReport(List<Movie> movies);
bool writeFile(List<string> lines);

int main() {
    
    
    string fileName = "example_reading.txt";
    //Verificar si el archivo se pudo abrir
    
    //Si se puede abrir, entonces guardar las líneas del archivo en List<string>
    List<string> lines = readFile(fileName);

    //Convertir mi List<string> a List<Movie>
    List<Movie> movies = getMoviesFromList(lines);
    // 1. Separar cada línea
    // 2. Crear una película a partir de esos datos.
    // Filtrar las peliculas cuyo año sea mayor a 1983.
    List<Movie> moviesSince1984 = filterMoviesByYear(movies, 1983);

    float ratingAverage = getRatingAverage(moviesSince1984);

    cout<< ratingAverage << endl;

    List<string> report = getAverageReport(moviesSince1984);
    //Escribir en un archivo
    /* Reporte
    lista de películas

    nombre: lo que sea - año:2001 - calificación: 85
    
    El promedio de calificación es 
    */

    bool fileWasWritten = writeFile(report);

    if (fileWasWritten) {
        cout<< "Archivo creado con éxito";
    }


    return 0;
}

List<string> readFile(string fileName) {
    fstream file;
    List<string> result;
    file.open(fileName, ios::in);

    if(file.fail()) {
        return result;
    }

    string line;

    while (getline(file, line)) {
        result.add(line);

        cout<<line<<endl;
    }

    file.close();

    return result;

}

List<string> split(string line, char delimiter) {
    List<string> tokens;
    

    return tokens;
}
List<Movie> getMoviesFromList(List<string> lines) {

    List<Movie> movies;
    //Recorrer la lista
    for(int i=0; i<lines.size; i++) {
        string line = lines.get(i);
        //Separar por ';'
        List<string> tokens = split(line,';');
        //tokens => ["1","1968","86"," Greetings"]
        //Asigno los valores a mi nueva película
        Movie movie;

        movie.id = stoi(tokens.get(0));
        movie.yearOfRelease = stoi(tokens.get(1));
        movie.rating = stoi(tokens.get(2));
        movie.name = tokens.get(3);

        movies.add(movie);

    }

    return movies;
}

List<Movie> filterMoviesByYear(List<Movie> movies, int year) {

    List<Movie> moviesFromYear;

    for(int i=0;i<movies.size; i++) {
        Movie movie = movies.get(i);

        if(movie.yearOfRelease > year) {
            moviesFromYear.add(movie);
        }
    }

    return moviesFromYear;


}

float getRatingAverage(List<Movie> movies) {

    if(movies.size == 0) {
        return -1;
    }

    float sum = 0;

    for(int i=0; i<movies.size; i++) {
        Movie movie = movies.get(i);
        sum += movie.rating;
    }

    return sum/movies.size;
}

List<string> getAverageReport(List<Movie> movies) {
    
    List<string> report;

    report.add("==========Reporte========= \n");

    for (int i=0; i<movies.size ; i++) {
        Movie movie = movies.get(i);

        string lineReport = "nombre: " + movie.name + "-" 
                            + "año: " + to_string(movie.yearOfRelease) + "-" 
                            + "calificación: " + to_string(movie.rating);
    
        report.add(lineReport);

    }

    float average = getRatingAverage(movies);

    report.add("El promedio de calificación es " + to_string(average));

    return report;
}

bool writeFile(List<string> lines) {

    fstream file;

    file.open("report.txt", ios::out);

    if (file.fail()) {
        return false;
    }

    for(int i=0; i < lines.size; i++) {
        file << lines.get(i)<< endl;
    }

    file.close();

    return true;

}
 