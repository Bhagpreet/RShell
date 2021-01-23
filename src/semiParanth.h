#ifndef SEMIPARANTH_H
#define SEMIPARANTH_H

#include <iostream>
#include <vector>
#include "base.h"
#include "shell.h"

using namespace std;

class SemiParanth : public Shell {
    private:
    string line;        // holds line of commands
    vector<Base*> list; 
    
    public:
    SemiParanth();
    ~SemiParanth();
    SemiParanth(string); // passes in a string with commands

    void parse(); // parses the string with commands and fills list
 
    bool execute(); // executes the commands depending on the previous command(s) result
};


#endif