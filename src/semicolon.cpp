#include "semicolon.h"
#include "command.h"


using namespace std;

Semicolon::Semicolon() {}

Semicolon::Semicolon(Command* command) : cmd(command) {} // setting command pointer object

Semicolon::~Semicolon(){
    delete cmd;
    cmd = 0;
}

bool Semicolon::execute() {
    bool result = cmd->execute();           // executes command no matter what the result
    if (cmd->exit == "true") {  // sets the exit status to true if the command exit status is true
        exit = "true";
    }
    return result; // returns result of the commmand; 
}