#include <stdio.h>
#include <stdlib.h>

long int fibs[24];

int isfibo(int n){
	int i;					
	for(i = 0;i<sizeof(fibs)/sizeof(long int);i++){		
		if(n == fibs[i])
			return 1;
	}
	return 0;
}

long int fibonacci(long int n){		
	if(fibs[n] != 0){
		return fibs[n];
	}
	if(n == 1 || n == 2){
		fibs[n] = 1;		
		return 1;
	}else{		
		fibs[n] = fibonacci(n-1) + fibonacci(n-2);		
		return fibs[n];		
	}		
}

int main(){
	int i,input,limit;
	scanf("%d",&input);	
	limit = (input > 24 ? 24 : input);
	fibonacci(limit);
	//fibonacci(input);
	for(i=0;i<input;i++){				
		if(!isfibo(i)){
			printf("%d ",i);
		}
	}	
}