#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int simulate(vector<int> jumps, int greater_jump, int start){
	int temp = greater_jump;
	for(int i = start; i < jumps.size();i++){		
		if(jumps[i] == temp)
			temp--;
		else if(jumps[i] > temp)
			return simulate(jumps,++greater_jump,i);
	}
	return greater_jump;
}

int main(){
	int ntestcases,nrungs,caseno = 0,jump,greater_jump;	
	int* rungs;
	vector<int> jumps;
	scanf("%d\n",&ntestcases);
	while(ntestcases--){
		scanf("%d\n",&nrungs);
		rungs = new int[nrungs];
		scanf("%d ",&rungs[0]);
		greater_jump = rungs[0];	
		jumps.push_back(greater_jump);	
		for(int i = 1;i < nrungs; i++){
			if(i == nrungs - 1)
				scanf("%d\n",&rungs[i]);
			else
				scanf("%d ",&rungs[i]);
			jump = (rungs[i] - rungs[i-1]);			
			jumps.push_back(jump);
			if(jump > greater_jump)
				greater_jump = jump;			
		}
		printf("Case %d: %d\n",++caseno,simulate(jumps,greater_jump,0));		
		jumps.clear();		
	}
	return 0;
}
