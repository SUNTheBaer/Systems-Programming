#include "Stack.h"

int secondStack [1000];

void enqueue (int entity)
{
    push(entity);
}

int dequeue()
{
    if (top <= 0)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else 
    {
        int result;
        int count = 0;

        while (top > 0)
        {
            secondStack[count++] = pop();
        }

        result = secondStack[--count];
        count--;
        
        for (int i = count; i >= 0; i--)
        {
            push(secondStack[i]);
        }

        return result;
    }
}