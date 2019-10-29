/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Input and output a phone number                      */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
	int area_code,prefix,number;
	
	printf("Enter phone number [(xxx) xxx-xxxx] : ");
	scanf("(%d) %d-%d",&area_code,&prefix,&number); // input area code, prefix, and number
	printf("You entered %03d.%03d.%04d\n",area_code,prefix,number); // output phone number
	return 0;
}
