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

    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
}

void reverse_name(char *name)
{
    char f = name[0];
    char *p = name;

    while(*p != ' ') p++;
    p++;

    int index = 0;
    while((*p)!='\0') 
        name[index++] = *p, p++;

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
    read_line(name, LEN);

    reverse_name(name);
    printf("%s\n", name);

    return 0;
}