/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Generate a random A-Z map                            */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

#define MAX_LEN 80

int main()
{
	char ch,end='.',sentence[MAX_LEN];//
	int n,i,j,start;

	printf("Enter a sentence: ");
	for(n=0;n<MAX_LEN;n++)
	{
		ch=getchar();
		if(ch=='.'||ch=='?'||ch=='!')
		{
			end=ch;
			break;
		}
		sentence[n]=ch;
	}

	printf("Reversal of sentence: ");
	for(i=n-1;i>=0;i--)
	{
		if(sentence[i]==' ')
			for(j=i+1;sentence[j]!=' ';j++)
				putchar(sentence[i]);
		putchar(' ');
	}
	putchar(end);

	return 0;
}