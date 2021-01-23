# Rshell

This assignment focuses on creating a c++ basic shell terminal by using a composite design pattern. The program is to take in and execute lines of commands from the user that may or may not be separated by connectors. The connectors are the logical operators that can be ran along with the commands. These commands are executed by using waitpid, fork, and execvp.

# Usage
The program requires cmake, googletest, and c++11 to run properly with the setup.

When running the code, the terminal will output $, indicating to the user to enter commands for it to execute.
e.g. $ ls -a


# Libraries Used

 - iostream
 - stdio.h
 - unistd.h
 - sys/wait.h
 - sys/types.h
 - stdlib.h
 - gtest/gtest.h (for testing)

# Known Bugs

 - If the user enters a comment (#) and then follows by any connectors (;, &&, ||), the code would produce an error because of how our code is written. In order to get around it we first found where they marked comment, and then read the string backwards from the comment.
 - The connector || does not always work with the exit function. The problem with this function is that not that the exit function doesn't properly execute. but rather the function does not execute a return false statement. It reads all the lines up to that code but when reaching a return false statement or a break statement, the code ignores it and goes over it.

