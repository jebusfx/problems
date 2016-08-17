#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <queue>

#define MAX_POSSIBLE_STATES 8

using namespace std;

int initial_conf[4];
int target_conf[4];
map <string,int> forbidden_confs;
map <string, int> distance_;

string intarr_to_string(int* config){
	char buffer[5];	
	sprintf(buffer,"%d%d%d%d",config[0],config[1],config[2],config[3]);		
	string aux_(buffer);
	return aux_;
}

bool target_reached(int* config){
	if(config[0] == target_conf[0]
		&& config[1] == target_conf[1]
		&& config[2] == target_conf[2]
		&& config[3] == target_conf[3])
		return true;
	return false;
}

bool is_forbidden_state(string config){	
	if(forbidden_confs[config] == 1)
		return true;	
	return false;
}

void bfs(){
	char buffer[5];
	int i;
	int* current;
	int* original = new int[4];
	int result = -1;
	bool found = false;
	queue<int*> q;
	q.push(initial_conf);	
	distance_[intarr_to_string(initial_conf)] = 1;

	while(!q.empty()){
		original = q.front();
		q.pop();
		for(i = 0;i < MAX_POSSIBLE_STATES; i++){			
			current = new int[4];
			copy(original,original + 4, current);
			if(i > 3){				
				if((current[i % 4] - 1) == -1)
					current[i % 4] = 9;	
				else			
					current[i % 4]--;
			}else
				current[i] = (current[i] + 1) % 10;

			string current_config = intarr_to_string(current);			
			if(distance_[current_config] == 0){ // not visited
				if(target_reached(current)){
					result =  distance_[intarr_to_string(original)] + 1;
					found = true;					
					break;
				}
				distance_[current_config] = distance_[intarr_to_string(original)] + 1;
				if(!is_forbidden_state(current_config))
					q.push(current);
			}
		}
		if(found)
			break;		
	}

	printf("%d\n", result < 0 ? -1 : --result);
	return;
}

int main(){
	int ntestcases,nforbiddenconfs;
	int temp[4];	
	scanf("%d\n\n",&ntestcases);
	while(ntestcases--){
		scanf("%d%d%d%d\n",&initial_conf[0],&initial_conf[1],&initial_conf[2],&initial_conf[3]);
		scanf("%d%d%d%d\n",&target_conf[0],&target_conf[1],&target_conf[2],&target_conf[3]);
		scanf("%d\n",&nforbiddenconfs);
		while(nforbiddenconfs--){
			scanf("%d%d%d%d\n",&temp[0],&temp[1],&temp[2],&temp[3]);			
			forbidden_confs[intarr_to_string(temp)] = 1;			
		}
		if(target_reached(initial_conf))
			printf("0\n");
		else
			bfs();
		forbidden_confs.clear();
		distance_.clear();		
	}
	return 0;
}
