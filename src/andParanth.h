#ifndef ANDPARANTH_H
#define ANDPARANTH_H

#include <iostream>
#include <vector>
#include "base.h"
#include "shell.h"

using namespace std;

class AndParanth : public Shell {
    private:
    string line;        // holds line of commands
    vector<Base*> list; 
    
    public:
    AndParanth();
    ~AndParanth();
    AndParanth(string); // passes in a string with commands

    void parse(); // parses the string with commands and fills list
 
    bool execute(); // executes the commands depending on the previous command(s) result
};


#endif