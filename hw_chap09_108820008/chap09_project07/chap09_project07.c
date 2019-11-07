/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.07                                              */
/* Purpose: Calculate x^n				                         */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int power(int x,int n)
{
	if(!n) return 1; // return 1 if the power is 0
	if(n==1) return x; // return x if the power is 1
	if(n%2) return x*pw(x,n-1); // odd case: return x*x^(n-1)
	return pw(x,n/2)*pw(x,n/2); // even case: return (x^(n/2))^2
}

int main()
{
	int x,n;

	// input base and power
	printf("For x^n, enter x: ");
	scanf("%d",&x);
	printf("Enter n: ");
	scanf("%d",&n);

	printf("%d^%d = %d\n",x,n,power(x,n));
	return 0;
}