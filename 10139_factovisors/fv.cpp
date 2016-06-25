#include <iostream>
#include <limits.h>
#include <math.h>
#include <map>
#include <stdio.h>

using namespace std;

unsigned long TWO = 2;

int is_prime(unsigned long x){
  int i;
  if(x%2 == 0 && x!= 2)
    return 0;
  for(i=3;i<=sqrt(x);i+=2)
    if(x%i == 0)
      return 0;
  return 1;	
}

int highest_power_in_factorial(unsigned long p, unsigned long a, unsigned long n){
	unsigned long i,result=0;
	for(i=1;i<=a;i++){
		result += n/pow(p,i);
	}	
	result /= a;
	return result;
}

void prime_factorization(map<unsigned long,unsigned long>* pf,unsigned long m){		
	unsigned long i,c,root;
	c = m;	
	while ((c % 2) == 0){
		c = c / 2;
		(*pf)[TWO]++;
	}	
	i = 3;
	root = sqrt(c);
	while (i <= (root+1)){
		if ((c % i) == 0){			
			c = c / i;			
			root = sqrt(c);
			(*pf)[i]++;
		}
		else
			i = i + 2;
	}
	if(c > 1){
		(*pf)[c]++;
	}		
	return;
}

int divides_(map<unsigned long,unsigned long> pf_m, unsigned long n){
	for(map<unsigned long, unsigned long>::iterator it = pf_m.begin(); it != pf_m.end(); ++it){				
		if(!highest_power_in_factorial(it->first,it->second,n))
			return 0;
	}
	return 1;
}

int main(){	
	map<unsigned long, unsigned long> pf_m;
	unsigned long n,m;
	while(scanf("%lu%lu\n",&n,&m) != EOF){
		if(m == 1 || m == 0){
			printf("%lu divides %lu!\n",m,n);
		}else{
			if(is_prime(m) && m > n/2 && m <= n)
				printf("%lu divides %lu!\n",m,n);
			else{
				prime_factorization(&pf_m,m);
				if(divides_(pf_m,n))
					printf("%lu divides %lu!\n",m,n);
				else
					printf("%lu does not divide %lu!\n",m,n);
			}
		}		
		pf_m.clear();
	}
	return 0;
}
