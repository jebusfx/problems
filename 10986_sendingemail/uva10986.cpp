#include <algorithm>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>
#include <vector>

#define LIMIT 100001
using namespace std;

struct edge
{
	int v;
	unsigned int w;
};

struct compare
{
	bool operator()(const edge& l, const edge& r)
	{
		return l.w > r.w;
	}
};

map<int, vector<edge>> graph;

int search(int s, int t, int n)
{
	int dist[n];
	memset(dist, LIMIT, sizeof(int)*n);
	map<int, bool> visited;
	priority_queue<edge,vector<edge>,compare> pq;
	edge tmp;
	tmp.v = s; tmp.w = 0;
	pq.push(tmp);
	dist[s] = 0;
	while(!pq.empty())
	{
		edge curr = pq.top(); pq.pop();
		if(curr.v == t)
			return dist[curr.v];
		if(!visited[curr.v])
		{
			visited[curr.v] = true;
			for(auto it = graph[curr.v].begin(); it != graph[curr.v].end(); it++)
			{
				edge myEdge = (*it);
				if(dist[curr.v] + myEdge.w < dist[myEdge.v])
				{
					dist[myEdge.v] = dist[curr.v] + myEdge.w;
					myEdge.w = dist[myEdge.v];
					pq.push(myEdge);
				}
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int ncase;
	int j,k;
	edge tmp;
	scanf("%d\n", &ncase);
	for (int i = 1; i <= ncase; ++i)
	{
		int n,m,s,t;
		scanf("%d%d%d%d\n", &n,&m,&s,&t);
		while(m--)
		{
			int u,v,w;
			scanf("%d%d%d\n", &u,&v,&w);
			tmp.v = v; tmp.w = w;
			graph[u].push_back(tmp);
			tmp.v = u;
			graph[v].push_back(tmp);
		}
		int res = search(s, t, n);
		printf("Case #%d: ", i);
		res == -1 || res == LIMIT ? printf("unreachable\n") : printf("%d\n", res);
		graph.clear();
	}
	return 0;
}