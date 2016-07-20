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

double outercircle_radius(double a, double b, double c){
	return (a * b * c)/(4 * heron(a,b,c));	
}

int main(){
	double a,b,c,violets,sunflowers,roses;
	double PI = acos(-1);
	while(scanf("%lf%lf%lf\n",&a,&b,&c) != EOF){
		roses = PI * pow(incircle_radius(a,b,c),2);
		violets = heron(a,b,c);
		sunflowers = (PI * pow(outercircle_radius(a,b,c),2));
		printf("%.4lf %.4lf %.4lf\n",sunflowers - violets,violets - roses,roses);
	}
	return 0;
}
