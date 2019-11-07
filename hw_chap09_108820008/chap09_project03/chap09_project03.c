/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.07                                              */
/* Purpose: Generate a random A-Z map with function              */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

void generate_random_walk(char walk[N][N])
{
	int x,y,new_x,new_y;
	int dir=rand()%4,try=0; // give dir a random direction, try records the numbers tried for four directions
	char letter='A'; // start the letter from A

	// initialize with '.'
	for(x=0;x<N;x++)
		for(y=0;y<N;y++)
			walk[x][y]='.';

	walk[x=0][y=0]=letter++;
	// start the location at (0,0) and add the letter to the location

	while(try<4 && letter<='Z') // 
	{
		// assign the moved location to new_x new_y
		switch((dir+try)%4)
		{
			case 0: new_x=x+1, new_y=y; break;
			case 1:	new_x=x, new_y=y+1; break;
			case 2: new_x=x-1, new_y=y; break;
			case 3: new_x=x, new_y=y-1; break;
		}

		// put a letter to the new location if (new_x,new_y) is in the map and if it is a '.'
		if(new_x>=0 && new_x<N && new_y>=0 && new_y<N && walk[new_x][new_y]=='.')
		{
			walk[x=new_x][y=new_y]=letter++;
			dir=rand()%4, try=0;
		}
		else try++;
		// add 1 to moves_tried if (new_x,new_y) is not in an appropriate location
	}
}

void print_array(char walk[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%c ",walk[i][j]);
		putchar('\n');
	}
}

int main()
{
	char walk[N][N];

	srand((unsigned) time(NULL));

	generate_random_walk(walk);
	print_array(walk);

	return 0;
}