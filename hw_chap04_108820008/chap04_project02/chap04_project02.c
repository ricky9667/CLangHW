/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.24                                              */
/* Purpose: reverse a 3 digit integer                            */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter a two-digit number: ");
    scanf("%d",&n); // input n

    printf("The reversal is: ");
    while(n) // break until n becomes 0
    {
        printf("%d",n%10); // output the last digit of n
        n/=10; // remove the last digit by dividing 10
    }

    puts("");
    /* This method can reverse any integer */

    // system("pause");
    return 0;
}