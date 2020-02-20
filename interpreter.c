/**
 *
 * @author Irmak Pakis
 * @dateCreated  29th January 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interpreter.h"

int interpreter(char *words[], int size)
{
    int errorcode = 0;

    if (strcmp(words[0], "help") == 0)
    {
        if (size != 1)
        {
            printf("HELP does not accept any arguments!\n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = help();
    }
    else if (strcmp(words[0], "quit") == 0)
    {
        if (size != 1)
        {
            printf("QUIT does not accept any arguments!n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = quit();
    }
    else if (strcmp(words[0], "set") == 0)
    {
        if (size != 3)
        {
            printf("SET accepts 2 arguments only!\n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = set(words);
    }
    else if (strcmp(words[0], "print") == 0)
    {
        if (size != 2)
        {
            printf("PRINT accepts 1 argument only!\n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = print(words);
    }
    else if (strcmp(words[0], "run") == 0)
    {
        if (size != 2)
        {
            printf("RUN ACCEPTS 1 ARGUMENT ONLY\n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = run(words[1]);
    }
    else if (strcmp(words[0], "exec") == 0)
    {
        if (size > 4)
        {
            printf("EXEC ACCEPTS AT MOST 3 ARGUMENTS \n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        if (size < 2)
        {
            printf("EXEC ACCEPTS AT LEAST 1 ARGUMENT \n");
            return WRONG_NUMBER_OF_ARGUMENTS;
        }
        errorcode = exec(words, size);
    }
    else
    {
        errorcode = INVALID_COMMAND;
    }

    return errorcode;
}

int help()
{
    printf("COMMANDS: \
                    \n  help: Displays all the commands\
                    \n  quit: Exits / terminates the shell with “Bye!”\
                    \n  set <VAR> <STRING>: Assigns a value to shell memory\
                    \n  print <VAR>: Prints the STRING assigned to VAR\
                    \n  run SCRIPT.TXT: Executes the file SCRIPT.TXT\
                    \n  exect <p1> <p2> <p2>: Executes concurrent programs \n");
    return 0;
}

int quit()
{
    printf("Bye!\n");
    return QUIT_SHELL;
}

int set(char *words[])
{
    char *key = words[1];
    char *value = words[2];
    int errorCode = insert(key, value);
    if (errorCode != MEMORY_EXCEED)
        printf("The variable %s is set to %s \n", key, value);
    return errorCode;
}

int print(char *words[])
{
    return get(words[1]);
}

int run(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        return FILE_NOT_FOUND;
    }

    char text_input[100] = {0};

    while (fgets(text_input, sizeof(text_input), file))
    {
        int errorCode = parse(text_input);
        switch (errorCode)
        {
        case QUIT_SHELL:
            exit(0);
        }
    }
    fclose(file);
    return 0;
}

int exec(char *words[], int size)
{
    for (int i = 1; i < size; i++)
    {
        char *program = words[i];
        FILE *file = fopen(program, "r");
        if (file == NULL)
        {
            return FILE_NOT_FOUND;
        }
        else
        {
            myinit(program);
        }
        fclose(program);
    }
    schedule();
    return 0;
}
