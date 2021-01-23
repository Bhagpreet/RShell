#include "and.h"
#include "command.h"
#include <stdlib.h>

using namespace std;

And::And() {}

And::And(Command* command) : cmd(command) {} // sets command pointer object

bool And::execute() {
    if (boolean == "true") { // only the command object if boolean/previous command's result is true
        bool val = cmd->execute();
        if (cmd->exit == "true") { // if exit status is set to true in command, set connector object exit status to true 
            exit = "true";
        }
        return val; // returns result of command based on if the command ran or not
    }else if (boolean == "") { // if empty, the object is the only thing that needs to be ran left
        cmd->execute();
    }else {             // sets boolean to fail if the next command is not supposed to run based on previous commands result
        boolean = "fail";
    }
}
