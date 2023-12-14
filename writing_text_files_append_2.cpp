//In this file we will see how to append in files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>

using namespace std; 


int main(){

    string sfileName = "example_writing_append_2.txt";
    fstream file;
    
    file.open(sfileName, ios::out);//We open the file in write mode.
    
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

    
    //Everytime we use ios::out we are overwriting the file.
    //If we want to append information to the file, we need to use ios::app.
    //The open() function can be used to open a file in append mode.
    file.open (sfileName, ios::app);//append
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    //We can append information to the file.
    file<<"Hello Again in append mode!\n";
    file.close();


    return 0;
}