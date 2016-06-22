#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

int solution(int* items,int count,int c,int newitem){
	for(int i = 0; i<count;i++){		
		if((items[i] + newitem) == c)
			return i+1;
	}
	return -1;
}

int main(){
	int n,c,p,nitems,temp,count,maincount,resfirst,ressecond,candidate;	
	string junk;
	cin>>n;
	maincount = 1;
	while(maincount<=n){
		cin>>c;
		cin>>nitems;		
		int* items = (int*)calloc(nitems,sizeof(int)*nitems);		
		count = 0;
		while(count<nitems){
			cin>>temp;			
			candidate = solution(items,count,c,temp);			
			if(candidate != -1){				
				if((count+1)>candidate){
					resfirst = candidate;
					ressecond = count+1;
				}else if((count+1)<candidate){
					resfirst = count+1;
					ressecond = candidate;
				}
				printf("Case #%d: %d %d\n",maincount,resfirst,ressecond);
				getline(cin,junk);
				break;
			}
			items[count] = temp;
			count++;
		}
		maincount++;
		free(items);		
	}
	return 0;
}