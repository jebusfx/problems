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
	int a,b,c;
	int i,j,k;
	int t = 0;
	while(scanf("%d%d%d\n", &a,&b,&c))
	{
		if(a == 0 && b == 0 && c == 0)
			break;
		if(t)
			printf("\n");
		int adj[a][a];
		loop(i, a)
		{
			loop(j, a)
			{
				adj[i][j] = INT_MAX;
			}
		}
		while(b--)
		{
			int x,y,z;
			scanf("%d%d%d\n", &x,&y,&z);
			adj[x - 1][y - 1] = z;
			adj[y - 1][x - 1] = z;
		}
		loop(i, a)
		{
			adj[i][i] = 0;
		}
		loop(k, a)
		{
			loop(i, a)
			{
				loop(j, a)
				{
					adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
				}
			}
		}
		printf("Case #%d\n", ++t);
		while(c--)
		{
			int qS,qE;
			scanf("%d%d\n", &qS, &qE);
			adj[qS - 1][qE - 1] == INT_MAX ? printf("no path\n") : printf("%d\n", adj[qS - 1][qE - 1]);
		}
	}
	return 0;
}
