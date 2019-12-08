/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.27                                              */
/* Purpose: parlindrome                                          */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min)
{
    int *p;
    // initialize *a to *min and *max
    *max=*min=*a;
    for(p=a;p<a+n;p++)
    {
        if(*p>*max) // renew *max if *p is larger
            *max=*p;
        if(*p<*min) // renew *min if *p is smaller
            *min=*p;
    }
}

int main()
{
    int b[N], i, big, small;

    // input
    printf("Enter %d numbers: ", N);
    for(i=0;i<N;i++)
        scanf("%d",&b[i]);

    // assign max and min to *big and *small
    max_min(b, N, &big, &small);

    // output max and min
    printf("Largest: %d\n",big);
    printf("Smallest: %d\n",small);
    return 0;
}