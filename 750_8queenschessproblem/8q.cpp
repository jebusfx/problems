#include <stdlib.h>
#include <stdio.h>

#define N 8
#define MAXSOLUTIONS 92

using namespace std;

int solution_count;
int results[MAXSOLUTIONS + 1][N + 1];

void print_solutions(int row, int column){
	if(row >= 1 && row <= 8 && column >= 1 && column <= 8){
		int sol = 1;
		for (int i = 0; i < solution_count; i++){
			if(results[i][column] == row){
				if(sol < 10)
					printf(" ");
				printf("%d      ",sol++);
				for(int j = 1; j <= N; j++){
					printf("%d",results[i][j]);
					if(j != N)
						printf(" ");
				}
				printf("\n");			
			}
		}
	}
	return;
}

void process_solution(int queen_positions[],int k){	
	for(int i = 1; i <= k; i++)
		results[solution_count][i] = queen_positions[i];	
	solution_count++;
	return;
}

bool is_a_solution(int k){
	return (k == N);
}

void construct_candidates(int queen_positions[], int k, int c[], int *ncandidates){
	int i,j;
	bool legal_move;
	*ncandidates = 0;
	for (i=1; i<=N; i++) {
		legal_move = true;
		for (j=1; j<k; j++) { // check if a new queen can be placed with the queens we already have
			if (abs(k-j) == abs(i-queen_positions[j])){
				legal_move = false;
				break;
			}
			if(i == queen_positions[j]){
				legal_move = false;
				break;
			}
		}
		if (legal_move == true) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
	return;
}

void backtrack(int queen_positions[], int k){
	int c[N];
	int ncandidates;
	int i;
	if (is_a_solution(k))
		process_solution(queen_positions,k);
	else {
		k = k + 1;
		construct_candidates(queen_positions,k,c,&ncandidates);		
		for (i = 0; i<ncandidates; i++) {
			queen_positions[k] = c[i];
			backtrack(queen_positions,k);			
		}
	}
	return;
}

void nqueens(){
	int queen_positions[N];
	solution_count = 0;
	backtrack(queen_positions,0);
	return;
}

int main(){
	nqueens();
	int ntestcases,row,column;
	scanf("%d\n\n",&ntestcases);
	while(ntestcases--){
		scanf("%d %d\n\n",&row,&column);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		print_solutions(row,column);
		if(ntestcases)
			printf("\n");
	}
	return 0;
}
