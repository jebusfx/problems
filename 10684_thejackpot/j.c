#include <stdio.h>

int main(){
	int n,i,sum,max;	
	while(scanf("%d\n",&n)){
		if(n == 0)
			break;
		int bets[n];
		sum = 0;
		max = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&bets[i]);
			sum += bets[i];			
			if(sum > max)
				max = sum;
			else if(sum < 0)
				sum = 0;
		}
		(max <= 0) ? printf("Losing streak.\n") : printf("The maximum winning streak is %d.\n", max);
	}
	return 0;
}
