#include <stdio.h>
#include <stdlib.h>

int stack[1000];
int top = 0;

void push(int data)
{
    stack[top++] = data;
}

int pop()
{
    if (top <= 0)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        return stack[--top];
    }
}