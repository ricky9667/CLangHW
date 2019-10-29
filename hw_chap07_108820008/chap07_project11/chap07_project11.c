/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Rewrite a first and last name                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
	char first[100],last[100];
	
	printf("Enter a first and last name: ");
	scanf("%s %s",first,last); 
		// use to strings to save the first and last name
	printf("%s, %c.\n",last,first[0]); 
		// output the last name and the first letter of the first name
	
	return 0;
}
