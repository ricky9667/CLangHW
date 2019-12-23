/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.19                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int x, y;
    char ch;

    printf("Enter an RPN expression: ");
    for(;;)
    {
        // input 
        scanf(" %c", &ch);

        if(ch>='0' && ch<='9') push(ch-'0'); // push the integer into the stack
        else if(ch=='+') 
        {
            // push the result of the addition of the top 2 operands
            push(pop() + pop());
        }
        else if(ch=='-') 
        {
            // push the result of the subtraction of the top 2 operands
            y=pop(), x=pop();
            push(x - y);
        }
        else if(ch=='*') 
        {
            // push the result of the multiplication of the top 2 operands
            push(pop() * pop());
        }
        else if(ch=='/')
        {
            // push the result of the division of the top 2 operands
            y=pop(), x=pop();
            push(x / y);
        }
        else if(ch=='=')
        {
            // get the result
            printf("Value of expression: %d\n", pop());
            // clear the stack
            clear();
            printf("Enter an RPN expression: ");
        }
        else break; // exit if input is not valid
    }
    return 0;
}