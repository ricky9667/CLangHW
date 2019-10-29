/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.24                                              */
/* Purpose: calculates the EAN check digit                       */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num[15],i,ans=0;
    printf("Enter the first 12 digits of an EAN: ");
    for(i=1;i<=12;i++) scanf("%1d",&num[i]); // input and split the number into 12 digits

    for(i=2;i<=12;i+=2) ans+=num[i]; // first sum
    ans*=3; // mutiply the first sum by 3
    for(i=1;i<=12;i+=2) ans+=num[i]; // add the second sum to ans
    ans--; // subtract 1 from ans
    ans%=10; // ans becomes the remainder of the original ans
    ans=9-ans; // subtract the remainder from 9

    printf("Check digit: %d\n",ans); // output the ans(check digit)
    // system("pause");
    return 0;
}