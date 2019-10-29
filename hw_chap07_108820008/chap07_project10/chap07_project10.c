/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Count the number of vowels                           */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int isvowel(char c)
{
	if(c=='A' || c=='a') return 1;
	if(c=='E' || c=='e') return 1;
	if(c=='I' || c=='i') return 1;
	if(c=='O' || c=='o') return 1;
	if(c=='U' || c=='u') return 1;
	return 0;
}

int main()
{
	int len=0,i,vowels=0;
	char sentence[1000];
	
	printf("Enter a sentence: ");
	fgets(sentence,sizeof(sentence),stdin); // input a sentence
	
	for(i=0;sentence[i]!='\0';i++)
	{
		if(isvowel(sentence[i])) 
			vowels++;
			// count the number of vowels
	}
	
	printf("Your sentence contains %d vowels.\n",vowels); // output
	
	return 0;
}
