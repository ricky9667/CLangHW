#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i=0;

    // input char to the end of str
    while((ch=getchar()) != '\n')
        if(i < n)
            str[i++] = ch;

    // add '\0' to mark as the end of the string
    str[i] = '\0';

    // retern the length of str
    return i;
}