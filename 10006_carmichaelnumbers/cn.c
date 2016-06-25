#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long int calcC(int a,int n, int exp){
  int two = 1;
  unsigned long long int modulo;
  unsigned long long int q;
  modulo = a%n;
  while(two<exp){
    two *= 2;	
    modulo = pow(modulo,2);
    if(modulo >= n){
      q = modulo / n;
      modulo = modulo - (q*n);
    }
  }
  return modulo;
}

int Congruence(int a,int n,char *binary){
  int i,exp;
  unsigned long long int mod = 1;
  int length = strlen(binary);
  for(i=0;i<length;i++){
    if((binary[i]-'0')!=0){
      exp = pow(2,i);
      mod *= calcC(a,n,exp);
      mod %= n;
    }
  }
  return mod;
}

int isPrime(int n){
  int i;
  if(n%2==0&&n!=2)
    return 0;
  for(i=3;i<=sqrt(n);i+=2)
    if(n%i==0)
      return 0;
  return 1;
}

int isCarmichael(int n){
  int i,temp = n;
  char binary[20];
  for(i=0;i<20;i++)
    binary[i]=0;
  i=0;
  while(n>0){
    binary[i] = !(n%2)?'0':'1';
    n /=2;
    i++;
  }
  for(i=2;i<temp;i++){
    if(i!=Congruence(i,temp,binary))
      return 0;
  }
  return 1;
}

int main(){
  int n;
  while(scanf("%d",&n) && n){
    !isPrime(n)&&isCarmichael(n)?printf("The number %d is a Carmichael number.\n",n):printf("%d is normal.\n",n);
  }
  return 0;
}