//In this file we will see how to read files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>
//Include the string library.
#include <string>
using namespace std; 


int main(){

    string sfileName = "example_reading.txt";
    //We create a file stream object.
    // a file stream object is an object that will help us to read and write files.
    // ifstream is the class that will help us to read files.
    // ofstream is the class that will help us to write files.
    // fstream is the class that will help us to read and write files.
    // In general a stream is a sequence of data elements made available over time.
    // In this case the data elements are the characters of the file.
    fstream fileStream;

    //We open the file.
    //We use the open() function from the file stream object.
    fileStream.open(sfileName, ios::in);//We open the file in read mode.
    
    //We check if the file was opened correctly.
    if (fileStream.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
    //We use the getline() function to read the file line by line.
    //istream& getline (istream&  is, string& str, char delim);
    // we can use it inside a while loop because it returns true if the line was read correctly.
    while (getline(fileStream, line)) {
        cout<<line<<endl;
    }
    fileStream.close();


    return 0;
}