#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
	int f,r,i,j;
	int* front;	
	int* rear;
	double maximum_spread;
	vector<double> drive_ratio;	

	while(scanf("%d%d\n",&f,&r) == 2){		
		front = (int*)malloc(sizeof(int) * f);
		rear = (int*)malloc(sizeof(int) * r);		
		maximum_spread = 0.0;		

		for(i = 0; i < f - 1; i++)
			scanf("%d ",&front[i]);
		scanf("%d\n",&front[i]);

		for(i = 0; i < r - 1; i++)
			scanf("%d ",&rear[i]);
		scanf("%d\n",&rear[i]);

		for(i = 0; i < f; i++){
			for(j = 0; j < r; j++){			
				drive_ratio.push_back(rear[j]/(double)front[i]);
			}
		}		
		sort(drive_ratio.begin(),drive_ratio.end());
				
		for(i = 0;i < drive_ratio.size() - 1; i++){			
			if((drive_ratio[i + 1] / drive_ratio[i]) > maximum_spread)
				maximum_spread = (drive_ratio[i + 1] / drive_ratio[i]);			
		}
		printf("%.2lf\n",maximum_spread);
		drive_ratio.clear();
		free(front);
		free(rear);
	}
	return 0;
}
