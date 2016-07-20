#include <math.h>
#include <stdio.h>

double semiperimeter(double a, double b, double c){
	return (a + b + c)/2;
}

double heron(double a, double b, double c){
	double s = semiperimeter(a,b,c);
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

double incircle_radius(double a, double b, double c){
	return heron(a,b,c) / semiperimeter(a,b,c);
}

int main(){
	double a,b,c,radius;
	while(scanf("%lf%lf%lf\n",&a,&b,&c) != EOF){
		radius = (a == 0.0 || b == 0.0 || c == 0.0) ? 0.0 : incircle_radius(a,b,c);			
		printf("The radius of the round table is: %.3lf\n",radius);	
	}	
	return 0;
}
