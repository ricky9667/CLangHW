/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.19                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include<stdio.h>

int main()
{
    int m, d, y;
    // list 12 months
    char Months[15][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter a date (mm/dd/yyyy): ");
    // input date
    scanf("%d / %d / %d", &m, &d, &y);
    // change month to string and output
    printf("You entered the date %s %.2d, %d", Months[m-1], d, y);

    return 0;
}