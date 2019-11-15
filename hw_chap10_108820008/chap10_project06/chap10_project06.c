/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.14                                              */
/* Purpose:    */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

#define N 100

int stack[N], top=0;
int trigger=0;

void push(int x)
{
	stack[top++]=x;
	if(top>=N) trigger=1;
}

void pop()
{
	if(!top) trigger=-1;
	else top--;
}

void calc(char op)
{
	int y=stack[top-1];
	pop();
	int x=stack[top-1];
	pop();
	int result;
	
	if(trigger==-1) 
		return;

	switch(op)
	{
		case '+': result=x+y; break;
		case '-': result=x-y; break;
		case '*': result=x*y; break;
		case '/': result=x/y; break;
	}
	push(result);
//	printf("%d %c %d = %d\n",x,op,y,result);
//	printf("top = %d, stack[%d] = %d\n",top,top-1,stack[top-1]);
}

int main()
{
	char ch;
	printf("Enter an RPN expression: ");
	while(true)
	{
		scanf("%c",&ch);
		if(ch>='0' && ch<='9')
			push(ch-'0');
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
			calc(ch);
		else if(ch=='=')
		{
			printf("Value of expression : %d\n",stack[--top]);
			trigger=0, top=0;
			printf("Enter an RPN expression: ");
		}
		else break;

		if(trigger==1)
		{
			printf("Expression is too complex\n");
			break;
		}
		if(trigger==-1)
		{
			printf("Not enough operands in expression\n");
			break;
		}
	}
	return 0;
}