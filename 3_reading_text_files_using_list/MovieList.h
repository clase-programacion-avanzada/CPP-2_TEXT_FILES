#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "Movie.h"
#include "LineList.h"

using namespace std;

struct MovieList {
    
    Movie movies[100];
    int size;

    MovieList() {
        size = 0;
    }

    void add(Movie movie) {
        movies[size] = movie;
        size++;
    }

    bool remove(int index) {

        if (index < 0 || index >= size) {
            return false;
        }

        for (int i = index; i < size - 1; i++) {
            movies[i] = movies[i + 1];
        }
        size--;

        return true;
    }

    Movie get(int index) {
        return movies[index];
    }

    bool contains(Movie movie) {
        for (int i = 0; i < size; i++) {
            if (movies[i].equals(movie)) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        size = 0;
    }

    MovieList copy(MovieList other) {
        MovieList newList;
        
        for (int i = 0; i < other.size; i++) {
            newList.add(other.movies[i]);
        }

        return newList;
    }

};

MovieList getMoviesFromLines(LineList lines, char delimiter) {
    MovieList movies;
    for (int i = 0; i < lines.size; i++) {
        Movie movie = getMovieFromLine(lines.get(i), delimiter);
        movies.add(movie);
    }
    return movies;
}

#endif /* MOVIELIST_H */