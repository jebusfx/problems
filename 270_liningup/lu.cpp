#include <float.h>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <vector>

#define MIN_DATAREAD 2
using namespace std;

typedef struct Coordinate{
	int x;
	int y;
}coordinate;

int max_slope;
int max_slope_global;
map<double,int> slope_count;
vector<Coordinate> coordinates;

double slope(int y2, int y1, int x2, int x1){
	if((x2 - x1) == 0) //same vertical line
		return DBL_MAX;

	return (y2 - y1)/(float)(x2-x1);
}

void calculate_slopes(){
	double _slope;
	max_slope_global = 0;
	for(int i = 0; i < coordinates.size(); i++){
		max_slope = 0;
		slope_count.clear();
		for(int j = 0; j < coordinates.size(); j++){
			if(i != j){				
				_slope = slope(coordinates[j].y,coordinates[i].y,coordinates[j].x,coordinates[i].x);				
				if(slope_count[_slope] == 0)
					slope_count[_slope] = 1; //count the point that we are proposing as starting point when a new slope is found
				if(max_slope < ++slope_count[_slope])
					max_slope = slope_count[_slope];
			}			
		}
		slope_count.clear();
		if(max_slope_global < max_slope)
			max_slope_global = max_slope;	
	}
}

int main(){
	int ntestcases;	
	string buf;	
	Coordinate temp;
	scanf("%d\n\n",&ntestcases);
	while(ntestcases--){		
		while(getline(cin,buf)){
			sscanf(buf.c_str(),"%d%d\n",&temp.x,&temp.y);		
			if(buf.length() < MIN_DATAREAD)
				break;
			coordinates.push_back(temp);
		}
		calculate_slopes();
		printf("%d\n",max_slope_global);
		if(ntestcases)
			printf("\n");
		slope_count.clear();
		coordinates.clear();
	}	
	return 0;
}
