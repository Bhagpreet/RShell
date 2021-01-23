#include "or.h"
#include "command.h"
#include <stdlib.h>

using namespace std;

Or::Or() {}

Or::Or(Command* command) : cmd(command) {} // sets command pointer object

Or::~Or(){
    delete cmd;
    cmd = 0;
}

bool Or::execute() {
    if (boolean == "false") {   // runs the command if the boolean/previous command's result is false
	bool val = cmd->execute();
        if (cmd->exit == "true") { // if exit status is set to true in command, set connector object exit status to true 
            exit = "true";
        }
        return val;     // returns result of command based on if the command ran or not
    }else {          // sets boolean to fail if the next command is not supposed to run based on previous commands result
	    boolean = "fail";
    }
}