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
}

void parse(char ui[])
{

    char tmp[200];
    int a, b;
    char *words[100];
    int w = 0; // wordsIdx

    //Skipping white spaces
    for (a = 0; ui[a] == ' ' && a < 1000; a++)
        ;

    while (ui[a] != '\0' && a < 1000)
    {

        for (b = 0; ui[a] != '\0' && ui[a] != ' ' && a < 1000; a++, b++)
            tmp[b] = ui[a]; // extract a word

        tmp[b] = '\0';
        words[w] = strdup(tmp);
        a++;
        w++;
    }
    // assumes: cmd switches args
    return interpreter(words);
}
