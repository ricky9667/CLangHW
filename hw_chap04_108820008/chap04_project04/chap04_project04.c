/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.24                                              */
/* Purpose: converts decimal to octal                            */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,ans=0,i;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d",&n); // input n
    for(i=1;n>0;i*=10,n/=8) // stop when n becomes 0
        ans+=i*(n%8); 
        // puts every octal digit into ans, i iterates to the next digit of ans 
        // n is divided by 8 to get the next octal digit
    printf("In octal, your number is: %05d\n",ans); // output ans (octal) with 5 digits
    // system("pause");
    return 0;
}