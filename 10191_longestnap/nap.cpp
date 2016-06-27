#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int qcmp(const void *a, const void *b){
  if(*(int*)a > *(int*)b) return 1;
  if(*(int*)a < *(int*)b) return -1;
  return 0;
}

int main(){
  int nlines,i,j,k,aux[1000],dif,hour,may,count=1,resulth,resultm,auxh,auxm,newlines;
  char app[1000][300];
  char haux[3];
  while(cin>>nlines){
    if(nlines!=0){
    /*Inicializo*/
      may = 0;
      cin.ignore(1);
      int ihours[nlines],iminutes[nlines],ohours[nlines],ominutes[nlines];
      memset(ihours,0,nlines);
      memset(aux,0,1000);
      aux[0] = 600;
      for(i=0,j=1;i<nlines;i++){
        cin.getline(app[i],300);
        memset(haux,0,3);
        /*Guardo la hora de entrada como tipo entero*/
        haux[0] = app[i][0];
        haux[1] = app[i][1];
        ihours[i] = atoi(haux);
        haux[0] = app[i][3];
        haux[1] = app[i][4];
        iminutes[i] = atoi(haux);
        /*Convierto a minutos las horas*/
        aux[j] = ihours[i]*60+iminutes[i];
        j++;
        /*Guardo la hora de salida como tipo entero*/
        haux[0] = app[i][6];
        haux[1] = app[i][7];
        ohours[i] = atoi(haux);
        haux[0] = app[i][9];
        haux[1] = app[i][10];
        ominutes[i] = atoi(haux);
        /*Convierto a minutos las horas*/
        aux[j] = ohours[i]*60+ominutes[i];
        j++;
      }
      newlines = nlines*2+2;
      aux[j] = 1080;
      qsort(aux,newlines,sizeof(int),qcmp);
      /*Calculo la siesta mas larga*/
      for(i=1;i<newlines;i++){
        if((i%2!=0)||i==1||i==newlines-1)
  	      dif = aux[i] - aux[i-1];
        if(dif > may){
        	may = dif;
        	hour = aux[i-1];
        }
      }
      resulth = hour/60;
      resultm = hour%60;
      auxh = may/60;
      auxm = may%60;
      if(resultm >=0 && resultm <= 9){
        if(auxh!=0)
  	       cout<<"Day #"<<count<<": the longest nap starts at "<<resulth<<":0"<<resultm<<" and will last for "<<auxh<<" hours "<<"and "<<auxm<<" minutes."<<endl;
        else
  	       cout<<"Day #"<<count<<": the longest nap starts at "<<resulth<<":0"<<resultm<<" and will last for "<<auxm<<" minutes."<<endl;      
      }else{
        if(auxh!=0)
  	       cout<<"Day #"<<count<<": the longest nap starts at "<<resulth<<":"<<resultm<<" and will last for "<<auxh<<" hours "<<"and "<<auxm<<" minutes."<<endl;
        else
  	       cout<<"Day #"<<count<<": the longest nap starts at "<<resulth<<":"<<resultm<<" and will last for "<<auxm<<" minutes."<<endl;         
      }
    }else
      cout<<"Day #"<<count<<": the longest nap starts at 10:00 and will last for 8 hours and 0 minutes."<<endl;
    count++;
  }
  return 0;
}
