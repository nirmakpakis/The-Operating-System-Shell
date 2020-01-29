/**
* Nihal Irmak Pakis
* nihal.pakis@mail.mcgill.ca
* 260733837
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Irmak's shell!\n");
    printf("Version 1.0 Created January 2020\n");
    printf("$");

    char userInput[1000];
    int errorCode = 0;

    while (1)
    {
        fgets(userInput, 999, stdin);
        printf("%s", userInput);
        errorCode = parse(userInput);
        //TODO: check errorCode
        if (errorCode == -1)
        {
            exit(0);
        }
        printf("$");
    }
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
    return interpreter(words);
}
