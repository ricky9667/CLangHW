/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.24                                              */
/* Purpose: fractions!!!!                                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int find_gcd(int x,int y)
{
    if(!y) return x; // x is the gcd if y==0
    return find_gcd(y,x%y); // recurse gcd until terminate
}

void reduce(int nom, int denom, int *re_nom, int *re_denom)
{
    int gcd = find_gcd(nom,denom); // get the gcd
    // divide both by gcd to get lowest terms
    *re_nom = nom/gcd; 
    *re_denom = denom/gcd;
}

int main()
{
    int nom,denom;
    // input
    printf("Enter a fraction: ");
    scanf("%d/%d",&nom,&denom);
    // get lowest terms
    reduce(nom,denom,&nom,&denom);
    // output
    printf("In lowest terms: %d/%d\n",nom,denom);
    return 0;
}