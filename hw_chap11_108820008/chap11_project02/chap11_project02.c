/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.24                                              */
/* Purpose: airplane!!!!!                                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int abs(int x)
{
    // convert a negative number positive
    if(x<0) return -x;
    return x;
}

void find_closest_flight(int time, int *departure, int *arrival)
{
    // store the departure and arrival of all flights
    // the last time is to avoid overnight calculation
    int d[] = {480,583,679,767,840,945,1140,1305,1920};
    int a[] = {616,712,811,900,968,1075,1280,1438,2056};
    // initialize min_index and closest_time
    int min_index=0, closest_time=abs(time-d[0]);

    // find the closest flight relative to the given time
    for(int i=1;i<9;i++)
        if(abs(time-d[i])<closest_time)
            min_index=i, closest_time=abs(time-d[i]);
    
    // assign closest departure and arrival to the pointers
    *departure = d[min_index];
    *arrival = a[min_index];
}

int main()
{
    int hour, minute;
    int departure, arrival;

    // input
    printf("Enter a 24-hour time: ");
    
    // get closest flight
    find_closest_flight(hour*60 + minute, &departure, &arrival);

    // output
    departure %= 1440, arrival %= 1440;
    printf("Closest departure time is %2d:%02d, arriving at %2d:%02d\n",departure/60,departure%60,arrival/60,arrival%60);

    return 0;
}