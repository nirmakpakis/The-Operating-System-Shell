/**
 *
 * @author Irmak Pakis
 * @dateCreated  29th January 2020
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

int shellUI()
{
    printf("Welcome to the Irmak's shell!\n");
    printf("Version 1.0 Created January 2020\n");
    printf("$ ");

    char userInput[1000];
    printf("%s", userInput);
    int errorCode = 0;

    while (1)
    {
        fgets(userInput, 999, stdin);
        errorCode = parse(userInput);
        switch (errorCode)
        {
        case QUIT_SHELL:
            exit(0);
            break;
        case INVALID_COMMAND:
            printf("Invalid Command!\n");
            break;
        case VARIABLE_DOES_NOT_EXISTS:
            printf("Variable Does Not Exist\n");
            break;
        case MEMORY_EXCEED:
            printf("Memory Exceeded!\n");
            break;
        case FILE_NOT_FOUND:
            printf("Script Not Found!\n");
            break;
        case RAM_MEMORY_EXCEED:
            printf("Ram Memory Exceeded!\n");
            break;
        }
        printf("$ ");
    }

    return errorCode;
}

int parse(char ui[])
{

    char tmp[200];
    int a = 0;
    int b = 0;
    char *words[100];
    int w = 0; // wordsIdx

    //Skipping white spaces
    for (a = 0; ui[a] == ' ' && a < 1000; a++)
        ;

    while (ui[a] != '\0' && ui[a] != '\n' && ui[a] != '\r' && a < 1000)
    {

        for (b = 0; ui[a] != '\0' && ui[a] != '\n' && ui[a] != '\r' && ui[a] != ' ' && a < 1000; a++, b++)
            tmp[b] = ui[a]; // extract a word

        tmp[b] = '\0';
        words[w] = strdup(tmp);
        a++;
        w++;
    }
    // assumes: cmd switches args
    return interpreter(words, w);
}
