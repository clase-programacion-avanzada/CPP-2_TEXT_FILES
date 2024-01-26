#ifndef LINELIST_H
#define LINELIST_H

#include <string>
#include <sstream>
using namespace std;

struct LineList {
    string lines[100];
    int size;

    LineList() {
        size = 0;
    }

    void add(string line) {
        lines[size] = line;
        size++;
    }

    bool remove(int index) {

        if (index < 0 || index >= size) {
            return false;
        }

        for (int i = index; i < size - 1; i++) {
            lines[i] = lines[i + 1];
        }
        size--;

        return true;
    }

    string get(int index) {
        return lines[index];
    }

    bool contains(string line) {
        for (int i = 0; i < size; i++) {
            if (lines[i] == line) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        size = 0;
    }

    LineList copy(LineList other) {
        LineList newList;
        
        for (int i = 0; i < other.size; i++) {
            newList.add(other.lines[i]);
        }

        return newList;

    }

};

#endif /* MYHEADER_H */

