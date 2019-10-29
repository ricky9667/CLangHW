/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Adding 2 fractions                                   */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
	int num1,denom1,num2,denom2;
	printf("Enter two fractions seperated by a plus sign : \n");
	scanf("%d/%d+%d/%d",&num1,&denom1,&num2,&denom2); //input two fractions
	
	printf("The sum is %d/%d\n",num1*denom2+num2*denom1,denom1*denom2); // calculate and output the result
	return 0;
}
