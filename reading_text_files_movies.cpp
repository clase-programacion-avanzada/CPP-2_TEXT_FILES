//In this file we will see how to read files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>
//Include the string library.
#include <string>
#include <sstream>
using namespace std; 

int EXIT_ERROR_CODE = -1;

struct movie{
    int id;
    int year;
    int rating;
    string title;
};
int countLines(fstream& file){
    int count = 0;
    string line;
    while (getline(file, line)){
        count++;
    }
    file.clear();
    file.seekg(0);
    return count;
    
}

movie getMovieFromLine (string line, char delimiter) {
    
    string word; 
    movie aux_movie;
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

int main(){

    string file_name = "example_reading.txt";
    fstream file;
    
    file.open(file_name, ios::in);//We open the file in read mode.
    
    if(!file.is_open()){
        return EXIT_ERROR_CODE;
    }
    //Convert this into a function
    
    string line;
    //We use the getline() function to read the file line by line.
    //istream& getline (istream&  is, string& str, char delim);
    //getline(file,line);
    
    //int arraySize = stoi(line);
    int array_size = countLines(file);
    movie movies[array_size];
     
    
    const char DELIMITER = ';';
    for (int i = 0; i < array_size; i++) {

        getline(file,line);
        movies[i] = getMovieFromLine(line,DELIMITER);

    }

    file.close();

    return 0;
}