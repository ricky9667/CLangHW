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
	int i,n;
	
	short s_fact=1;
	int i_fact=1;
	long l_fact=1;
	long long ll_fact=1;
	float f_fact=1;
	double d_fact=1;
	long double ld_fact=1;
	
	printf("Enter a positive integer: ");
	scanf("%d",&n); // input a number 
	
	for(i=1;i<=n;i++) // multiply each variable from 1 to n
	{
		s_fact *= (short) i;
		i_fact *= (int) i;
		l_fact *= (long) i;
		ll_fact *= (long long) i;
		f_fact *= (float) i;
		d_fact *= (double) i;
		ld_fact *= (long double) i;
	}
	
	printf("Factorial of %d (short)       : %hd\n",n,s_fact);
	printf("Factorial of %d (int)         : %d\n",n,i_fact);
	printf("Factorial of %d (long)        : %ld\n",n,l_fact);
	printf("Factorial of %d (long long)   : %lld\n",n,ll_fact);
	printf("Factorial of %d (float)       : %f\n",n,f_fact);
	printf("Factorial of %d (double)      : %f\n",n,d_fact);
	printf("Factorial of %d (long double) : %Lf\n",n,ld_fact);
	// output n! in different types
	
	return 0;
}
