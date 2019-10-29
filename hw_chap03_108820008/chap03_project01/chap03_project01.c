/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Input and output a date                              */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
    int year,month,day;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&month,&day,&year); // input the month, day, and year

    printf("You entered the date %04d%02d%02d\n",year,month,day); // output the date
    return 0;
}
