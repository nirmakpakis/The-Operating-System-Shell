/**
* Nihal Irmak Pakis
* 260733837
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int interpreter(char *words[])
{
    int errorcode = 0;
    if (strcmp(words[0], "help") == 0)
    {
        errorcode = help();
    }
    else if (strcmp(words[0], "quit") == 0)
    {
        errorcode = quit();
    }
    else if (strcmp(words[0], "set") == 0)
    {
        errorcode = set(words);
    }
    else if (strcmp(words[0], "print") == 0)
    {
        errorcode = printKey(words);
    }
    else if (strcmp(words[0], "run") == 0)
    {
        errorcode = run(words[1]);
    }
    else
    {
        printf("Unknown command!\n");
    }

    return errorcode;
}

int help()
{
    printf("COMMAND DESCRIPTION \
                    \n  help: Displays all the commands\
                    \n  quit: Exits / terminates the shell with “Bye!”\
                    \n  set <VAR> <STRING>: Assigns a value to shell memory\
                    \n  print <VAR>: Prints the STRING assigned to VAR\
                    \n  run SCRIPT.TXT: Executes the file SCRIPT.TXT\n");
    return 0;
}

int quit()
{
    printf("Bye!\n");
    return -1;
}

int set(char *words[])
{
    char *key = words[1];
    char *value = words[2];
    if (insert(key, value))
    {
        printMemory();
        printf("The variable %s is set to %s \n", key, value);
        return 0;
    }
    return 10;
}

int printKey(char *words[])
{
    get(words[1]);
    return 0;
}

int run(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("ERROR: Script not found\n");
        return 0;
    }

    char text_input[100] = {0};
    int errCode = 0;

    while (fgets(text_input, sizeof(text_input), file))
    {
        int errorCode = parse(text_input);
        switch (errorCode)
        {
        case -1:
            exit(0);
        }
    }
    fclose(file);
    return 0;
}
