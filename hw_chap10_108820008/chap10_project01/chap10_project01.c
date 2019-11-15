/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.14                                              */
/* Purpose: test if parentheses and braces are nested properly   */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 100

char stack[N]; // stack of string
int top=0; // the top index of string

void push(char c) // pushes a character into the stack
{
	stack[top++]=c;
}

void pop() // pops out a character from the stack
{
	top--;
}

int main()
{
	int nested=1; // check if nested properly
	int trigger=0; // check if there is a stack underflow or overflow
	char ch; // input character

	printf("Enter parentheses and/or braces: ");
	while(nested && !trigger && (ch=getchar()) !='\n') // break if a \n character is input
	{
		if(ch==')')
		{
			if(!top) 
				trigger=-1; // mark as underflow if stack pops when top is 0
			else if(stack[top-1]!='(')
				nested=0; // the parentheses are not nested if the top of the stack doesn't match the input
			else 
				pop(); // pop out if the parentheses match
		}
		else if(ch=='}')
		{
			if(!top) 
				trigger=-1; // mark as underflow if stack pops when top is 0
			else if(stack[top-1]!='{')
				nested=0; // the braces are not nested if the top of the stack doesn't match the input
			else 
				pop(); // pop out if the parentheses match
		}
		else 
		{
			if(top>=N)
				trigger=1; // mark as overflow if stack is full
			else
				push(ch); // push if the stack has enough size
		}
	}

	if(trigger==1)
		printf("Stack overflow\n");
	else if(trigger==-1)
		printf("Stack underflow\n");
	else 
	{
		if(nested && !top)
			printf("Parentheses/braces are nested properly\n");
		else
			printf("Parentheses/braces are NOT nested properly\n");		
	}

	return 0;
}