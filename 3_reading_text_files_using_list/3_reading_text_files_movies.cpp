#include <iostream>
#include <string>
#include "Movie.h"
#include "MovieList.h"
#include "TextFileHandler.h"
#include "LineList.h"

using namespace std;

int EXIT_ERROR_CODE = -1;

void printMovie(Movie movie){
    cout << "ID: " << movie.id << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Rating: " << movie.rating << endl;
    cout << "Title: " << movie.title << endl;
}

void printLines (LineList lines) {
    for (int i = 0; i < lines.size; i++){
        cout << lines.get(i) << endl;
    }
}

int main(){

    string fileName = "example_reading.txt";
    const char delimiter = ';';

    TextFileHandler fileHandler(fileName);

    LineList lines = fileHandler.readLines();

    printLines(lines);

    MovieList movies = getMoviesFromLines(lines, delimiter);

    for (int i = 0; i < movies.size; i++){
        printMovie(movies.get(i));
    }

    
    return 0;
}

