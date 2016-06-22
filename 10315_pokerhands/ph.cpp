#include <stdio.h>
#include <iostream>
#include <map>

#define NCARDS 52
#define NSUITS 4
#define HANDCARDS 5
//ranks
#define HIGHCARD 1
#define PAIR 2
#define TWOPAIRS 3
#define THREES 4
#define STRAIGHT 5
#define FLUSH 6
#define FULLHOUSE 7
#define FOURS 8
#define STRAIGHTFLUSH 9

using namespace std;

char values[] = "23456789TJQKA";
char suits[] = "CDHS";

//-1 black wins, 1 white wins, 0 tie
int get_high_card(map<char, int> black_values, map<char, int> white_values, int no){
	int i;
	for(i=(NCARDS/NSUITS)-1;i>=0;i--){
		if(black_values[values[i]] == no && white_values[values[i]] != no)			
			return -1;		
		else if(black_values[values[i]] != no && white_values[values[i]] == no)			
			return 1;		
	}
	return 0;
}

int final_rank(map<char, int> black_values, map<char, int> white_values, int rank){
	int i;
	int highercard = 0;

	if(rank == PAIR || rank == TWOPAIRS)
		highercard = get_high_card(black_values,white_values,2);		
	else if(rank == THREES)
		highercard = get_high_card(black_values,white_values,3);				
	else if(rank == FOURS)
		highercard = get_high_card(black_values,white_values,4);			
	else if(rank == FULLHOUSE){		
		highercard = get_high_card(black_values,white_values,3);
		return (highercard == 0 ? get_high_card(black_values,white_values,2) : highercard);
	}		
	return ((highercard == 0) ? get_high_card(black_values,white_values,1) : highercard);	
}

int rank_hand(map<char,int> value_ocurrences, char** cards){	
	int i,j;
	int npairs = 0, nthrees = 0, nfours = 0, straight = 0, flush = 0;
	int rank = 0;
	for(i=0;i<(NCARDS/NSUITS) && !straight;i++){
		if(value_ocurrences[values[i]] == 1){
			for(j=i+1;j<(NCARDS/NSUITS) && value_ocurrences[values[j]] == 1;j++);						
			if(j-(i+1) == 4)
				straight = 1;					
		}
		else if(value_ocurrences[values[i]] == 2)
			npairs++;
		else if(value_ocurrences[values[i]] == 3)
			nthrees++;			
		else if(value_ocurrences[values[i]] == 4)
			nfours++;
	}
	
	for(i=1;i<5 && cards[i][1] == cards[0][1];i++);	
	if(i==5)
		flush = 1;
	
	if(npairs == 1 && nthrees == 0 && !flush)
		rank = PAIR;
	else if(npairs == 2 && !flush)
		rank = TWOPAIRS;
	else if(nthrees == 1 && npairs == 0 && !flush)
		rank = THREES;
	else if(straight && !flush)
		rank = STRAIGHT;
	else if(flush && !straight)
		rank = FLUSH;
	else if(npairs == 1 && nthrees == 1 && (flush || !flush))
		rank = FULLHOUSE;
	else if(nfours == 1 && (flush || !flush))
		rank = FOURS;
	else if(straight && flush)
		rank = STRAIGHTFLUSH;
	else
		rank = HIGHCARD;	
	return rank;
}

int main(){	
	int i = 0;	
	int black_rank, white_rank,highercard;
	char value,suit;	
	map<char,int> black_values;	
	map<char,int> white_values;	
	char** black_cards = new char*[HANDCARDS];
	char** white_cards = new char*[HANDCARDS];
	while (scanf("%c",&value) != EOF) {		
		if(value != ' ' && value != 13 && value != 10){
			scanf("%c",&suit);
			if(i >= 0 && i < HANDCARDS){
				black_values[value]++;									
				black_cards[i] = new char[3];
				black_cards[i][0] = value;
				black_cards[i][1] = suit;
				black_cards[i][2] = '\0';				
			}else if(i >= 5 && i < HANDCARDS*2){
				white_values[value]++;									
				white_cards[i%HANDCARDS] = new char[3];
				white_cards[i%HANDCARDS][0] = value;
				white_cards[i%HANDCARDS][1] = suit;
				white_cards[i%HANDCARDS][2] = '\0';				
			}
			i++;			
			if(i == HANDCARDS*2){
				black_rank = rank_hand(black_values,black_cards);
				white_rank = rank_hand(white_values,white_cards);		
				if(black_rank == white_rank ){					
					highercard = final_rank(black_values,white_values,black_rank);
					if(highercard == -1)
						printf("Black wins.\n");
					else if(highercard == 1)
						printf("White wins.\n");
					else
						printf("Tie.\n");
				}else if(black_rank > white_rank)
					printf("Black wins.\n");
				else if(black_rank < white_rank)
					printf("White wins.\n");				

				black_cards = new char*[HANDCARDS];
				white_cards = new char*[HANDCARDS];
				black_values.clear();
				white_values.clear();
			}
			i %= HANDCARDS*2;
		}
	}
	return 0;
}
