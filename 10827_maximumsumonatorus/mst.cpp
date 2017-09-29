#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		int n;
		scanf("%d\n", &n);
		int table[n][n];
		int globalmax = INT_MIN;
		bool hasPositive = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &table[i][j]);
				if(table[i][j] > 0)
					hasPositive = true;
				globalmax = max(globalmax, table[i][j]);
			}
		}
		if(!hasPositive)
		{
			printf("%d\n", globalmax);
			continue;
		}
		int tmp[n];
		int sum, mymax;
		globalmax = INT_MIN;
		for(int m = 0; m < n; m++)
		{
			for(int k = 0; k < n; k++)
			{
				memset(tmp, 0 , n*sizeof(int));
				for(int i = k; i < n + k; i++)
				{
					sum = 0;
					mymax = INT_MIN;
					int j, tmpCount = 0;
					for(j = m; j < n + m; j++, tmpCount++)
					{
						tmp[tmpCount] += table[j % n][i % n];
						sum += tmp[tmpCount];
						if(sum < 0)
							sum = 0;
						mymax = max(sum, mymax);
					}
					globalmax = max(mymax, globalmax);
				}
			}
		}
		printf("%d\n", globalmax);
	}
	return 0;
}