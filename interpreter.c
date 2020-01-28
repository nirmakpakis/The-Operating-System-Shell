#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Each command the interpreter() function accepts has a corresponding function that implements the command’s functionality.
// Give the function the same name as the command.

//TODO:
// help: Displays all the commands
// quit:  Exits / terminates the shell with “Bye!”
// set VAR STRING: Assigns a value to shell memory
// print VAR: Displays the STRING assigned to VAR
// run SCRIPT.TXT:  Executes the file SCRIPT.TXT

int interpreter(char *words[])
{

    int errorcode = 0;

    // The user is asking to execute a single command
    if (strcmp(words[0], “help”) errCode = help(words);
    else if (strcmp(words[0], “quit”) errCode = quit(words);
    else if (strcmp(words[0], “set”) errCode = set(words);
    else if (strcmp(words[0], “print”) errCode = print(words);
    else if (strcmp(words[0], “run”) errCode = run(words);

    return errorcode;
}

void help()
{
}

void quit()
{
}

void set()
{
}

void print()
{
}

void run()
{
}