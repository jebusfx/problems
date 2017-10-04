#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

map<string, vector<string>> graph;

int bfs(string root, string end)
{
	if(root.compare(end) == 0)
		return 0;
	queue<string> q;
	map<string, int> heights;
	heights.insert(pair<string, int>(root, 0));
	q.push(root);
	while(!q.empty())
	{
		string curr = q.front(); q.pop();
		if(end.compare(curr) == 0)
			return heights[curr];
		for(auto it = graph[curr].begin(); it!= graph[curr].end(); it++)
		{
			if(heights.find(*it) == heights.end())
			{
				heights.insert(pair<string, int>(*it, heights[curr] + 1));
				q.push(*it);
			}
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	int t;
	scanf("%d\n\n", &t);
	while(t--)
	{
		vector<string> words;
		string line;
		while(getline(cin, line))
		{
			if(line[0] == '*')
				break;
			words.push_back(line);
		}

		for(int i = 0; i < words.size(); i++)
		{
			for(int j = 0; j < words.size(); j++)
			{
				if(i != j && words[i].length() == words[j].length())
				{
					int nchanges = 0;
					for(int k = 0; k < words[i].size() && k < words[j].size(); k++)
					{
						if(words[i][k] != words[j][k])
							nchanges++;
					}
					if(nchanges == 1)
						graph[words[i]].push_back(words[j]);
				}
			}
		}
		string root, end;
		while(getline(cin, line))
		{
			if(line.empty())
				break;
			int space = line.find(" ");
			root = line.substr(0, space);
			end = line.substr(space + 1, line.length());
			int nsteps = bfs(root, end);
			cout << root << " " << end << " " << nsteps << endl;
		}
		if(t != 0)
			cout << endl;
		graph.clear();
	}
	return 0;
}
