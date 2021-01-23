#ifndef AND_H
#define AND_H

#include "shell.h"

class Command;

using namespace std;

class And : public Shell {
    protected:
    Command* cmd; // stores command object
    public:
    And();
    ~And();
    And(Command*); // passes in command object to set cmd

    bool execute();

};

#endif