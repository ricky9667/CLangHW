/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.28                                              */
/* Purpose: Find the largest and smallest number                 */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i,max,min,arr[5];
    
    printf("Enter four integers: ");
    scanf("%d",&arr[0]); // input the first number
    max = arr[0], min = arr[0]; // initialize max and min

    for(i=1;i<4;i++) {
        scanf("%d",&arr[i]); // input the 2nd~4th number
        if(arr[i]>max) max = arr[i]; // update max if arr[i] is larger than max
        if(arr[i]<min) min = arr[i]; // update min if arr[i] is smaller than min
    }

    printf("Largest: %d\n",max); // output max value
    printf("Smallest: %d\n",min); // ouput min value

    system("PAUSE");
    return 0;
}