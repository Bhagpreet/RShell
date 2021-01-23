#ifndef COMMAND_H
#define COMMAND_H

#include "base.h"

using namespace std;

class Command : public Base {
    public:
    string val; // holds single command arguement, i.e. "ls -a"

    Command();
    Command(string val); // string passed in holds commmand

    bool execute(); // executes command and returns true if command worked and false if failed

};

#endif