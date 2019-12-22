/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.16                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i, sum = 0;

    for(i=1;i<argc;i++) 
        sum += atoi(argv[i]); // convert numbers from string to int and add to sum

    // output
    printf("Total: %d\n",sum);
    return 0;
}