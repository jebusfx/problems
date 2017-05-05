#include <math.h>
#include <stdio.h>

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	while(scanf("%lld", &n) != EOF){
		if(!n)
			break;
		int i, j=0, nbits = floor(log(n)/log(2)) + 1;
		ll one = 1LL, a = 0, b = 0;
		for (i = 0; i < nbits; ++i)
		{
			if(one & n)
			{
				if(j%2)
					b ^= one;
				else
					a ^= one;
				j++;
			}
			one <<= 1;		
		}
		printf("%lld %lld\n", a, b);
	}
	return 0;
}
