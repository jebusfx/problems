#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef struct Point{
	double x;
	double y;
}point;

bool escape(point p1, point gopher, point dog){	
	return sqrt(pow((gopher.x - p1.x),2) + pow((gopher.y - p1.y),2)) <= sqrt(pow((dog.x - p1.x),2) + pow((dog.y - p1.y),2))/2;
}

int main(){
	string buf;
	int nholes;
	point dog, gopher, temp;
	bool escaped,process;
	while(getline(cin,buf)){		
		sscanf(buf.c_str(),"%d %lf %lf %lf %lf\n",&nholes, &gopher.x, &gopher.y, &dog.x, &dog.y);				
		if(buf.length() == 1)
			continue;		
		escaped = false;
		while(nholes--){
			scanf("%lf %lf\n",&temp.x,&temp.y);			
			if(escape(temp,gopher,dog) && !escaped){
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",temp.x,temp.y);
				escaped = true;						
			}
		}
		if(!escaped)
			printf("The gopher cannot escape.\n");		
	}
	return 0;
}
