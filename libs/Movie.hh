#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>
#include <cstring>

using namespace std;

struct Movie{
    int id;
    int year;
    int rating;
    char title[50];

    Movie() {
        id = 0;
        year = 0;
        rating = 0;
        strncpy(title, "", 50);
    }

    bool operator==(const Movie& other) const {
        return id == other.id
            && year == other.year
            && rating == other.rating
            && title == other.title;
    }
};

Movie getMovieFromTokens (char tokens[4][50]) {
    

    Movie aux_movie;
    
    aux_movie.id = atoi(tokens[0]);
    aux_movie.year = atoi(tokens[1]);
    aux_movie.rating = atoi(tokens[2]);
    strncpy(aux_movie.title, tokens[3], 50);
    
    return aux_movie;

}

void getLineFromMovie(Movie movie, char delimiter, char line[256]) {
    stringstream ss;
    strncpy(line, "", 256);
    ss << movie.id << delimiter
        << movie.year << delimiter
        << movie.rating << delimiter
        << movie.title;
    ss.getline(line, 256);
}

#endif /* MOVIE_H */