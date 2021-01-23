# Rshell

This assignment focuses on creating a c++ basic shell terminal by using a composite pattern. The program is to take in and execute lines of commands from the user that are or are not separated by connectors. These commands are executed by using waitpid, fork, and execvp.

# Usage
When running the code, the terminal would output $, indicating to the user to enter commands for it to execute.

$ ls -a
and.h  and.cpp command.h command.cpp
etc...

# Libraries Used

 - iostream
 - stdio.h
 - unistd.h
 - sys/wait.h
 - sys/types.h
 - stdlib.h
 - using namespace std;

# Known Bugs

 - If the user enters a comment (#) and then follows by any connectors (;, &&, ||), the code would produce an error because of how our code is written. In order to get around it we first found where they marked comment, and then read the string backwards from the comment
 - The connector || does not always work with the exit function. The problem with this function is that not that the exit function doesn't properly execute. but rather the function does not execute a return false statement. It reads all the lines up to that code but when reaching a return false statement or a break statement, the code ignores it and goes over it.

