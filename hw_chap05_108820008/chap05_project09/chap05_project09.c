/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.28                                              */
/* Purpose: Compare two dates                                    */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int d1,m1,y1;
    int d2,m2,y2;
    int early = -1; 
    // use an int to save the result, and initialize it as -1

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d",&m1,&d1,&y1); // input the first date
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d",&m2,&d2,&y2); // input the second date

    if(y2<y1) early = 1; // change the result to 1 if y1 is earlier than y2
    else if(y2==y1) {
        if(m2<m1) early = 1; // change the result to 1 if m1 is earlier than m2
        else if(m2==m1) {
            if(d2<d1) early = 1; // change the result to 1 if d1 is earlier than d2
            else if(d2==d1) early = 0; // change the result to 0 if the two dates are same
        }
    }
    if(early==1) printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n",m2,d2,y2,m1,d1,y1);
    else if(early==-1) printf("%02d/%02d/%02d is eariler than %02d/%02d/%02d\n",m1,d1,y1,m2,d2,y2);
    else printf("%02d/%02d/%02d is same as %02d/%02d/%02d\n",m2,d2,y2,m1,d1,y1);

    system("PAUSE");
    return 0;
}