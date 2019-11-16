/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.14                                              */
/* Purpose: Counting poker 									     */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* external variables */
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int hand[NUM_CARDS][2];
bool straight,flush,four,three;
int pairs;

/* duplicate_card: check if an input card exists */
bool duplicate_card(int rank,int suit,int hand[NUM_CARDS][2], int cards_read)
{
	int i;
	for(i=0;i<cards_read;i++)
		if(rank==hand[i][0] && suit==hand[i][1])
			return true;
	return false;
}

/* read cards: read cards into parameters        */
/*             num_in_rank and num_in_suit       */
/*			   check for bad and duplicate cards */
void read_cards()
{
	char c,rank_ch,suit_ch;
	int rank,suit;
	bool bad_card;
	int cards_read=0;

	// read 5 cards
	while(cards_read < NUM_CARDS)
	{
		bad_card=false;
		printf("Enter a card: ");

		// read rank and transfer to int value
		rank_ch=getchar();
		switch(rank_ch)
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': rank=0; break;
			case '3': rank=1; break;
			case '4': rank=2; break;
			case '5': rank=3; break;
			case '6': rank=4; break;
			case '7': rank=5; break;
			case '8': rank=6; break;
			case '9': rank=7; break;
			case 't': case 'T': rank=8; break;
			case 'j': case 'J': rank=9; break;
			case 'q': case 'Q': rank=10; break;
			case 'k': case 'K': rank=11; break;
			case 'a': case 'A': rank=12; break;
			default: bad_card=true; 
		}

		// read suit and transfer to int value
		suit_ch=getchar();
		switch(suit_ch)
		{
			case 'c': case 'C': suit=0; break;
			case 'd': case 'D': suit=1; break;
			case 'h': case 'H': suit=2; break;
			case 's': case 'S': suit=3; break;
			default: bad_card=true; 
		}

		// bad card if unnecessary characters are added
		while((c=getchar())!='\n')
			if(c!=' ')
				bad_card=true;

		// notify an error of unavailable cards or add available cards to the arrays
		if(bad_card)
			printf("Bad card; ignored.\n");
		else if(duplicate_card(rank,suit,hand,cards_read))
			printf("Duplicate card; ignored.\n");
		else {
			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			cards_read++;
		}
	}
}

/* analyze_hand: determines what the hand contains */
void analyze_hand()
{
	int num_consec=0;
	int card,rank,matches;
	int tmp;
	int i,j,smallest,temp_suit,temp_rank;

	straight=false;
	flush=false;
	four=false;
	three=false;
	pairs=0;

	// sort cards by rank
	for(i=0;i<NUM_CARDS;i++)
	{
		smallest=i;
		for(j=i+1;j<NUM_CARDS;j++)
			if(hand[j][0]<hand[smallest][0])
				smallest=j;

		temp_rank=hand[i][0];
		temp_suit=hand[i][1];
		hand[i][0]=hand[smallest][0];
		hand[i][1]=hand[smallest][1];
		hand[smallest][0]=temp_rank;
		hand[smallest][1]=temp_suit;
	}

	// check for flush
	for(card=1;card<NUM_CARDS;card++)
	{
		if(hand[card][1]!=hand[0][1])
			break;
		if(card==NUM_CARDS-1)
			flush=true;
	}

	// check for straight
	for(card=1;card<NUM_CARDS;card++)
	{
		if(hand[card][0]-hand[card-1][0] != 1)
			break;
		if(card==NUM_CARDS-1)
			straight=true;
	}

	// check four-of-a-kind, three-of-a-kind and pairs
	for(i=0;i<NUM_CARDS;i++)
	{
		matches=0;
		for(j=i+1;j<NUM_CARDS;j++)
			if(hand[j][0]==hand[i][0])
				matches++;

		if(matches==1) pairs++;
		if(matches==2) three=true;
		if(matches==3) four=true;
	}
}

/* print_result: prints the classification of the hand */
void print_result()
{
	if(straight && flush) 		printf("Straight flush");
	else if(four) 				printf("Four of a kind");
	else if(three && pairs==1) 	printf("Full House");
	else if(flush) 				printf("Flush");
	else if(straight) 			printf("Straight");
	else if(three) 				printf("Three of a kind");
	else if(pairs==2) 			printf("Two pairs");
	else if(pairs==1) 			printf("Pair");
	else 						printf("High card");
	
	puts("\n");
}

int main()
{
	for(;;)
	{
		read_cards();
		analyze_hand();
		print_result();
	}
}