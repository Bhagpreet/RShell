#include "command.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

Command::Command() {}

Command::Command(string val) : val(val) {}

bool Command::execute() {
    while (val.at(0) == ' ') { // Getting rid of whitespace in front of string
        val = val.substr(1);
    }

    while (val.at(val.size() - 1) == ' ') { // Getting rid of whitespace in end of string
        val = val.substr(0, val.size() - 1);
    }

    if (val == "exit") { // if the command is exit, set exit status to true
        exit = "true";
	return false; 
    }
    
    stringstream iss(val);
    vector<string> splitWords;
    string temp;

    while(iss >> temp) {     // splitting words to use for execvp
        splitWords.push_back(temp);
    }

    int stat;
    char* args[splitWords.size() + 1]; // char* created with an increased sized to include the NULL ending to the char array
    int i = 0;
    
    for(i ; i < splitWords.size(); i++) {
        args[i] = (char*)splitWords.at(i).c_str(); // converting strings to cstrings
    }
    args[i] = NULL; 
    
    pid_t pid = fork(); // forking the process
    pid_t wait;
    int status; 
    
    if (pid == 0) { // if at child process
	if (execvp(args[0], args) < 0) { // if the command fails, perror then exit
	    perror("Command failed");
	    std::exit(1);
	}
    }else if(pid > 0) { // checking if the child process is dead
        wait = waitpid(pid, &status, 0);
	    if (wait == -1) {    // checks if wait failed, exits if so 
	       perror("Error");
	       std::exit(1);
	    } 
	    if (WEXITSTATUS(status) == 0) { // checks if theres an exit status. Returns true if there's none 
	        return true;
	    }
    }

    return false;
}