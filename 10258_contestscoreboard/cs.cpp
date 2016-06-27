#include <limits.h>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#define MINDATAREAD 8
#define MAXCONTESTANTS 100
#define MAXPROBLEMS 9
#define PENALTY 20

using namespace std;

typedef struct Contestant{
	int id;
	int solved_problems;
	int total_penalty;
	map<int,int> correct_problems;
	map<int,int> incorrect_problems;	
}contestant_;

struct compare{
	bool operator()(const Contestant& l, const Contestant& r){
		if(l.solved_problems == r.solved_problems){
			if(l.total_penalty == r.total_penalty)
				return l.id > r.id;
			else
				return l.total_penalty > r.total_penalty;
		}else
			return l.solved_problems < r.solved_problems;
	}
};

int main(){
	int testcases,contestant,sproblem,stime,i,j;
	string buf;
	char scase;	
	contestant_ temp;
	map<int,Contestant> contestant_info;
	priority_queue<Contestant,vector<Contestant>,compare> ranks;
	scanf("%d\n\n",&testcases);

	while(testcases--){		
		while(getline(cin,buf)){
			sscanf(buf.c_str(),"%d %d %d %c\n",&contestant,&sproblem,&stime,&scase);			
			if(buf.length() < MINDATAREAD)
				break;
			contestant_info[contestant].id = contestant;			
			if(scase == 'I')
				contestant_info[contestant].incorrect_problems[sproblem] += PENALTY;
			else if(scase == 'C'){
				if(contestant_info[contestant].correct_problems[sproblem] == 0 || (contestant_info[contestant].correct_problems[sproblem] != 0 && stime < contestant_info[contestant].correct_problems[sproblem])){
					contestant_info[contestant].correct_problems[sproblem] = stime + contestant_info[contestant].incorrect_problems[sproblem];
					contestant_info[contestant].total_penalty += contestant_info[contestant].correct_problems[sproblem];				
				}				
			}
		}

		for(i=1;i<=MAXCONTESTANTS;i++)
			if(contestant_info[i].id != 0){
				for(j=1;j<=MAXPROBLEMS;j++)
					if(contestant_info[i].correct_problems[j] > 0)
						contestant_info[i].solved_problems++;
				ranks.push(contestant_info[i]);
			}
				
		while(!ranks.empty()){
			temp = ranks.top();
			ranks.pop();
			printf("%d %d %d\n",temp.id,temp.solved_problems,temp.total_penalty);
		}

		if(testcases)
			printf("\n");
		contestant_info.clear();
	}
	return 0;
}
