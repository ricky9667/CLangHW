#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50
#define LEN 60

struct vstring {
    int len;
    char chars[];
};

int read_line(char str[], int n)
{
    int ch, i=0;
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int main()
{
    struct vstring *reminders[MAX];
    char day_str[3], msg_str[LEN+1];
    int day, i, j, num_remind = 0;

    for(;;)
    {
        // too many reminders
        if(num_remind >= MAX)
        {
            printf(" -- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(!day) break;

        // put date number to day_str
        sprintf(day_str, "%2d", day);
        read_line(msg_str, LEN);

        // find the correct location by number order
        for(i=0;i<num_remind;i++)
            if(strcmp(day_str, reminders[i]->chars) < 0)
                break;
        // move other reminders 1 space back
        for(j=num_remind;j>i;j--)
            reminders[j] = reminders[j-1];

        reminders[i] = (struct vstring *)malloc(sizeof(struct vstring) + 2 + strlen(msg_str));
        if(reminders[i] == NULL)
        {
            printf(" -- No space left --\n");
            break;
        }

        // put reminder to reminders
        reminders[i]->len = 2 + strlen(msg_str);
        memcpy(reminders[i]->chars, day_str, 2);
        memcpy(reminders[i]->chars + 2, msg_str, strlen(msg_str));
        num_remind++;
    }

    // output
    printf("\nDay Reminder\n");
    for(i=0;i<num_remind;i++)
        printf(" %*s\n", reminders[i]->len, reminders[i]->chars);

    return 0;
}