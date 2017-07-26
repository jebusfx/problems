#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d\n", &n) != EOF)
	{
		int m, count;
		map<char, bool> awakenAreas;
		map<char, set<char> > graph;
		scanf("%d\n", &m);
		string areas;
		cin >> areas;
		for(int i = 0; i < areas.length(); i++)
			awakenAreas[areas[i]] = true;
		while(m--)
		{
			cin >> areas;
			graph[areas[0]].insert(areas[1]);
			graph[areas[1]].insert(areas[0]);
		}
		int res = 0;
		vector<char> awakenFirst;
		while(true)
		{
			bool awaken = false;
			for(auto it = graph.begin(); it != graph.end(); it++)
			{
				if(awakenAreas.find(it->first)->second == false)
				{
					count = 0;
					for(auto it2 = graph[it->first].begin(); it2 != graph[it->first].end(); it2++)
					{
						if(awakenAreas.find(*it2)->second == true)
							count++;
						if(count == 3)
						{
							awakenFirst.push_back(it->first);
							awaken = true;
						}
					}
				}
			}
			if(awaken)
			{
				res++;
				for(int i = 0; i < awakenFirst.size(); i++)
				{
					awakenAreas[awakenFirst[i]] = true;
				}
				awakenFirst.clear();
			}
			else
				break;
		}
		awakenAreas.size() == n ? printf("WAKE UP IN, %d, YEARS\n", res) : printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}
