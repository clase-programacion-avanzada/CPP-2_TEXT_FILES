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
    char title[256];

    Movie() {
        id = 0;
        year = 0;
        rating = 0;
        strncpy(title, "", 256);
    }

    bool equals(Movie other) {
        return id == other.id
            && year == other.year
            && rating == other.rating
            && strncmp(title, other.title, 256) == 0;

    }

    bool operator==(const Movie& other) const {
        return id == other.id
            && year == other.year
            && rating == other.rating
            && title == other.title;
    }
};

Movie getMovieFromLine (string line, char delimiter) {
    

    Movie aux_movie;
   
    
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