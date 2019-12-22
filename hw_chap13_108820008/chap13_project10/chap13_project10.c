/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.19                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>
#include<string.h>

#define LEN 30

int read_line(char str[], int n)
{
    int i = 0;
    char ch;

    // input
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
}

void reverse_name(char *name)
{
    char f = name[0]; // get first letter of name
    char *p = name;

    // iterate to the end of first name
    while(*p != ' ') p++;
    p++;

    // move last name to the front
    int index = 0;
    while((*p)!='\0') 
        name[index++] = *p, p++;

    // replace the first letter of first name to the end
    name[index++] = ',';
    name[index++] = ' ';
    name[index++] = f;
    name[index++] = '.';
    name[index++] = '\0';
}

int main()
{
    char name[LEN+1];
    
    printf("Enter a first and last name: ");
    // input to name
    read_line(name, LEN);

    // reverse the name order
    reverse_name(name);

    // output
    printf("%s\n", name);

    return 0;
}