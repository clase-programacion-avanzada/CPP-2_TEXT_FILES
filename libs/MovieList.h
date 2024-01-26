#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "Movie.h"
#include "List.h"

using namespace std;

List<Movie> getMoviesFromLines(List<string> lines, char delimiter) {

    List<Movie> movies;

    for(int i = 0; i < lines.size; i++) {
    
        
        Movie movie = getMovieFromLine(lines.get(i), delimiter);
        
        movies.add(movie);
    }

    return movies;
}

List<string> getLinesFromMovies(List<Movie> movies, char delimiter) {
    List<string> lines;
    for (int i = 0; i < movies.size; i++) {
        lines.add(getLineFromMovie(movies.get(i), delimiter));
    }
    return lines;
}

float getAverageRating(List<Movie> movies) {
    float sum = 0;
    for (int i = 0; i < movies.size; i++) {
        sum += movies.get(i).rating;
    }
    return sum / movies.size;
}


#endif /* MOVIELIST_H */