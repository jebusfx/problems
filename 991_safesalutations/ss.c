#include <stdio.h>

int main()
{
	int n;
	int t = 0;
	while(scanf("%d\n", &n) != EOF)
	{
		if(t)
			printf("\n");
		long int upper = 1;
		int i;
		for(i = 2*n; i > n;i--)
			upper *= i;
		long int lower = 1;
		for(i = 2; i <= n+1;i++)
			lower *= i;
		printf("%lu\n", upper/lower);
		t++;
	}
	return 0;
}
