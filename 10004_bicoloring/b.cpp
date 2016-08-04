#include <limits.h>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct Graph_strct{	
	vector<int> nodes;
	int level;
	int color;
}graph_strct;

bool is_bipartite(graph_strct* graph, int nvertex){
	int i;
	bool bipartite = true;
	graph_strct current;
	queue<graph_strct> q;
	
	for(i = 0;i < nvertex;i++)		
		graph[i].level = INT_MAX;

	graph[0].level = 1;
	graph[0].color = 0;
	q.push(graph[0]);

	while(!q.empty() && bipartite){
		current = q.front();
		q.pop();
		for(i = 0;i < current.nodes.size();i++){
			if(graph[current.nodes[i]].level == INT_MAX){
				graph[current.nodes[i]].color = current.color ^ 1;
				graph[current.nodes[i]].level = current.level + 1;
				q.push(graph[current.nodes[i]]);
			}else if(current.color == graph[current.nodes[i]].color) // it was already visited, check colors
				bipartite = false;			
		}
	}
	return bipartite;
}

int main(){
	int nvertex,nedges,nvertex_copy;
	int no,node;	
	while(true){
		scanf("%d\n",&nvertex);
		if(nvertex == 0)
			break;
		scanf("%d\n",&nedges);
		nvertex_copy = nvertex;		
		graph_strct graph[nvertex];
		while(nedges--){
			scanf("%d%d\n",&no,&node);
			graph[no].nodes.push_back(node);
		}
		is_bipartite(graph,nvertex_copy) ? printf("BICOLORABLE.\n") : printf("NOT BICOLORABLE.\n");
	}	
	return 0;
}
