/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.16                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>
#include<ctype.h>

#define MAX_LEN 80

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;
    // count vowels
    while(*sentence != '\0')
        switch(toupper(*sentence++))
            case 'A': case 'E': case 'I': case 'O': case 'U':
                vowels++; // add 1 if current char is a vowel
    return vowels;
}

int read_line(char str[], int n)
{
    int i = 0;
    char ch;

    // input
    while((ch = getchar()) != '\n') // terminate when tapping enter
        if(i < n)
            str[i++] = ch; // put char into string
}

int main()
{
    char sentence[MAX_LEN+1];

    printf("Enter a sentence: ");
    
    // input to sentence
    read_line(sentence, MAX_LEN); 

    // output by using compute_vowel_count
    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
    
    return 0;
}