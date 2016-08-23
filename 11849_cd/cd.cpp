#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n,m,i;
	vector<unsigned long long>::iterator it;	
	while(scanf("%d%d\n",&n,&m)){
		if(n == 0 && m == 0)
			break;
		unsigned long long jack[n];
		unsigned long long jill[m];
		vector<unsigned long long> result(n + m);
		for(i = 0; i < n; i++)
			scanf("%llu\n",&jack[i]);
		for(i = 0; i < m; i++)
			scanf("%llu\n",&jill[i]);
		sort(jack, jack + n);
		sort(jill, jill + m);
		it = set_intersection(jack, jack + n, jill, jill + m, result.begin());
		result.resize(it - result.begin());
		printf("%d\n",result.size());
	}	
	return 0;
}
