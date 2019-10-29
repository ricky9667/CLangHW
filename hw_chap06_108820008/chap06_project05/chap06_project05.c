/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.11                                              */
/* Purpose: reverse an integer                                   */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n); // input n

    printf("The reversal is: ");
    
    while(n) // break until n becomes 0
    {
        printf("%d",n%10); // output the last digit of n
        n/=10; // remove the last digit by dividing 10
    }
    puts("");
    return 0;
}
