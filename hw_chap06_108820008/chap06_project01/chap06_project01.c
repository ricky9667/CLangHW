/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.12                                              */
/* Purpose: find and output the largest number                   */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h> // accessing function atof(char*)
#include<string.h> // accessing function strcpy(char*,char*)

int main()
{
	char c[50],ans[50];
	double input;
    while(1)
    {
    	printf("Enter a number: ");
    	scanf("%s",c);
    	input=atof(c); // converts c into a double type and assign it to input
    	
    	if(input<=0) 
    		break; // break if input is <= 0
    	if(input>atof(ans)) 
			strcpy(ans,c); // copy c to ans if the value of c is larger than ans
	}
	printf("The largest number entered was %s\n",ans); // output the value in string type
    return 0;
}
