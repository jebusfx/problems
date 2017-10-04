#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define MAX	101
#define loop(counter, n) for(int counter = 0; counter < n; counter++)

using namespace std;

int main()
{
	int input[MAX];
	int a,b,i,j,k;
	int adj[MAX][MAX];
	int t = 0;
	while(scanf("%d%d", &a,&b))
	{
		if(a == 0 && b == 0)
			break;
		loop(i, MAX)
		{
			loop(j, MAX)
			{
				adj[i][j] = INT_MAX;
			}
		}
		memset(input, -1, sizeof(int)*MAX);
		int n = 0;
		input[a] = n++;
		input[b] = n++;
		adj[input[a]][input[b]] = 1;
		while(scanf("%d%d", &a, &b))
		{
			if(a == 0 && b == 0)
				break;
			if(input[a] == -1)
				input[a] = n++;
			if(input[b] == -1)
				input[b] = n++;
			adj[input[a]][input[b]] = 1;
		}
		loop(i, n)
		{
			adj[i][i] = 0;
		}
		loop(k, n)
		{
			loop(i, n)
			{
				loop(j, n)
				{
					int path = adj[i][k] == INT_MAX || adj[k][j] == INT_MAX ? INT_MAX : adj[i][k] + adj[k][j];
					adj[i][j] = min(adj[i][j], path);
				}
			}
		}
		double res = 0.0;
		loop(i, n)
		{
			loop(j, n)
			{
				if(adj[i][j] != INT_MAX)
					res += adj[i][j];
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n", ++t, res/((n*n) - n));
	}
	return 0;
}
