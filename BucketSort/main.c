#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bucket.h"
#define NUMBUCKS 8

int main(int argc, char** argv)
{
    char* userInput;
    int quit = 1;
    
    while (quit)
    {
        printf("Type a word\n");
        scanf("%s", userInput);
        char* aWord = (char *)malloc(strlen(userInput)+1);
        
        if (strcmp(userInput, "Sort") == 0)
        {
            SortAndPrintBucket();
            quit = 0;
        }
        else if (strcmp(userInput, "Quit") == 0)
        {
            quit = 0;
        }
        else
        {
            PassString(userInput);
        }
    }
    
    return (EXIT_SUCCESS);
}

