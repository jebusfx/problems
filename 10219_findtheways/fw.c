#include <stdio.h>
#include <math.h>

int main(){
	double result;
	unsigned long long n,k,i,j;
	while(scanf("%llu%llu\n",&n,&k) != EOF){
		result = 0.0;
		i = ((k > n - k) ? k + 1 : n - k + 1);		
		for(;i<=n;i++)
			result += (log10(i) - log10(n - i + 1));
		printf("%.0lf\n",floor(result) + 1);		
	}
	return 0;	
}
