/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Calculate the row and column totals                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>

int main()
{
	int i,j,input;
	int row[8]={0},column[8]={0};

	for(i=1;i<=5;i++)
	{
		// output the i-th row 
		printf("Enter row %d: ",i);
		for(j=1;j<=5;j++)
		{
			scanf("%d",&input);
			row[i]+=input; // sum up input to row i
			column[j]+=input; // sum up input to column j
		}
	}

	// output the row totals
	printf("\nRow totals:");
	for(i=1;i<=5;i++)
		printf(" %d",row[i]);
	
	// output the column totals
	printf("\nColumn totals:");
	for(i=1;i<=5;i++)
		printf(" %d",column[i]);

	return 0;
}