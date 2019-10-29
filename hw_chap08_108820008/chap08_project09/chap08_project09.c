/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Generate a random A-Z map                            */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define FILLER '.'

int main()
{
	char a[N][N], letter='A'; // start the letter from 'A'
	int x,y,direction,moves_tried,new_x,new_y;

	// initialize the map as '.'
	for(x=0;x<N;x++)
		for(y=0;y<N;y++)
			a[x][y]=FILLER; 

	// initialize the seed of time for using rand()
	srand((unsigned) time(NULL));

	x=0,y=0; // start the location at (0,0)
	a[x][y]=letter; // add the letter to the location
	direction=rand()%4; // randomly select a number from 0-3
	moves_tried=0; // record the numbers tried for four directions

	while(moves_tried<4 && letter<'Z')
	{
		// assign the moved location to new_x new_y
		switch((direction+moves_tried)%4)
		{
			case 0: 
				new_x=x+1,new_y=y;
				break;
			case 1:
				new_x=x,new_y=y+1;
				break;
			case 2:
				new_x=x-1,new_y=y;
				break;
			case 3:
				new_x=x,new_y=y-1;
				break;
		}

		// put a letter to the new location if (new_x,new_y) is in the map and if it is a FILLER('.')
		if(new_x>=0 && new_x<N && new_y>=0 && new_y<N && a[new_x][new_y]==FILLER)
		{
			x=new_x,y=new_y;
			a[x][y]=++letter;
			direction=rand()%4;
			moves_tried=0;
		}
		else // add 1 to moves_tried if (new_x,new_y) is not in an appropriate location
			moves_tried++;
	}

	// print out the drawn map
	for(x=0;x<N;x++)
	{
		for(y=0;y<N;y++)
			printf("%c",a[x][y]);
		printf("\n");
	}
	return 0;
}