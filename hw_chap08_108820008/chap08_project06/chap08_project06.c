/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Convert English to B1ff-speak                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

#define MAX_SIZE 100

char convert(char c)
{
	// convert a character to upper case
	if(c>='a' && c<='z') 
		c=c-'a'+'A'; 
	
	// convert some particular characters to numbers and return 
	if(c=='A') return '4';
	if(c=='B') return '8';
	if(c=='E') return '3';
	if(c=='I') return '1';
	if(c=='O') return '0';
	if(c=='S') return '5';

	// return the original character if c is not one of the above
	return c;
}

int main()
{
	char c,message[MAX_SIZE]={0};
	int i=0,size=0;

	printf("Enter message: ");
	
	// save converted characters into a char array
	while((c=getchar()) != '\n' && size<MAX_SIZE)
		message[size++]=convert(c);

	// output the converted message
	printf("In B1ff-speak: %s!!!!!!!!!!\n",message);

	return 0;
}

/*
abcdefghijklmnopqrstuvwxyz
*/