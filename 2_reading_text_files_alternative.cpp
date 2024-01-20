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

int main(){

    string fileName = "example_reading_with_spaces.txt";
    //string fileName = "example_reading.txt";
    fstream file;


    file.open(fileName, ios::in);//We open the file in read mode.
    
    if (file.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
        
    while (!file.eof()) {
        file >> line;
        cout << line << endl; 
    }
    file.close();
    
    return 0;
}