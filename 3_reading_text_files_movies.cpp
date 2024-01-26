#include <iostream>
#include <string>

#include "libs/Movie.h"
#include "libs/MovieList.h"
#include "libs/TextFileHandler.h"
#include "libs/List.h"

using namespace std;

int EXIT_ERROR_CODE = -1;

void printMovie(Movie movie){
    cout << "ID: " << movie.id << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Rating: " << movie.rating << endl;
    cout << "Title: " << movie.title << endl << endl; 
}

void printLines (List<string> lines) {
    for (int i = 0; i < lines.size; i++){
        cout << lines.get(i) << endl;
    }
}

int main() {

    string fileName = "example_reading.txt";
    const char delimiter = ';';

    cout<< "Now that we have seen how to read a text file line by line,"
        " we can use the same technique to read a file with a specific format." 
        " In those case we will use the TextFileHandler.h file "
        " That library will help you to read a text file and convert it into a" 
        " List<string> and write a List<string> into a text file."<< endl;

    TextFileHandler fileHandler(fileName);

    cout << "In this case the format of the file is the following:"
        " ID;Year;Rating;Title"
        "  i.e 1;1994;90;The Shawshank Redemption" 
        "We call this type of formatted text files csv (comma sepparated value) file. \n" 
        "Even when the delimiter is not a comma, the name is still csv," 
        " in this case the delimiter is the semicolon (;) \n \n"
        "The first thing we need to do is to read the file and convert it into a List<string> \n"
        "  i.e: if we have following file:\n"
        "    1;1994;90;The Shawshank Redemption \n"
        "    2;1972;90;The Godfather \n"
        "  then, the List<string> will be: \n"
        "    [ \"1;1994;90;The Shawshank Redemption\", \n"
        "      \"2;1972;90;The Godfather ]\" \n \n"
        " We can do that using the readLines() function from the TextFileHandler.h library" << endl;
         
    
    List<string> lines = fileHandler.readLines();

    cout << "These are the first and last lines of the file: " << endl;
    cout << "First line: " << lines.get(0) << endl;
    cout << "Last line: " << lines.get(lines.size - 1) << endl << endl;

    cout << "Now that we have the lines, we can convert them into a List<Movie>" << endl;
    cout << "We can do that using the getMoviesFromLines() function from the List<Movie>.h library"<< endl; 
    cout << "This function works as follows: " << endl;

    List<Movie> movies = getMoviesFromLines(lines, delimiter);

    return 0;
}

