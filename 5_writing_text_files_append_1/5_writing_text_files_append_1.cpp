//In this file we will see how to append files.
#include <iostream> 
// In a similar way as 
//iostream (input stream and output stream), fstream (file stream) is used
//to read and write files.

#include <fstream>

using namespace std; 


int main(){

    string sfileName = "example_writing_append_1.txt";
    fstream file;
    
    file.open(sfileName, ios::out);//We open the file in write mode.
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    
        
    file<<"Hello World!\n";
    file<<"This is a new line.\n";
    file<<"This is another new line.\n";
    file<<"This is the last line.\n";
    
    file.close();
   
    //What happens if we try to write more information to the file?
    //The file is already open, so we can't write to it.
    //then, let's open it again in write mode.
    file.open (sfileName, ios::out);//write
    
    if(file.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    //We can write to the file.
      
    file<<"Hello Again!\n";
    file.close();
  
    

    return 0;
}