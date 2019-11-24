/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.14                                              */
/* Purpose: money!!!                                             */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars/20; // count the amount of twenties
    dollars -= *twenties*20; // remove counted amount
    *tens = dollars/10; // count the amount of tens
    dollars -= *tens*10; // remove counted amount
    *fives = dollars/5; // count the amount of fives
    dollars -= *fives*5; // remove counted amount
    *ones = dollars; // the rest are ones
}

int main()
{
    int amount,twenties,tens,fives,ones;

    // input
    printf("Enter a dollar amount: ");
    scanf("%d",&amount);

    // convert money to different coins
    pay_amount(amount,&twenties,&tens,&fives,&ones);

    // output
    printf("$20 bills : %d\n",twenties);
    printf("$10 bills : %d\n",tens);
    printf("$5 bills : %d\n",fives);
    printf("$1 bills : %d\n",ones);

    return 0;
}