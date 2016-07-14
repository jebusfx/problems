#include <float.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct Line{
	int x1;
	int y1;
	int x2;	
	int y2;
	double slope;	
}line;

typedef struct Point{
	int x;
	int y;
}point;

vector<Line> lines;

void slope(Line* temp_line){
	if((temp_line->x2 - temp_line->x1) == 0) //vertical line
		temp_line->slope = DBL_MAX;

	temp_line->slope = (temp_line->y2 - temp_line->y1)/(float)(temp_line->x2 - temp_line->x1);
}

void swap(int* x, int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap_if_minor(Line* temp_line){	
	if(temp_line->x1 > temp_line->x2){	
		swap(&temp_line->x1,&temp_line->x2);
		swap(&temp_line->y1,&temp_line->y2);
	}
}

int line_underneath(Point temp_point){
	//line equation: y - y1 = slope(x - x1)
	//from this eq we get: y = slope(x - x1) + y1 and test with a point x,y	
	double separation = DBL_MAX;
	double line_eq;
	int line_result = -1;
	for(int i = 0;i < lines.size();i++){
		line_eq = lines[i].slope * (temp_point.x - lines[i].x1) +  lines[i].y1;	
		//x,y is above y if y > slope(x - x1) + y1 and is in range of x1 and x2
		if(temp_point.x >= lines[i].x1 && temp_point.x <= lines[i].x2 && temp_point.y > line_eq)
			if(temp_point.y - line_eq < separation){//pick the line closest to the point
				line_result = i;
				separation = temp_point.y - line_eq;
			}
	}
	return line_result;
}

void new_point_fall(Point* temp_point, int nline_underneath){	
	if(lines[nline_underneath].slope > 0){
		temp_point->x = lines[nline_underneath].x1;
		temp_point->y = lines[nline_underneath].y1 - 1;		
	}else{		
		temp_point->x = lines[nline_underneath].x2;
		temp_point->y = lines[nline_underneath].y2 - 1;
	}
	if(temp_point->y < 0)
		temp_point->y = 0;
}

void water_fall(Point* temp_point){	
	int nline_underneath = line_underneath(*temp_point);
	if(nline_underneath == -1)
		return;
	new_point_fall(temp_point,nline_underneath);
	water_fall(temp_point);
}

int main(){
	int ntestcases,nlines,npoints;	
	Line temp_line;
	Point temp_point;
	scanf("%d\n\n",&ntestcases);
	while(ntestcases--){
		scanf("%d\n",&nlines);
		while(nlines--){
			scanf("%d%d%d%d\n",&temp_line.x1,&temp_line.y1,&temp_line.x2,&temp_line.y2);
			swap_if_minor(&temp_line);
			slope(&temp_line);
			lines.push_back(temp_line);
		}
		scanf("%d\n",&npoints);
		while(npoints--){
			scanf("%d%d\n",&temp_point.x,&temp_point.y);
			water_fall(&temp_point);
			printf("%d\n",temp_point.x);
		}
		lines.clear();
		if(ntestcases)
			printf("\n");
	}
	return 0;
}
