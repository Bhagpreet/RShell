#include "shell.h"
#include "command.h"
#include "semicolon.h"
#include "and.h"
#include "or.h"
#include "andParanth.h"
#include "semiParanth.h"
#include "orParanth.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

Shell::Shell() {}

Shell::Shell(string val) : line(val) {} // passing in a user passed in string

Shell::~Shell() {
    while (list.size() != 0) {
	int i = list.size() - 1;
	delete list.at(i);
	list.at(i) = 0;
	list.pop_back();
    }
}

void Shell::parse() {
    while (!list.empty()) { // clears any previous command calls on the command line
	delete list.at(list.size() - 1);
        list.pop_back();
    }

    vector<char> commands;

    while(line.size() != 0) {
        commands.push_back(line.at(0)); // pushing string with commands into a vector of characters
        if(line.size() == 1) {
            break;
        }
        line = line.substr(1);
    }

    int marker = commands.size() - 1; // the marker is here to determine the last index of the command that is to be ran in
    for (int i = commands.size() - 1; i >= 0; i--) { 
        
        if (commands.at(i) == '#') { // if there are any comments, set the marker to index before # in order to read in the command before comment
            marker = i - 1;
        }
    }

    int counter = 0;
    for (int i = 0; i <= marker; i++) { // checks to see if there are the same number of '(' relative to ')'
        if (commands.at(i) == '(') {
            counter++;
        }else if (commands.at(i) == ')') {
            counter--;
        }
    }

    if (counter != 0) { // if counter != 0, then there was an extra or missing paranthesis i.e. "((echo test)"
        cout << "Error with paranthesis" << endl;
        exit = "true";
        return;
    }   
    
    for (int i = marker; i >= 0; i--) { // backwards for loop to run through the vector to store commands
        if (commands.at(i) == ')') { // used to read in paranthesis connectors
            marker = i - 1;
            int paranth = 0;
            for (int j = marker; j >= 0; j--) { 
                if (commands.at(j) == ')') { // increments paranth to make sure the correct paranthesis is parsed with its corresponding paranthesis
                    paranth++; 
                }else if (commands.at(j) == '(') { // decrements paranth to make sure correct paranthesis are parsed
                    if (paranth > 0) {  
                        paranth--;
                    }else {
                        string commandsString = "";
                        
                        for (int k = j + 1; k <= marker; k++) { // loops through what was between paranthesis to  
                            commandsString.push_back(commands.at(k));
                        }
                        if (j == 0) { // means that this is the last commands being parsed, creates SemiParanth since first command must always be ran
                            list.insert(list.begin(), new SemiParanth(commandsString));
                            return;
                        }else if (commands.at(j - 2) == '|' && commands.at(j - 3) == '|') { // if || connector before (), create new OrParanth
                            list.insert(list.begin(), new OrParanth(commandsString));
                            marker = j - 4;  // sets marker before the leftmost '|'
                            i = marker + 1;  // i is set to marker + 1 since for loop will decrement i after this run, continues parse from that point
                            break;
                        }else if (commands.at(j - 2) == '&' && commands.at(j - 3) == '&') { // if && connector before (), create new AndParanth
                            list.insert(list.begin(), new AndParanth(commandsString));
                            marker = j - 4; // sets marker before the leftmost '&'
                            i = marker + 1; // i is set to marker + 1 since for loop will decrement
                            break;
                        }else if (j == 0 || commands.at(j - 2) == ';') { // if ; connector before (), create new SemiParanth
                            list.insert(list.begin(), new SemiParanth(commandsString));
                            marker = j - 3; // sets marker before ';'
                            i = marker + 1;
                            break;
                        }
                    }
                }
            }
        }else if (commands.at(i) == ';') { // if semicolon, create a new semicolon object with the temp string command
            string commandString = "";

            for (int j = i + 1; j <= marker; j++) { // reads chars into temp string from index after ';' and stops at marker
                commandString.push_back(commands.at(j));
            }

            list.insert(list.begin(), new Semicolon(new Command(commandString))); // adding semicolon w/ command in front of connrctor into vector
            marker = i - 1;                           // setting the marker index before the connector to read in next command
            i = marker + 1;
        }else if (commands.at(i) == '&' && commands.at(i - 1) == '&') { // if and, create a new and object with temp string command
            string commandString = "";

            for (int j = i + 1; j <= marker; j++) { // reads chars into temp string from index after '&' and stops at marker
                commandString.push_back(commands.at(j));
            }

            list.insert(list.begin(), new And(new Command(commandString))); // adding and w/ command in front of connector into vector
            marker = i - 2;      // setting marker two indices before the rightmost '&' read in
            i = marker;

        }else if (commands.at(i) == '|' && commands.at(i - 1) == '|') { // if or, create a new or object with temp string command
            string commandString = "";

            for (int j = i + 1; j <= marker; j++) { // reads chars into temp string from index after '|' and stops at marker
                commandString.push_back(commands.at(j));
            }

            list.insert(list.begin(), new Or(new Command(commandString)));
            marker = i - 2;              // setting marker two indices before the rightmost '|' read in
            i = marker;
        }
    }
    if (marker != 0) {    // if marker doesn't reach zero, a command is still within the vector<char> commands
        string first = "";
        for (int i = 0; i <= marker; i++) { // pushes chars into a temp string
            first.push_back(commands.at(i));
        }
        if (commands.at(0) == '(' && commands.at(marker - 1) == ')') {
            list.insert(list.begin(), new SemiParanth(first));
        }else {
            list.insert(list.begin(), new Semicolon(new Command(first))); // adds new semicolon object for the command to run initial command
        }
    }
}

bool Shell::execute() {
    do {           // looping in order to be able to execute multiple lines with commands/comments
        char hostname[HOST_NAME_MAX]; // holds the hostname
        gethostname(hostname, HOST_NAME_MAX);
        cout << getenv("USER");      // outputs username taken from stdlib library
        cout << '@';
        for (int i = 0; i < HOST_NAME_MAX ; i++){ // outputs host name, taken from unistd library
            if (!isalpha(hostname[i]) && !isdigit(hostname[i]) && hostname[i] != '-') {
		        break;
	        }else {
	            cout << hostname[i];
	        }
        }
        
        cout << "$ ";  // prints out $ to show that you are within the shell
        getline(cin, line);
        cout << endl;

        if (line != "") { // only runs the string command if there are values within it
            parse(); // parses commands and fills list
            if (exit == "true") {
                std::exit(-1);
            }
            bool result;         // temporary bool made to store result of bool 
            for (int i = 0; i < list.size(); i++) {
                if (i != list.size() - 1){
                    result = list.at(i)->execute(); // result holds result of the previous base pointer's result
                    if (result) {                       // sets boolean which is used in connector classes execute to know to run the command
                        list.at(i + 1)->boolean = "true";
                    }else {
                        list.at(i + 1)->boolean = "false";
                    }
                }else {
                    list.at(i)->execute(); // executes final base in vector, seperate from setting result to avoid range error
                }
                if (list.at(i)->exit == "true") { // if the exit status has been set to true, exit shell
		            std::exit(0);
		            return 1;
                }if (list.at(i)->boolean == "fail") { // if the connector object cannot run based on result, breaks the line of commands being ran
		            if (i != list.size() - 1) {
                        if (result) {
                            list.at(i + 1)->boolean = "true";
                        }else {
                            list.at(i + 1)->boolean = "false";
                        }
                    }
                }
                cout << endl;
            }
            line = "";
        }
    }while(exit == "false"); // run loop to take in lines of commands till exit status is set to true 
}