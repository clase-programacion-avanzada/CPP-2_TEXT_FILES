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
    fstream fileStream;

    fileStream.open(sfileName, ios::in);//We open the file in read mode.
    
    if (fileStream.fail()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
    //We use the getline() function to read the file line by line.
    //istream& getline (istream&  is, string& str, char delim);
    while (getline(fileStream, line)) {
        cout<<line<<endl;
    }
    fileStream.close();


    return 0;
}