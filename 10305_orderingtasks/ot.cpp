#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int> > tasks;
vector<bool> visited;
stack<int> ordered_tasks;

void dfs(int root){	
	visited[root] = true;	
	for(int k = 0; k < tasks[root].size(); k++){
		if(visited[tasks[root][k]] == false)
			dfs(tasks[root][k]);
	}
	ordered_tasks.push(root + 1);
}

int main(){
	int n,m,i,j;		
	while(scanf("%d%d\n",&n,&m)){
		if(n == 0 && m == 0)
			break;		
		tasks.resize(n);
		visited.resize(n);		
		while(m--){
			scanf("%d%d\n",&i,&j);
			tasks[i - 1].push_back(j - 1);			
		}		
		for(int counter = 0; counter<n ;counter++){
			if(visited[counter] == false)
				dfs(counter);
		}
		while(!ordered_tasks.empty()){
			printf("%d",ordered_tasks.top());
			if(ordered_tasks.size() > 1)
				printf(" ");
			ordered_tasks.pop();
		}
		printf("\n");
		tasks.clear();	
		visited.clear();
	}
	return 0;
}
