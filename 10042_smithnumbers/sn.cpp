#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

unsigned long sum_digits(char* n_string){
	int i;
	unsigned long sum = 0;
	for(i=0;i<strlen(n_string);i++)
		sum += n_string[i] - '0';	
	return sum;
}

unsigned long sum_digits(string n_string){
	int i;
	unsigned long sum = 0;
	for(i=0;i<strlen(n_string.c_str());i++)
		sum += n_string[i] - '0';	
	return sum;
}

string sum_prime_factorization(unsigned long n){
	unsigned long i,c = n,root;
	bool isPrime = true;
	char number[11];
	string result = "";	
	
	while((c % 2) == 0){
		c = c / 2;
		result += "2";
		isPrime = false;
	}

	i = 3;
	root = sqrt(c);
	while(i <= (root + 1)){
		if((c % i) == 0){
			c = c / i;
			sprintf(number,"%lu",i);
			result += number;
			root = sqrt(c);
			isPrime = false;
		}else
			i += 2;
	}

	if(c > 1){
		sprintf(number,"%lu",c);
		result += number;
	}

	if(isPrime || n == 2)
		result = "0";

	return result;
}


int isSmith(char* n_string, unsigned long n){	
	if(sum_digits(n_string) == sum_digits(sum_prime_factorization(n)))
		return 1;
	return 0;
}

int main(){
	int ntestcases;
	unsigned long n;
	char n_string[11];

	scanf("%d\n",&ntestcases);
	while(ntestcases--){
		scanf("%lu\n",&n);	
		n++;	
		while(true){
			sprintf(n_string,"%lu",n);
			if(isSmith(n_string,n)){
				printf("%lu\n",n);
				break;
			}else
				n++;		
		}
	}
	return 0;
}
