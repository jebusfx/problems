#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void initSet(int pset[], int n)
{
	for (int i = 0; i < n; i++)
	{
		pset[i] = i;
	}
}

int findRoot(int pset[], int i)
{
	if(pset[i] == i) // arrived to root
	{
		return i;
	}
	pset[i] = findRoot(pset, pset[i]); // path compression
	return pset[i];
}

void unionSet(int pset[], int x, int y)
{
	int rx = findRoot(pset, x);
	int ry = findRoot(pset, y);
	pset[rx] = ry;
}

bool isSameSet(int pset[], int x, int y)
{
	return findRoot(pset, x) == findRoot(pset, y);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int npcs;
		scanf("\n%d\n", &npcs);
		int pcs[npcs+1];
		initSet(pcs, npcs+1);
		int pc1,pc2;
		char c;
		// printf("%d\n",npcs + 1);
		int correct_queries = 0, incorrect_queries = 0;
		string line;
		while(true)
		{
			if(!getline(cin, line) || line.empty())
				break;
			sscanf(line.c_str(), "%c %d %d", &c, &pc1, &pc2);
			if(c == 'c')
			{
				unionSet(pcs, pc1, pc2);
			}
			else if(c == 'q')
			{
				if(isSameSet(pcs, pc1, pc2))
					correct_queries++;
				else
					incorrect_queries++;
			}
		}
		printf("%d,%d\n", correct_queries, incorrect_queries);
		if(t > 0)
			printf("\n");
	}
	return 0;
}
