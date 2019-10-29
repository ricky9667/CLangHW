/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Reverse the order of a sentence                      */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

#define MAX_LEN 80

int main()
{
	char ch,end='.',sentence[MAX_LEN]={' '}; // initialize the sentence with a ' '
	int n,i,start,finish;

	printf("Enter a sentence: ");
	for(n=1;n<MAX_LEN;n++)
	{
		ch=getchar(); // input each character to a char array
		if(ch=='.' || ch=='?' || ch=='!')
		{
			// save the terminator to end and break out from the loop
			end=ch; 
			break;
		}
		sentence[n]=ch;
	}

	finish=n; // set finish as the end of a word
	printf("Reversal of sentence: ");
	for(start=n-1;start>=0;start--)
	{
		// find the start of a word by finding a ' '
		if(sentence[start]==' ')
		{
			// output the word
			for(i=start;i<finish;i++)
				putchar(sentence[i]); 
			finish=start; // reset finish
		}
	}
	putchar(end); // output the terminator

	return 0;
}