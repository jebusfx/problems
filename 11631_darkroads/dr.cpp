#include <algorithm>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct Edge{	
	int v;
	unsigned int key;
}edge;

struct compare{
	bool operator()(const edge& l, const edge& r){
		return l.key > r.key;
	}
};

vector<vector<edge> > city;

int minimum_cost(int start,int m){
	int min_cost = 0;	
	bool mst[m];
	edge current;
	priority_queue<edge,vector<edge>,compare> pq;	
	vector<edge> current_adjList;

	memset(mst,false,sizeof(bool)*m);	
	current.v = 0, current.key = 0;	
	pq.push(current);
	
	while(!pq.empty()){
		//WITH PRIORITY QUEUE WE GET THE NEXT MINIMUM VERTEX
		current = pq.top(), pq.pop();
		//CONSIDER VERTICES THAT ARE NOT IN MST
		if(mst[current.v] == false){
			mst[current.v] = true;
			current_adjList = city[current.v];
			min_cost += current.key;	
			//EXPAND THE VERTEX
			for(int i = 0;i<current_adjList.size();i++)
				if(mst[current_adjList[i].v] == false)//ADD VERTICES NOT INT MST
					pq.push(current_adjList[i]);	
		}
	}
	return min_cost;
}

int main(){
	int m,n;
	int x,y;
	int total_cost;
	unsigned int z;

	while(true){
		scanf("%d%d\n",&m,&n);
		if(m == 0 && n == 0)
			break;
		edge temp;
		total_cost = 0;
		city.resize(m);
		while(n--){
			scanf("%d%d%d\n",&x,&y,&z);
			temp.v = y, temp.key = z;
			city[x].push_back(temp);
			temp.v = x, temp.key = z;
			city[y].push_back(temp);
			total_cost += z;
		}
		printf("%d\n",total_cost - minimum_cost(0,m));
		city.clear();
	}
	return 0;
}
