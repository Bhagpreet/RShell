#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "shell.h"

class Command;

using namespace std;

class Semicolon : public Shell {
    protected:
    Command* cmd; // command object that stores the command within

    public:
    Semicolon();
    ~Semicolon();
    Semicolon(Command*); // passes in object to set cmd

    bool execute(); // executes command object


};

#endif