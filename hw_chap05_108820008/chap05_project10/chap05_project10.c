/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                 */
/* ID: 108820008                                                 */
/* Date: 2019.09.28                                              */
/* Purpose: Convert a score to a letter grade                    */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int score; 
    char grade; // use a char variable to represent the letter grade

    printf("Enter numerical grade: ");
    scanf("%d",&score); // input numerical score

	switch(score/10)
	{
		case 10:
		case 9:
			grade='A'; // change grade to 'A' if score is 90~100
			break;
		case 8:
			grade='B'; // change grade to 'B' if score is 80~89
			break;
		case 7:
			grade='C'; // change grade to 'C' if score is 70~79
			break;
		case 6:
			grade='D'; // change grade to 'D' if score is 60~69
			break;
		default:
			grade='F'; // the rest(0~59) are graded as 'F'
	}

    printf("Letter grade: %c\n",grade); // print letter grade 
    system("PAUSE");
    return 0;
}
