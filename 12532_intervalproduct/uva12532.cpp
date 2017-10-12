#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <iostream>

#define MAX	10000000
#define loop(counter, n) for(int counter = 0; counter < n; counter++)
using namespace std;

int st[MAX];

int multiply(int a, int b)
{
	if(a == 0 || b == 0)
		return 0;
	else if((a > 0 && b > 0) ||
			(a < 0 && b < 0))
		return 1;
	return -1;
}

int querySegmentTree(int l, int r, int ql, int qr, int counter)
{
	if(ql > r || qr < l)
		return INT_MIN;
	if(l >= ql && r <= qr)
		return st[counter];
	else
	{
		int mid = l + (r-l)/2;
		int resL = querySegmentTree(l, mid, ql, qr, 2*counter+1);
	    int resR = querySegmentTree(mid + 1, r, ql, qr, 2*counter+2);
	    if(resL == INT_MIN && resR == INT_MIN)
	    	return INT_MIN;
	    else if(resL == INT_MIN)
	    	return resR;
	    else if(resR == INT_MIN)
	    	return resL;
	    else
	    	return multiply(resL, resR);
	}
}

void updateSegmentTree(int x, int y, int l, int r, int counter)
{
	if(x < l || x > r)
		return;
	if(l != r)
	{
		int mid = l + (r-l)/2;
		updateSegmentTree(x,y,l,mid,2*counter + 1);
		updateSegmentTree(x,y,mid+1,r,2*counter + 2);
		st[counter] = multiply(st[2*counter + 1], st[2*counter + 2]);
	}
	else if(l == x)
	{
		st[counter] = multiply(y, 1);
	}
}

void buildSegmentTree(int seq[], int l, int r, int counter)
{
    if(l == r)
	{
		st[counter] = multiply(seq[l], 1);
	}
	else
	{
		int mid = l + (r-l)/2;		
		buildSegmentTree(seq, l, mid, 2*counter + 1);
		buildSegmentTree(seq, mid + 1, r, 2*counter + 2);
		st[counter] = multiply(st[2*counter+1], st[2*counter+2]);
	}
	return;
}

int main(int argc, char const *argv[])
{
	char op;
	int n,k;
	int x,y;
	while(scanf("%d%d\n", &n, &k) != EOF)
	{
		memset(st, INT_MIN, sizeof(int)*MAX);
		int seq[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d\n", &seq[i]);
		}
		buildSegmentTree(seq, 0, n - 1, 0);
		while(k--)
		{
			scanf("%c%d%d\n", &op,&x,&y);
			if(op == 'C')
			{
				updateSegmentTree(x - 1, y, 0, n - 1, 0);
				seq[x - 1] = y;
			}
			else if(op == 'P')
			{
				int query = querySegmentTree(0, n - 1, x - 1, y - 1, 0);
				query == 0 ? printf("%d", query) : printf("%c", query > 0 ? '+' : '-');
			}
		}
		printf("\n");
	}
	return 0;
}
