#ifndef FILEHANDLER_H
#define FILEHANDLER_H


#include <string>
#include <sstream>
#include <fstream>

struct Lines {
    char lines[100][256];
    int size;

    Lines() {
        size = 0;
    }
};

#endif /* MYHEADER_H */