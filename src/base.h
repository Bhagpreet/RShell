#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base {
    public:
    string boolean; // boolean that stores the result of the previous command 
    string exit; // holds exit status

    Base() {
        exit = "false";
    }; // sets exit status to false

    virtual bool execute() = 0;

};


#endif