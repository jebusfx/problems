#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;

int search(int books[], int lower, int upper, int i,int m){
	if(lower <= upper){
		int midpoint = (lower + upper)/2;
		int sum = books[i] + books[midpoint];
		if(sum == m && i != midpoint) // positions in the array have to be different
			return books[midpoint];
		else if(sum > m)
			return search(books,lower,midpoint - 1,i,m);
		else if(sum < m)
			return search(books,midpoint + 1,upper,i,m);
	}
	return INT_MIN;
}

int main(){
	int i,n,m,difference,possible;
	pair<int,int> best;
	while(scanf("%d\n",&n) != EOF){
		int books[n];
		difference = INT_MAX;
		for(i = 0; i < n; i++){
			if(i == n - 1)
				scanf("%d\n",&books[i]);
			else
				scanf("%d ",&books[i]);
		}
		scanf("%d\n\n",&m);
		sort(books, books + n);
		for(i = 0; i < n; i++){			
			possible = search(books,0,n,i,m);
			if(abs(books[i] - possible) < difference){
				difference = abs(books[i] - possible);
				best = make_pair(books[i],possible);
			}
		}
		if(best.first <= best.second)
			printf("Peter should buy books whose prices are %d and %d.\n\n", best.first,best.second);
		else
			printf("Peter should buy books whose prices are %d and %d.\n\n", best.second,best.first);
	}
	return 0;
}
