//In this file we will see how to write files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>
#include "libs/List.h"

using namespace std; 


int main(){

    string sfileName = "example_writing.txt";
    fstream file;
    //We can open a file using the open() function.
    //The first parameter is the name of the file, the second parameter is the mode.
    //The mode can be either ios::in (read only) or ios::out (write only) .
    //The third parameter is the mode of the file.
    file.open(sfileName, ios::out);//We open the file in write mode.
    //The open() function returns a boolean value.
    //If the file is opened successfully, the function returns true.
    //If the file is not opened, the function returns false.
    //We need to make sure that this stream is succesfully open before we can write to it.
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    
    //The process of writing to a file is done using the write() function. 
    //The approach is very similar of writing into a console. 
    //in the console, we use the << operator (i.e cout << "Hello World!"),
    //with files, we replace cout with file.
    file<<"Hello World!\n";
    file<<"This is a new line.\n";
    file<<"This is another new line.\n";
    file<<"This is the last line.\n";
    //We must be sure that we close the file when we are done writing to it.
    file.close();

    //We can also use the write() function but writing a list of strings.
    string fileNameList = "example_writing_list.txt";

    file.open(fileNameList, ios::out);//We open the file in write mode.

    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    //We can also use the write() function but writing a list of strings.

    List<string> lines;

    lines.add("Hello World!");
    lines.add("This is a new line.");
    lines.add("This is another new line.");
    lines.add("This is the last line.");

    for(int i = 0; i < lines.size; i++) {
        if(i != 0) {
            file<<endl;
        }
        file<<lines.get(i);
    }

    return 0;
}