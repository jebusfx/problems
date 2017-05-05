#include <bitset>
#include <stdio.h>

#ifndef MAX
#define MAX 1000000
#endif

using namespace std;

bitset<MAX + 10> bs;

int testSet(int start, int end)
{
	for(int i = start; i < end && i < MAX; i++)
	{
		if(bs.test(i))
			return true;
		bs.set(i);
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n,m;
	while(1)
	{
		scanf("%d %d\n", &n, &m);
		if(!n && !m)
			break;
		int start, end, repeat, conflict = 0;
		while(n--)
		{
			scanf("%d %d\n", &start, &end);
			if(testSet(start, end))
			{
				conflict = 1;
			}
		}
		while(m--)
		{
			scanf("%d %d %d\n", &start, &end, &repeat);
			while(!conflict && start < MAX)
			{
				if(testSet(start, end))
				{
					conflict = 1;
				}
				start += repeat;
				end += repeat;
			}
		}
		conflict ? printf("CONFLICT\n") : printf("NO CONFLICT\n");
		bs.reset();
	}
	return 0;
}