#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <iostream>

#define LIMIT 1000010
#define ADJUST 100000
#define LIMIT2 200010

using namespace std;

int ocurrences[LIMIT2];  // used to build segment tree
int start[LIMIT2];
int st[LIMIT];
int orArr[LIMIT];

int RMQ(int l, int r, int i, int j, int counter)
{
	if(i > r || j < l)
		return -1;
	if(l >= i && r <= j)
		return st[counter];
	int mid = l + (r - l)/2;
    return max(RMQ(l, mid, i, j, counter*2 + 1),
    		   RMQ(mid + 1, r, i, j, counter*2 + 2));
}

int buildSegmentTree(int l, int r, int counter)
{
	// one element
	if(l == r)
	{
		st[counter] = ocurrences[orArr[l]];
		return st[counter];
	}

	int mid = l + (r - l)/2;
	st[counter] = max(buildSegmentTree(l, mid, counter*2 + 1),
		              buildSegmentTree(mid + 1, r, counter*2 + 2));
	return st[counter];
}

int main()
{
	int n,q;
	while(scanf("%d%d\n", &n, &q) == 2)
	{
		if(n == 0)
			break;
		int cnt, last =  INT_MIN;
		memset(ocurrences, 0, sizeof(ocurrences));
		memset(start, 0, sizeof(start));
		memset(st, 0, sizeof(st));
		memset(orArr, 0, sizeof(orArr));
		for(cnt = 0; cnt < n; cnt++)
		{
			scanf("%d", &orArr[cnt]);
			orArr[cnt] += ADJUST;
			if(orArr[cnt] != last)
			{
				last = orArr[cnt];
				start[orArr[cnt]] = cnt;
			}
			ocurrences[orArr[cnt]]++;
		}
		buildSegmentTree(0, n - 1, 0);
		int i, j;
		while(q--)
		{
			scanf("%d%d\n", &i, &j);
			i -= 1; j -= 1;
			if(orArr[i] == orArr[j])
				printf("%d\n", j - i + 1);
			else
			{
				int endL = start[orArr[i]] + ocurrences[orArr[i]];
				int countL = endL - i;
				int countR = j - start[orArr[j]] + 1;
				int rmq = -1;
				int qL = endL;
				int qR = start[orArr[j]] - 1;
				if(qL <= qR)
					rmq = RMQ(0, n - 1, qL, qR, 0);
				int countMax = max(countL, countR);
				printf("%d\n", max(countMax, rmq));
			}
		}
	}
	return 0;
}
