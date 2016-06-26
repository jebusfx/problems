#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void * a, const void * b){
  if(*(int*)a > *(int*)b) return 1;
  if(*(int*)a < *(int*)b) return -1;
  return 0;
}

int calculateMinimalSum(int median, int size, int *streetNumbers){
    int i,sum=0;
    for(i=median;i>=0;i--)
	     sum += abs(streetNumbers[median]- streetNumbers[i]);
      for(i=median; i<size;i++)
	       sum+= abs(streetNumbers[median]- streetNumbers[i]);
    return sum;
}

int main(){
  int ncases,relatives,i,j,sum,median,medianEven;
  scanf("%d",&ncases);
  for(i=0;i<ncases;i++){
    
    sum = 0;
    scanf("%d",&relatives);
    int streetNumbers[relatives];
    
    for(j=0;j<relatives;j++)
      scanf("%d",&streetNumbers[j]);
    
    qsort(streetNumbers,relatives,sizeof(int),cmp);
    
    if(relatives%2==0){
      median = relatives/2;
      medianEven = (relatives/2) - 1;
      calculateMinimalSum(medianEven,relatives,streetNumbers) <= calculateMinimalSum(median,relatives,streetNumbers)?printf("%d\n",calculateMinimalSum(medianEven,relatives,streetNumbers)):printf("%d\n",calculateMinimalSum(median,relatives,streetNumbers));
    }else{
      median = relatives/2;
      printf("%d\n",calculateMinimalSum(median,relatives,streetNumbers));
    }
    
  }
  return 0;
}