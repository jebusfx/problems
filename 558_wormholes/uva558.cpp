#include <algorithm>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>
#include <vector>

#define LIMIT 1010
#define loop(counter, n) for(int counter = 0; counter < n; counter++)
using namespace std;

struct edge
{
	int v;
	int w;
};

vector<edge> adjList[LIMIT];

int main()
{
	int c;
	scanf("%d\n", &c);
	while(c--)
	{
		int n,m,i,j;
		int x,y,z;
		scanf("%d%d\n", &n,&m);
		while(m--)
		{
			scanf("%d%d%d\n", &x,&y,&z);
			edge tmp;
			tmp.v = y;
			tmp.w = z;
			adjList[x].push_back(tmp);
		}
		int dist[n];
		bool hasNegativeCycle = false;
		loop(i, n)
			dist[i] = INT_MAX/2; // avoid overflows
		dist[0] = 0;
		loop(j, n) // relax all edges n times, if n - 1 any edge is relaxed it contains negative cycle
		{
			loop(i, n)
			{
				for(auto it = adjList[i].begin(); it != adjList[i].end(); it++)
				{
					edge curr = *it;
					if(dist[curr.v] > dist[i] + curr.w)
					{
						dist[curr.v] = dist[i] + curr.w;
						hasNegativeCycle = j == n - 1;
					}
				}
			}
		}
		hasNegativeCycle ? printf("possible\n") : printf("not possible\n");
		loop(i, LIMIT)
			adjList[i].clear();
	}	
	return 0;	
}
