#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct Job{
	int njob;
	int time;
	int fine;
}job;

struct compare{
  bool operator()(const job& l, const job& r){
		double fineL = l.fine, timeL = l.time, fineR =  r.fine, timeR = r.time;
		if(fineL/timeL == fineR/timeR)
			return l.njob > r.njob;							
		else
			return	fineL/timeL < fineR/timeR;			
	}
}; 

int main(){
	int testcases,njobs,time_,fine,count;
	job temp;
	scanf("%d\n\n",&testcases);
	while(testcases--){
		count = 1;
		priority_queue<Job,vector<Job>,compare> pq;
		scanf("%d\n",&njobs);
		while(njobs--){
			scanf("%d%d\n",&time_,&fine);
			temp.njob = count++;
			temp.time = time_;
			temp.fine = fine;
			pq.push(temp);
		}

		while(true){
			temp = pq.top();
			pq.pop();
			printf("%d",temp.njob);
			if(pq.empty()){
				printf("\n");
				break;
			}else
				printf(" ");
			
		}
		if(testcases)
			printf("\n");
	}	
	return 0;
}
