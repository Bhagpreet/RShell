#include "andParanth.h"
#include "or.h"
#include "and.h"
#include "semicolon.h"
#include "orParanth.h"
#include "semiParanth.h"
#include "command.h"
#include <iostream>

using namespace std;

AndParanth::AndParanth(){}

AndParanth::AndParanth(string val) : line(val) {}

AndParanth::~AndParanth(){
    while (list.size() != 0) {
	int i = list.size() - 1;
	delete list.at(i);
	list.at(i) = 0;
	list.pop_back();
    }
}

void AndParanth::parse() {
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
    
    for (int i = marker; i >= 0; i--) { // backwards for loop to run through the vector to store commands
        if (commands.at(i) == ')') { // if i = ')', then loop through till t
            marker = i - 1;
            int paranth = 0;
            for (int j = marker; j >= 0; j--) { // loops backwards starting from marker
                if (commands.at(j) == ')') {
                    paranth++; 
                }else if (commands.at(j) == '(') { 
                    if (paranth > 0) { // if paranth isn't at the correcting opening paranthesis, decrement
                        paranth--;
                    }else { // if paranth = 0, then we are at the correct opening brace and must read in the commands between paranthesis
                        string commandsString = "";
                        for (int k = j + 1; k <= marker; k++) { // loops through to store whats between paranthesis into string
                            commandsString.push_back(commands.at(k));
                        }
                        
                        if (j == 0) {   // if j == 0, we are at the first command which should always be ran, so it's set as a semiParanth
                            list.insert(list.begin(), new SemiParanth(commandsString)); // commandsString stores string thats between ()
                            return;
                        }else if (commands.at(j - 2) == '|' && commands.at(j - 3) == '|') { // if connector is || before (), create a new OrParanth
                            list.insert(list.begin(), new OrParanth(commandsString)); // commandsString stores string thats between ()
                            marker = j - 4; // marker is set before the leftmost '|'
                            i = marker + 1; // i = marker + 1 since i will decrement right after this loop
                            break;
                        }else if (commands.at(j - 2) == '&' && commands.at(j - 3) == '&') { // if connector is && before (), creates a new AndParanth
                            list.insert(list.begin(), new AndParanth(commandsString)); // commandsString stores string thats between ()
                            marker = j - 4; // marker is set before the leftmost '&'
                            i = marker + 1; // i = marker + 1 since i will decrement after this loop
                            break;
                        }else if (j == 0 || commands.at(j - 2) == ';') { // if connecter is ; before (), creates a new semiParanth 
                            list.insert(list.begin(), new SemiParanth(commandsString));
                            marker = j - 3; // marker is set before ';'
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
    if (marker != 0) {    // if marker doesn't reach zero, a command(s) is still within the vector<char> commands
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


bool AndParanth::execute() {
    if (boolean == "true") {
        parse(); // parses commands and fills list

        bool result;         // temporary bool made to store result of bool
        for (int i = 0; i < list.size(); i++) {
            if (i != list.size() - 1){
                result = list.at(i)->execute(); // result holds result of the previous base pointer's result
                cout << endl;
                if (result) {                       // sets boolean which is used in connector classes execute to know to run the command
                    list.at(i + 1)->boolean = "true";
                }else {
                    list.at(i + 1)->boolean = "false";
                }
            }else {
                result = list.at(i)->execute(); // executes final base in list, seperate from setting result to avoid range error
            }
            if (list.at(i)->exit == "true") { // if the exit status has been set to true, exit shell
	            exit = "true";
		        return -1;
            }if (list.at(i)->boolean == "fail") { // if the connector object cannot run based on result, stop running list and return result
                if (i != list.size() - 1) {
                    if (result) {
                        list.at(i + 1)->boolean = "true";
                    }else {
                        list.at(i + 1)->boolean = "false";
                    }
                }
            }
        }
        return result;
    }else {
        boolean = "false"; // bool set to false when connector fails
    }
}