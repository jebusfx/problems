#include <stdio.h>
#include <string.h>
#include <map>

#ifndef MAX
#define MAX 1000000
#endif

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,aux,tmp;
	while(scanf("%d%d\n", &n, &m) != EOF)
	{
		map<int, map<int,int> > mymap;
		int counters[MAX];
		memset(counters, 0, MAX);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &aux);
			mymap[aux][++counters[aux]] = i + 1;
		}
		while(m--)
		{
			scanf("%d%d\n", &aux, &tmp);
			printf("%d\n", mymap[tmp][aux]);
		}
	}
	return 0;
}
