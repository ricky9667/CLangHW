#include <stdio.h>

#define SIZE ((int) sizeof(flights) / sizeof(flights[0]))

// define and save flight information
struct flight{
    int departure, arrival;
} flights[] = {
    {480, 616}, {583,  712}, { 679,  811}, { 767,  900},
    {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};

void put_time(int time)
{
    // output 12- hour time 
    int hour = time / 60;
    int minute = time % 60;
    if(hour>12) hour-=12;

    printf("%d:%.2d ", hour, minute);
    printf((time < 12*60)?"a.m.":"p.m.");
}

int main()
{
    int hours, minutes, time, closest;

    // input
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    // convert time to minutes
    time = hours*60 + minutes;

    // find closest departure flight
    if(time <= flights[0].departure)
        closest = 0;
    else if(time > flights[SIZE-1].departure)
        closest = SIZE-1;
    else 
    {
        closest = 0;
        while(time > flights[closest+1].departure)
            closest++;
        if((flights[closest+1].departure - time) < (time - flights[closest].departure))
            closest++;
    } 

    // output closest flight information
    printf("Closest departure time is ");
    put_time(flights[closest].departure);
    printf(", arriving at ");
    put_time(flights[closest].arrival);
    puts("");

    return 0;
}