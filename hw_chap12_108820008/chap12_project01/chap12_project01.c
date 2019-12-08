/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.27                                              */
/* Purpose: reverse sentence                                     */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>

#define MAXN 100

int main()
{
    char message[MAXN];
    char c, *p = message;

    printf("Enter a message: ");
    // input character
    while((c=getchar())!='\n' && (p-message)<MAXN)
        *p = c, p++; // put c in message by iterating *p

    printf("Reversal is: ");
    // iterate backwards to reverse
    for(p--;p!=message;p--) 
        putchar(*p);
    printf("%c\n",*p); 

    return 0;
}