#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SIZE 100

int nums[SIZE], top = 0;

// push: add an element to the top of the stack
void push(int i)
{
    // stack overflow
    if(top >= SIZE)
    {
        printf("Expression is too complex\n");
        exit(0);
    }
    nums[top++] = i;
}

// pop: remove an element from the top of the stack
int pop()
{
    // stack underflow
    if(!top) 
    {
        printf("Not enough operands in expression\n");
        exit(0);
    }
    return nums[--top];
}

// clear: remove all elements from the stack
void clear()
{
    top = 0;
}