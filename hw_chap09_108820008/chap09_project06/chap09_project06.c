/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.07                                              */
/* Purpose: calcuate a function                                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int polynomial(int x)
{
	// return the calculated result
	return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

int main()
{
	int n;

	printf("Enter an integer: ");
	scanf("%d",&n); // input the integer
	printf("Result: %d\n",polynomial(n)); // output the result of the function
	return 0;
}