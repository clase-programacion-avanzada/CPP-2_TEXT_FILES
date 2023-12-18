#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>

using namespace std;

struct Movie{
    int id;
    int year;
    int rating;
    string title;

    Movie() {
        id = 0;
        year = 0;
        rating = 0;
        title = "";
    }

    bool equals(Movie other) {
        return id == other.id
            && year == other.year
            && rating == other.rating
            && title == other.title;

    }
};

Movie getMovieFromLine (string line, char delimiter) {
    
    string word; 
    Movie aux_movie;
    stringstream str(line);

    getline( str, word, delimiter);
    aux_movie.id = stoi(word);

    getline( str, word,delimiter);
    aux_movie.year = stoi(word);

    getline( str, word,delimiter);
    aux_movie.rating = stoi(word);

    getline( str, word,delimiter);
    aux_movie.title = word;

    return aux_movie;

}

string getLineFromMovie (Movie movie, char delimiter) {
    return to_string(movie.id) + delimiter
        + to_string(movie.year) + delimiter
        + to_string(movie.rating) + delimiter
        + movie.title;
}

#endif /* MOVIE_H */