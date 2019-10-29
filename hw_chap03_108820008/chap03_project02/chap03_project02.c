/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: ­J²Ð¦t                                                */
/* ID: 108820008                                                 */
/* Date: 2019.09.18                                              */
/* Purpose: Input and output some information of an item         */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
    int item_num,year,month,day;
    double unit_price;
    
    printf("Enter item number : ");
    scanf("%d",&item_num); // input the item number

    printf("Enter unit price : ");
    scanf("%lf",&unit_price); // input the unit price

    printf("Enter purchase date (mm/dd/yyyy) : ");
    scanf("%d/%d/%d",&month,&day,&year); // input the date

    printf("\nItem\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$ %.2f\t\t%02d/%02d/%04d\n",item_num,unit_price,month,day,year); // output the information
    return 0;
}
