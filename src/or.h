#ifndef OR_H
#define OR_H

#include "shell.h"

class Command;

using namespace std;

class Or : public Shell {
    protected:
    Command* cmd;
   
    public:
    Or();
    ~Or();
    Or(Command*); // sets commmand object which holds the command within

    bool execute(); // executes the command based on previous result

};

#endif