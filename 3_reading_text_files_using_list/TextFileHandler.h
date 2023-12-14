#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "LineList.h"
#include <string>
#include <fstream>

using namespace std;

struct TextFileHandler {

    string fileName;

    TextFileHandler(string path) {
        fileName = path;
    }

    LineList readLines() {

        LineList lines;
        
        fstream file;
        
        file.open(fileName, ios::in);
        
        if (file.fail()) {
            return lines;
        }
        string line;

        while (getline(file, line)) {
            lines.add(line);
        }

        file.close();

        return lines;

    }

    void writeLines(LineList lines) {

        fstream file;

        file.open(fileName, ios::out);

        for (int i = 0; i < lines.size; i++) {
            file << lines.get(i) << endl;
        }

        file.close();

    }


};

#endif /* MYHEADER_H */