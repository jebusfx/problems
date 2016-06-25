#include <stdio.h>
#include <math.h>

int isPerfect(long int n){
  float root = sqrt(n);
  if(((long int)root)*((long int)root) == n)
    return 1;
  else
    return 0;
}

int main(){
  unsigned long int number;
  int i;
  while(scanf("%ld",&number) && number){
    if(number==1)
      printf("yes\n");
    else if(number==2)
      printf("no\n");
    else{
      if(isPerfect(number))
	       printf("yes\n");
      else
	       printf("no\n");
    }
  }
  return 0;
}