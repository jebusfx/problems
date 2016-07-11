#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

#define MAX 2000000000

using namespace std;

map<unsigned long, unsigned long> numbers;
vector<unsigned long> intervals;
vector<unsigned long>::iterator low;

//search in the intervals O(log n)
unsigned long search(unsigned long n){	
	low = lower_bound(intervals.begin(),intervals.end(),n);
	return (low - intervals.begin());
}

unsigned long self_describing_sequence(){
	unsigned long n = 1, intervalEnd;	
	numbers[1] = 1;	
	intervals.push_back(1);

	//generate numbers of the sequence only when it changes values e.g numbers[12] = 6 and it changes till numbers[16] = 7 
	while(n < MAX){
		intervals.push_back(n + 1);
		numbers[n + 1] = 1 + numbers[n + 1 - numbers[numbers[n]]];
		if(numbers[numbers[n + 1]] == 0)
			numbers[numbers[n + 1]] = search(numbers[n + 1]);
		intervalEnd = n + numbers[numbers[n + 1]];		
		numbers[intervalEnd] = numbers[n + 1];		
		n += numbers[numbers[n + 1]];
	}
}

int main(){
	unsigned long n;	
	self_describing_sequence();
	while(1){
		scanf("%lu",&n);
		if(n == 0)
			break;		
		if(numbers[n] == 0)	
			numbers[n] = search(n);			
		printf("%lu\n", numbers[n]);
	}
	return 0;
}
