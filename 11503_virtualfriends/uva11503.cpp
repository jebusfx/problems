#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

#define MAX	100002

using namespace std;

int pset[MAX];
int set_size[MAX];

void initSet(int n)
{
	for (int i = 0; i < n; i++)
	{
		pset[i] = i;
		set_size[i] = 1;
	}
}

int findRoot(int i)
{
	if(pset[i] == i) // arrived to root
	{
		return i;
	}
	pset[i] = findRoot(pset[i]);
	return pset[i];
}

void unionSet(int ri, int rj)
{
	pset[ri] = rj;
	set_size[rj] += set_size[ri];
	set_size[ri] = set_size[rj];
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		int n;
		scanf("%d\n", &n);
		int count_names = 0;
		initSet(MAX);
		map<string,int> name_to_id;
		while(n--)
		{
			int ans;
			string n1, n2;
			cin >> n1 >> n2;
			if(name_to_id.find(n1) == name_to_id.end())
				name_to_id[n1] = count_names++;
			if(name_to_id.find(n2) == name_to_id.end())
				name_to_id[n2] = count_names++;
			int ri = findRoot(name_to_id[n1]);
			int rj = findRoot(name_to_id[n2]);
			if(!(ri == rj))
			{
				unionSet(ri, rj);
			}
			ans = set_size[findRoot(name_to_id[n1])];
			printf("%d\n", ans);
		}
	}
	return 0;
}
