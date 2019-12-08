/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.27                                              */
/* Purpose: parlindrome                                          */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>

#define MAXN 80

int main()
{
    char message[MAXN];
    char ch, *p = message, *r;

    printf("Enter a message: ");
    // input a message
    while((ch=getchar())!='\n' && (p-message)<MAXN)
    {
        // change all alphabets to lowercase
        if(ch>='A' && ch<='Z')
            ch += ('a'-'A');
        // assign and iterate
        *p = ch, p++;
    }

    // detect if *p from start, *r from end are identical
    for(r=p-1, p=message;p<r;p++, r--)
        if(*p != *r)
            break;

    // output result
    if(p>=r) printf("Parlindrome\n");
    else printf("Not a parlindrome\n");

    return 0;
}