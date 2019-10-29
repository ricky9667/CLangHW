/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.11                                              */
/* Purpose: calculate natural number e                           */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
    int n,i; 
    long long fac=1; // calculate 1!~n!
    double ans=1;

    printf("Enter a number: ");
    scanf("%d",&n); // input n
	
	for(i=1;i<=n;i++)
	{
		fac*=i; // make fac=i!
		ans+=(1.0f/fac); // add (1/!i) to ans
	}
	
	printf("%f\n",ans); // output the answer
    return 0;
}
