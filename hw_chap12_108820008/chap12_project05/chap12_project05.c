/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.08                                              */
/* Purpose: parlindrome                                          */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>
#define MAXN 81

int main()
{
    char ch, sentence[MAXN] = {' '}, terminator = '.';
    char *start, *finish = sentence+1, *p = sentence;

    // input
    printf("Enter a sentence: ");
    while(finish <= sentence + MAXN)
    {
        // input a character
        ch = getchar();

        // break when you get a terminate mark
        if(ch == '.' || ch == '!' || ch == '?')
        {
            terminator = ch; // assign ch to terminator
            break;
        }
        *finish++ = ch; // assign ch to the last character and move the pointer
    }

    // output
    printf("Reversal of sentence: ");
    for(start = (finish-1);start >= sentence;start--)
        if(*start == ' ') // output a word when reaching a blank
        {
            // output a word
            for(p = start;p < finish;p++)
                putchar(*p);
            finish = start;
        }
    printf("%c\n",terminator);
    return 0;
}