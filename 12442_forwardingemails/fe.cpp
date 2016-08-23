#include <stdio.h>

int* martians;
int* path_length;
int* visited;

int dfs(int root){		
	visited[root] = 1;	
	int path = 0;
	if(visited[martians[root]] == 0)
		path = dfs(martians[root]) + 1;		
	visited[root] = 0;
	path_length[root] = path;
	return path;
}

int main(){
	int i,j,ncases,nmartians,martian_u,martian_v,max,maxMartian;
	scanf("%d\n",&ncases);
	for(i = 1;i <= ncases; i++){
		scanf("%d\n",&nmartians);
		martians = new int[nmartians + 1];
		path_length = new int[nmartians + 1];
		visited = new int[nmartians + 1];
		for(j = 0; j < nmartians; j++){
			scanf("%d%d\n",&martian_u,&martian_v);
			martians[martian_u] = martian_v;
			path_length[martian_u] = -1;
			visited[martian_u] = 0;
		}
		max = 0;
		for(j = 1; j <= nmartians; j++){
			if(path_length[j] == -1)
				dfs(j);
			if(path_length[j] > max){
				max = path_length[j];
				maxMartian = j;
			}						
		}
		printf("Case %d: %d\n",i,maxMartian);
	}	
	return 0;
}
