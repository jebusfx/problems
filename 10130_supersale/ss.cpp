#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct object
{
	int weight;
	int prize;	
};

int main()
{
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		int n, g;
		scanf("%d\n", &n);
		struct object* myobjs = (struct object*)malloc(sizeof(struct object)*n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d\n", &myobjs[i].prize, &myobjs[i].weight);
		}
		scanf("%d\n", &g);
		int family[g];
		for(int i = 0; i < g; i++)
		{
			scanf("%d\n", &family[i]);
		}
		int res = 0;
		for(int k = 0; k < g; k++)
		{
			int i,j;
			int canCarry = family[k] + 1;
			int dp[n][canCarry];
			for(i = 0; i < n; i++)
			{
				dp[i][0] = 0;
				if(i == 0)
				{
					for(j = 1; j < canCarry; j++)
					{
						dp[i][j] = myobjs[i].weight <= j ? myobjs[i].prize : 0;
					}
				}
			}
			for(i = 1; i < n; i++)
			{
				for(j = 1; j < canCarry; j++)
				{
					if(myobjs[i].weight <= j)
					{
						// first term is the cost if we take the object, second term if we do not
						dp[i][j] = max(myobjs[i].prize + dp[i - 1][j - myobjs[i].weight], dp[i - 1][j]);
					}
					else
					{
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
			res += dp[i - 1][j - 1];
		}
		printf("%d\n", res);
	}
	return 0;
}
