#include <iostream>
#include <iomanip>
#include <string>

#include "libs/Movie.h"
#include "libs/MovieList.h"
#include "libs/TextFileHandler.h"
#include "libs/LineList.h"

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

MovieList moviesWithratingGreaterThan(MovieList movies, double rating) {
    MovieList newList;

    for (int i = 0; i < movies.size; i++) {
        if (movies.get(i).rating > rating) {
            newList.add(movies.get(i));
        }
    }

    return newList;
}


int main(){

    string inputFileName = "example_reading.txt";
    const char delimiter = ';';

    TextFileHandler readFileHandler(inputFileName);

    LineList lines = readFileHandler.readLines();

    printLines(lines);

    MovieList movies = getMoviesFromLines(lines, delimiter);

    for (int i = 0; i < movies.size; i++){
        printMovie(movies.get(i));
    }

    // Write the movies to a file
    string outputFileName = "output.txt";
    TextFileHandler writeFileHandler(outputFileName);

    MovieList moviesWithRatingGreaterThan80 = moviesWithratingGreaterThan(movies, 80);    
    LineList linesToWrite = getLinesFromMovies(moviesWithRatingGreaterThan80, '#');
    linesToWrite.add("Total: " + to_string(moviesWithRatingGreaterThan80.size) + " movies.");
    linesToWrite.add("Average rating: " + to_string(getAverageRating(moviesWithRatingGreaterThan80)));
    printLines(linesToWrite);

    writeFileHandler.writeLines(linesToWrite);
    


    return 0;
}


