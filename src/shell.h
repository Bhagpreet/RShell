#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include "base.h"

class Semicolon;

using namespace std;


class Shell : public Base {
    protected:
    string line;
    vector<Base*> list;

    public:
    Shell();
    ~Shell();
    Shell(string val); // passes in a string with all the commands
    
    void parse(); // parses the string with commands into vector<Base*>

    bool execute(); // runs the shells looping function as well as executes the and, or, semicolon connectors in the vector list
};


#endif