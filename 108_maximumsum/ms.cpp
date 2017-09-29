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
	int n;
	while(scanf("%d\n", &n) != EOF)
	{
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
		for(int k = 0; k < n - 1; k++)
		{
			memset(tmp, 0 , n*sizeof(int));
			for(int i = k; i < n; i++)
			{
				sum = 0;
				mymax = INT_MIN;
				for(int j = 0; j < n; j++)
				{
					tmp[j] += table[j][i];
					sum += tmp[j];
					if(sum < 0)
						sum = 0;
					mymax = max(sum, mymax);
				}
				globalmax = max(mymax, globalmax);
			}
		}
		printf("%d\n", globalmax);
	}
	return 0;
}