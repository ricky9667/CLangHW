/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Convert a phone number                               */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

char convert(char c)
{
	// create a function to convert English alphabets to numbers
	if(c>='A' && c<='C') return '2';
	if(c>='D' && c<='F') return '3';
	if(c>='G' && c<='I') return '4';
	if(c>='J' && c<='L') return '5';
	if(c>='M' && c<='O') return '6';
	if(c>='P' && c<='S' && c!='Q') return '7';
	if(c>='T' && c<='V') return '8';
	if(c>='W' && c<='Y') return '9';
	return c; 
	// the digit remains the same if the current digit is not an English alphabet
}

int main()
{
	int i;
	char phone[100];
	
	printf("Enter phone number: ");
	scanf("%s",phone); // input phone number
	
	for(i=0;phone[i]!='\0';i++)
		printf("%c",convert(phone[i]));
		// output the converted digit	
	printf("\n");
	
	return 0;
}
