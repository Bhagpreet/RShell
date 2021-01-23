#include <iostream>
#include "base.h"
#include "shell.h"

using namespace std;

int main(){
        Shell* commands = new Shell();
        commands->execute();
    
    return 0;
}  