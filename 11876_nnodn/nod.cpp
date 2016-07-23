#include <algorithm>
#include <math.h>
#include <map>
#include <stdio.h>
#include <vector>

#define MAX 1000000

using namespace std;

vector<int> sequence_generated;
vector<int>::iterator low;
vector<int>::iterator up;

unsigned int count_map(map<unsigned long, unsigned int> nods){
	map<unsigned long, unsigned int>::iterator it;
	unsigned int total_nods = 1;
	for(it = nods.begin(); it != nods.end(); it++){
		total_nods *= ((it->second) + 1);
	}
	return total_nods;
}

unsigned int number_of_divisors(unsigned long n){
	unsigned long i,root,previous_divisor;
	bool is_prime = true;
	map<unsigned long, unsigned int> nods;

	if(n == 0 || n == 1)
		return 1;

	while((n  % 2) == 0){
		is_prime = false;
		n /= 2;
		nods[2]++;
	}
	
	i = 3;	
	root = sqrt(n);
	while(i <= (root + 1)){
		if((n % i) == 0){
			is_prime = false;
			n /= i;			
			root = sqrt(n);
			nods[i]++;
		}else
			i += 2;
	}

	if(n > 1)
		nods[n]++;
				
	if(is_prime)
		return 2;	

	return count_map(nods);
}

unsigned long search(unsigned long a, unsigned long b){
	low = lower_bound(sequence_generated.begin(),sequence_generated.end(),a);
	up = upper_bound(sequence_generated.begin(),sequence_generated.end(),b);	
	return (up - sequence_generated.begin()) - (low - sequence_generated.begin());
}

void sequence(){
	//sequence_generated.reserve(MAX);	lower and upper bound dont work with vector.reserve()
	//sequence_generated[0] = 1;
	sequence_generated.push_back(1);
	for(unsigned long i = 1;i < MAX; i++){
		//sequence_generated[i] = sequence_generated[i - 1] + number_of_divisors(sequence_generated[i - 1]);
		sequence_generated.push_back(sequence_generated[i - 1] + number_of_divisors(sequence_generated[i - 1]));		
		if(sequence_generated[i] > MAX)			
			break;
	}
}

int main(){	
	sequence();
	int ntestcases,count_testcases = 0;
	unsigned long int a,b;
	scanf("%d\n",&ntestcases);
	while(ntestcases--){
		scanf("%lu%lu\n",&a,&b);
		printf("Case %d: %d\n",++count_testcases,search(a,b));
	}
	return 0;
}
