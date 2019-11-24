/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.11.24                                              */
/* Purpose: fractions!!!!                                        */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* read cards: read cards into parameters        */
/*             num_in_rank and num_in_suit       */
/*			   check for bad and duplicate cards */
void read_cards(int num_in_rank[], int num_in_suit[])
{
	bool card_exist[NUM_RANKS][NUM_SUITS];
	char ch,rank_ch,suit_ch;
	int rank,suit;
	bool bad_card;
	int cards_read=0;

	// initialize card_exist, num_in_rank, and num_in_suit
	for(rank=0;rank<NUM_RANKS;rank++)
	{
		num_in_rank[rank]=0;
		for(suit=0;suit<NUM_SUITS;suit++)
			card_exist[rank][suit]=false;
	}
	for(suit=0;suit<NUM_SUITS;suit++)
		num_in_suit[suit]=0;

	// read 5 cards
	while(cards_read<NUM_CARDS)
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
			default: bad_card=true; // input is unavailable if it is not one of the above
		}

		// read suit and transfer to int value
		suit_ch=getchar();
		switch(suit_ch)
		{
			case 'c': case 'C': suit=0; break;
			case 'd': case 'D': suit=1; break;
			case 'h': case 'H': suit=2; break;
			case 's': case 'S': suit=3; break;
			default: bad_card=true; // input is unavailable if it is not one of the above
		}

		// bad card if unnecessary characters are added
		while((ch=getchar())!='\n')
			if(ch!=' ')
				bad_card=true;

		// notify an error of unavailable cards or add available cards to the arrays
		if(bad_card) 
			printf("Bad card; ignored.\n");
		else if(card_exist[rank][suit])
			printf("Duplicate card; ignored.\n");
		else {
			num_in_rank[rank]++;
			num_in_suit[suit]++;
			card_exist[rank][suit]=true;
			cards_read++;
		}
	}
}

/* analyze_hand: determines what the hand contains */
void analyze_hand(int num_in_rank[], int num_in_suit[], bool *straight, bool *flush, bool *four, bool *three, int *pairs)
{
	int num_consec=0; 
	int rank,suit;

	*straight=false;
	*flush=false;
	*four=false;
	*three=false;
	*pairs=0;

	// check for flush
	for(suit=0;suit<NUM_SUITS;suit++)
		if(num_in_suit[suit]==NUM_CARDS)
			*flush=true;

	// check for straight
	rank=0;
	while(!num_in_rank[rank]) rank++;
	for(;rank<NUM_RANKS && num_in_rank[rank]>0;rank++)
		num_consec++;

	if(num_consec==NUM_CARDS)
	{
		*straight=true;
		return;
	}

	// check four-of-a-kind, three-of-a-kind and pairs
	for(rank=0;rank<NUM_RANKS;rank++)
	{
		if(num_in_rank[rank]==4) *four=true;
		if(num_in_rank[rank]==3) *three=true;
		if(num_in_rank[rank]==2) (*pairs)++;
	}
}

/* print_result: prints the classification of the hand */
void print_result(const bool *straight, const bool *flush, const bool *four, const bool *three, const int *pairs)
{
	if(*straight && *flush) 		printf("Straight flush");
	else if(*four) 				    printf("Four of a kind");
	else if(*three && (*pairs)==1) 	printf("Full House");
	else if(*flush) 				printf("Flush");
	else if(*straight) 			printf("Straight");
	else if(*three) 				printf("Three of a kind");
	else if((*pairs)==2) 			printf("Two pairs");
	else if((*pairs)==1) 			printf("Pair");
	else 						printf("High card");

	puts("\n");
}

int main()
{
    bool straight, flush, four, three;
    int pairs;
	int num_in_rank[NUM_RANKS];
	int num_in_suit[NUM_SUITS];
	for(;;)
	{
		read_cards(num_in_rank,num_in_suit);
		analyze_hand(num_in_rank,num_in_suit,&straight,&flush,&four,&three,&pairs);
		print_result(&straight,&flush,&four,&three,&pairs);
	}
}