#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int dp_table(int tracks[],int n,int ntracks){
	int i,j;
	int dp_table[ntracks + 1][n + 1];
	bool taken[ntracks + 1][n + 1];
	memset(dp_table,0,sizeof(int)*(ntracks+1)*(n+1));
	memset(taken,0,sizeof(int)*(ntracks+1)*(n+1));
	for(i = 1;i<=ntracks;i++){
		for(j = 1;j<=n;j++){			
			if(tracks[i - 1] <= j){
				if(dp_table[i - 1][j - tracks[i - 1]] + tracks[i - 1] > dp_table[i - 1][j]){
					dp_table[i][j] = dp_table[i - 1][j - tracks[i - 1]] + tracks[i - 1];
					taken[i][j] = true;
				}else{
					dp_table[i][j] = dp_table[i - 1][j];
					taken[i][j] = false;
				}				
			}else{
				dp_table[i][j] = dp_table[i - 1][j];
				taken[i][j] = false;
			}
		}
	}
	
	vector<int> result;
	int temp = n;
	for(i = ntracks; i>=1; i--){
		if(taken[i][temp]){
			result.push_back(tracks[i - 1]);
			temp -= tracks[i - 1];
		}
	}
	for(i = result.size()-1; i>=0;i--)
		printf("%d ",result[i]);
	return dp_table[ntracks][n];
}

int main(){	
	int n,ntracks;
	while(scanf("%d %d ",&n,&ntracks) != EOF){
		int tracks[ntracks];
		int possible[ntracks];
		for(int i = 0;i < ntracks; i++){
			if(i == ntracks - 1)
				scanf("%d\n",&tracks[i]);
			else
				scanf("%d ",&tracks[i]);
		}		
		int max = dp_table(tracks,n,ntracks);		
		printf("sum:%d\n",max);
	}
	return 0;
}
