#include <stdio.h>

int main(){
  int numbers,i,jolly;
  while(scanf("%d",&numbers)!=EOF){
    jolly=0;
    int sequence[numbers];
    int table[numbers-1][1];
    for(i=0;i<numbers;i++)
      scanf(" %d",&sequence[i]);
    for(i=1;i<=numbers-1;i++)
      table[i][0]=0;
    
    for(i=0;i<numbers-1;i++)
      if(abs(sequence[i]-sequence[i+1])<=numbers-1)
	       table[abs(sequence[i]-sequence[i+1])][0]=1;
    for(i=1;i<=numbers-1;i++)
	     if(table[i][0]==1)
	       jolly=1;
	     else{
	       jolly=0;
	       break;
	     }
    if(numbers==1)
      jolly=1;
    jolly?printf("Jolly\n"):printf("Not jolly\n");
  }
  return 0;
}
