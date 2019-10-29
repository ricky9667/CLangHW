/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.11                                              */
/* Purpose: reduct a fraction to lowest terms                    */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int gcd(int x,int y)
{
	if(!y) return x; // x is the greatest common divisor if y becomes 0
	return gcd(y,x%y); // recall the function gcd, while gcd(x,y)=gcd(y,x%y)
}

int main()
{
    int top,bot,divide;
    
    printf("Enter a fraction: ");
    scanf("%d/%d",&top,&bot); 
    	//input the top and bottom of a fraction
    
    divide=gcd(top,bot); 
		// assign divide the greatest common divisor of top and bot
		
    printf("In lowest terms: %d/%d\n",top/divide,bot/divide); 
    	// output the lowest terms by dividing top and bot by divide
    return 0;
}
