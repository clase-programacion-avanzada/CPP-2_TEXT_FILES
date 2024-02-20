//In this file we will see how to read files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>
//Include the string library.
#include <string>
#include "libs/List.h"

using namespace std; 


int main(){

    string fileName = "example_reading.txt";
    //We create a file stream object.
    // a file stream object is an object that will help us to read and write files.
    // ifstream is the class that will help us to read files.
    // ofstream is the class that will help us to write files.
    // fstream is the class that will help us to read and write files.
    // In general a stream is a sequence of data elements made available over time.
    // In this case the data elements are the characters of the file.
    fstream file;

    //We open the file.
    //We use the open() function from the file stream object.
    file.open(fileName, ios::in);//We open the file in read mode.
    
    //We check if the file was opened correctly.
    if (file.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
    //We use the getline() function to read the file line by line.
    //istream& getline (istream&  is, string& str, char delim);
    // we can use it inside a while loop because it returns true if the line was read correctly.
    List<string> lines;
    while (getline(file, line)) {
        lines.add(line);
        cout<<line<<endl;
    }
    file.close();

    //We could even read the file and store it in a list of strings.
    //We can use the getline() function inside a while loop because it returns true if the line was read correctly.



    return 0;
}