#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

int main(int argc, char** argv) 
{
    char userInput[50];
    int userNum;
    int quit = 1;
    
    while (quit)
    {
        printf("Enter command (type help for list of commands)\n");
        scanf("%s", &userInput[0]);
        
        if (strcmp(userInput, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
        else if (strcmp(userInput, "enqueue") == 0)
        {
            printf("Enter integer to push\n");
            scanf("%d", &userNum);
            enqueue(userNum);
        }
        else if (strcmp(userInput, "help") == 0)
        {
            printf("List of valid commands:\n");
            printf("enqueue\n");
            printf("dequeue\n");
            printf("quit\n");
        }
        else if (strcmp(userInput, "quit") == 0)
        {
            quit = 0;
        }
        else
        {
            printf("Enter a valid command\n");
        }
    }
    
    return (EXIT_SUCCESS);
}