#include <stdio.h>

long int bezout(long int a, long int b){
  long int x=0,y=1;
  long int auxX=1,auxY=0;
  long int aux;
  long int q;
  long int auxA=a,auxB=b;
 
  while(b!=0){
    aux = b;
    q = a/b;
    b = a%b;
    a=aux;
    
    aux = x;
    x = auxX - q * x;
    auxX = aux;
    
    aux = y;
    y = auxY - q * y;
    auxY = aux;
  }
  
  printf("%ld %ld %ld\n",auxX,auxY,a);
}

int main(){
  long int a,b;
  while(scanf("%ld%ld",&a,&b)!=EOF){
    bezout(a,b);
  }
  return 0;
}
