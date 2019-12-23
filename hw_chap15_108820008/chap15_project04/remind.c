/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.19                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include <stdio.h>
#include <string.h>
#include "readline.h"

#define MAX 50 /* maximum number of reminders */
#define LEN 60 /* max length of reminder message */

int main()
{
    char reminders[MAX][LEN+3];
    char day_str[3], msg[LEN+1];
    int day, i, j, reminds = 0;

    for(;;reminds++) // counts the number of reminders
    {
        // notify if there are too many reminders
        if(reminds >= MAX)
        {
            printf("-- No space left --\n");
            break;
        }

        // input date
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(!day) break;

        // move the date to day_str
        sprintf(day_str, "%2d", day);
        // read the reminder
        read_line(msg, LEN);

        // find the correct location to put the reminder by date order
        for(i=0;i<reminds;i++)
            if(strcmp(day_str, reminders[i])<0)
                break;

        // move back reminders that are later that the current reminder
        for(j=reminds;j>i;j--)
            strcpy(reminders[j], reminders[j-1]);

        // insert the reminder
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg);
    }

    printf("\nDay Reminder\n");
    for(i=0;i<reminds;i++)
        printf(" %s\n", reminders[i]);

    return 0;
}