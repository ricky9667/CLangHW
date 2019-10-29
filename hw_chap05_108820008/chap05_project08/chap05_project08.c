/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.28                                              */
/* Purpose: Find the closest departure time                      */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int dh[10]={-2,8,9,11,12,14,15,19,21}; 
    // take the latest time to the front by subtracting 24 to avoid time calculation over 0:00
    int dm[10]={45,0,43,19,47,0,45,0,45};
    int ah[10]={-1,10,11,13,15,14,15,21,23};
    int am[10]={58,16,52,31,0,8,55,20,58}; // save the departure and arrival time
    int hour,minute,p=0,i,min,tmp; 

    printf("Enter a 24-hour time: ");
    scanf("%d:%d",&hour,&minute); // input time

    for(i=0;i<8;i++) {
        tmp = abs((hour-dh[i])*60 + minute-dm[i]); // convert time into minutes

        if(tmp<min || !i) min=tmp, p=i; // update the closest time
    }

    printf("Closest departure time is %d:%02d ",((dh[p]>12?dh[p]-12:dh[p])+12)%12,dm[p]);
    if(dh[p]>=0 && dh[p]<12) printf("a.m."); 
    else printf("p.m."); 
    // output
    printf(", arriving at %d:%02d ",((ah[p]>12?ah[p]-12:ah[p])+12)%12,am[p]);
    if(ah[p]>=0 && ah[p]<12) printf("a.m.\n");
    else printf("p.m.\n");
    // output
    system("PAUSE");
    return 0;
}
