#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define MAX 20

using namespace std;

char aux[10];
int res[MAX];
vector<string> results;
map<string, bool> duplicate;

void backTrack(int arr [], int i, int n, int m, int currSum, int resCount)
{
	currSum += arr[i];
	res[resCount++] = arr[i];
	for (int j = i + 1; j < m; ++j)
	{
		if(currSum + arr[j] == n)
		{
			string s = "";
			res[resCount++] = arr[j];
			for (int k = 0; k < resCount; ++k)
			{
				sprintf(aux, "%d", res[k]);
				s += aux;
				if(k != resCount - 1)
					s+='+';
			}
			// decrement to keep searching in children at same level
			resCount--;
			if(duplicate[s] == false)
			{
				duplicate[s] = true;
				results.push_back(s);
			}
		}
		else if(currSum + arr[j] < n)
			backTrack(arr, j, n, m, currSum, resCount);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n,m;
	while(true)
	{
		scanf("%d%d\n", &n,&m);
		if(!n && !m)
			break;
		int arr[m];
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &arr[i]);
		}
		printf("Sums of %d:\n", n);
		for (int i = 0; i < m; ++i)
		{
			if(arr[i] == n)
			{
				sprintf(aux, "%d", arr[i]);
				string s(aux);
				if(duplicate[s] == false)
				{
					duplicate[s] = true;
					results.push_back(s);
				}
			}
			else
			{
				backTrack(arr, i, n, m, 0, 0);
			}
		}
		if(results.size() == 0)
			printf("NONE\n");
		else
		{
			for(auto it = results.begin(); it != results.end(); it++)
				cout << *it << endl;
		}
		results.clear();
		duplicate.clear();
	}
	return 0;
}
