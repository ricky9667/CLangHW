/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.22                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include <stdio.h>
#include "quicksort.h"

#define N 10

int main()
{
    int a[N], i;

    // input
    printf("Enter %d numbers to be sorted: ", N);
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);

    // quicksort
    quicksort(a, 0, N-1);

    // output
    printf("In sorted order: ");
    for(int i=0;i<N;i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}