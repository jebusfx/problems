#include <stdio.h>
/*
 * 	10196 - Check the Check
 * 	@author: Fernandez
 */
int i,j,k,n,count=1,process;
char table[12][12];
int Wcheck,Bcheck;

int main(){
  start:
  process=0,Bcheck=0,Wcheck=0;
  for(j=2;j<=9;j++){
    for(i=2;i<=9;i++){
      scanf(" %c",&table[i][j]);
    }
  }
  for(j=2;j<=9;j++){
    for(i=2;i<=9;i++){
      if(table[i][j]=='K'||table[i][j]=='k')
	process++;
      switch(table[i][j]){
	case 'P':
	  process++;
	  if(table[i+1][j-1]=='k' || table[i-1][j-1]=='k')
	    Bcheck=1;
	  break;
	case 'p':
	  process++;
	  if(table[i-1][j+1]=='K' || table[i+1][j+1]=='K')
	    Wcheck=1;
	  break;
	case 'N':
	  process++;
	  if(table[i+1][j+2]=='k'||table[i-1][j+2]=='k'||table[i+2][j+1]=='k'||table[i+2][j-1]=='k'||table[i-2][j-1]=='k'||table[i-2][j+1]=='k'||table[i-1][j-2]=='k'||table[i+1][j-2]=='k')
	    Bcheck=1;	  
	  break;
	case 'n':
	  process++;
	  if(table[i+1][j+2]=='K'||table[i-1][j+2]=='K'||table[i+2][j+1]=='K'||table[i+2][j-1]=='K'||table[i-2][j-1]=='K'||table[i-2][j+1]=='K'||table[i-1][j-2]=='K'||table[i+1][j-2]=='K')
	    Wcheck=1;	  
	  break;
	case 'B':
	  process++;
	  /*Abajo Derecha*/
	  for(k=i,n=j;k<12&&n<12;k++,n++){
	    if(table[k][n]!='B'&&table[k][n]!='.'&&table[k][n]!='k')
	      break;
	    else if(table[k][n]=='k')
	      Bcheck=1;
	   }
	   /*Abajo Izquierda*/
	   for(k=i,n=j;n<12&&k>=0;k--,n++){
	     if(table[k][n]!='B'&&table[k][n]!='.'&&table[k][n]!='k')
		break;
	     else if(table[k][n]=='k')
		Bcheck=1;
	   }
	   /*Arriba Derecha*/
	   for(k=i,n=j;k<12&&n>=0;k++,n--){
	      if(table[k][n]!='B'&&table[k][n]!='.'&&table[k][n]!='k')
		 break;
	      else if(table[k][n]=='k')
		 Bcheck=1;
	   }
	   /*Arriba Izquierda*/
	   for(k=i,n=j;k>=0&&n>=0;k--,n--){
	      if(table[k][n]!='B'&&table[k][n]!='.'&&table[k][n]!='k')
		  break;
	      else if(table[k][n]=='k')
		  Bcheck=1;
	   }	  
	  break;
	case 'b':
	  process++;
	  /*Abajo Derecha*/
	  for(k=i,n=j;k<12&&n<12;k++,n++){
	    if(table[k][n]!='b'&&table[k][n]!='.'&&table[k][n]!='K')
	      break;
	    else if(table[k][n]=='K')
	      Wcheck=1;
	   }
	   /*Abajo Izquierda*/
	   for(k=i,n=j;n<12&&k>=0;k--,n++){
	     if(table[k][n]!='b'&&table[k][n]!='.'&&table[k][n]!='K')
		break;
	     else if(table[k][n]=='K')
		Wcheck=1;
	   }
	   /*Arriba Derecha*/
	   for(k=i,n=j;k<12&&n>=0;k++,n--){
	      if(table[k][n]!='b'&&table[k][n]!='.'&&table[k][n]!='K')
		 break;
	      else if(table[k][n]=='K')
		 Wcheck=1;
	   }
	   /*Arriba Izquierda*/
	   for(k=i,n=j;k>=0&&n>=0;k--,n--){
	      if(table[k][n]!='b'&&table[k][n]!='.'&&table[k][n]!='K')
		  break;
	      else if(table[k][n]=='K')
		  Wcheck=1;
	      }	  	  
	  break;
	case 'R':
	  process++;
	  /*Izquierda*/
	  for(k=i;k>=0;k--){
	    if(table[k][j]!='R'&&table[k][j]!='.'&&table[k][j]!='k')
	      break;
	    else if(table[k][j]=='k')
	      Bcheck=1;
	  }
	  /*Derecha*/
	  for(k=i;k<12;k++){
	     if(table[k][j]!='R'&&table[k][j]!='.'&&table[k][j]!='k')
	      break;
	     else if(table[k][j]=='k')
	      Bcheck=1;
	  }		      
	  /*Abajo*/
	  for(k=j;k>=0;k--){
	     if(table[i][k]!='R'&&table[i][k]!='.'&&table[i][k]!='k')
	      break;
	     else if(table[i][k]=='k')
	      Bcheck=1;
	  }	 
	  /*Arriba*/
	  for(k=j;k<12;k++){
	     if(table[i][k]!='R'&&table[i][k]!='.'&&table[i][k]!='k')
	      break;
	     else if(table[i][k]=='k')
	      Bcheck=1;
	  }	  
	  break;
	case 'r':
	  process++;
	  /*Izquierda*/	  
	  for(k=i;k>=0;k--){
	    if(table[k][j]!='r'&&table[k][j]!='.'&&table[k][j]!='K')
	      break;
	    else if(table[k][j]=='K')
	      Wcheck=1;
	  }
	  /*Derecha*/ 
	  for(k=i;k<12;k++){
	     if(table[k][j]!='r'&&table[k][j]!='.'&&table[k][j]!='K')
	      break;
	     else if(table[k][j]=='K')
	      Wcheck=1;
	  }		      
	  /*Abajo*/
	  for(k=j;k>=0;k--){
	     if(table[i][k]!='r'&&table[i][k]!='.'&&table[i][k]!='K')
	      break;
	     else if(table[i][k]=='K')
	      Wcheck=1;
	  }	 
	  /*Arriba*/
	  for(k=j;k<12;k++){
	     if(table[i][k]!='r'&&table[i][k]!='.'&&table[i][k]!='K')
	      break;
	     else if(table[i][k]=='K')
	      Wcheck=1;
	  }	  
	  break;
	case 'Q':
	  process++;
	  /*Izquierda*/
	  for(k=i;k>=0;k--){
	    if(table[k][j]!='Q'&&table[k][j]!='.'&&table[k][j]!='k')
	      break;
	    else if(table[k][j]=='k')
	      Bcheck=1;
	  }
	  /*Derecha*/
	  for(k=i;k<12;k++){
	     if(table[k][j]!='Q'&&table[k][j]!='.'&&table[k][j]!='k')
	      break;
	     else if(table[k][j]=='k')
	      Bcheck=1;
	  }		      
	  /*Abajo*/
	  for(k=j;k>=0;k--){
	     if(table[i][k]!='Q'&&table[i][k]!='.'&&table[i][k]!='k')
	      break;
	     else if(table[i][k]=='k')
	      Bcheck=1;
	  }	 
	  /*Arriba*/
	  for(k=j;k<12;k++){
	     if(table[i][k]!='Q'&&table[i][k]!='.'&&table[i][k]!='k')
	      break;
	     else if(table[i][k]=='k')
	      Bcheck=1;
	  }
	  /*Abajo Derecha*/
	  for(k=i,n=j;k<12&&n<12;k++,n++){
	    if(table[k][n]!='Q'&&table[k][n]!='.'&&table[k][n]!='k')
	      break;
	    else if(table[k][n]=='k')
	      Bcheck=1;
	   }
	   /*Abajo Izquierda*/
	   for(k=i,n=j;n<12&&k>=0;k--,n++){
	     if(table[k][n]!='Q'&&table[k][n]!='.'&&table[k][n]!='k')
		break;
	     else if(table[k][n]=='k')
		Bcheck=1;
	   }
	   /*Arriba Derecha*/
	   for(k=i,n=j;k<12&&n>=0;k++,n--){
	      if(table[k][n]!='Q'&&table[k][n]!='.'&&table[k][n]!='k')
		 break;
	      else if(table[k][n]=='k')
		 Bcheck=1;
	   }
	   /*Arriba Izquierda*/
	   for(k=i,n=j;k>=0&&n>=0;k--,n--){
	      if(table[k][n]!='Q'&&table[k][n]!='.'&&table[k][n]!='k')
		  break;
	      else if(table[k][n]=='k')
		  Bcheck=1;
	   }		  
	  break;
	case 'q':
	  /*Izquierda*/	  
	  for(k=i;k>=0;k--){
	    if(table[k][j]!='q'&&table[k][j]!='.'&&table[k][j]!='K')
	      break;
	    else if(table[k][j]=='K')
	      Wcheck=1;
	  }
	  /*Derecha*/ 
	  for(k=i;k<12;k++){
	     if(table[k][j]!='q'&&table[k][j]!='.'&&table[k][j]!='K')
	      break;
	     else if(table[k][j]=='K')
	      Wcheck=1;
	  }		      
	  /*Abajo*/
	  for(k=j;k>=0;k--){
	     if(table[i][k]!='q'&&table[i][k]!='.'&&table[i][k]!='K')
	      break;
	     else if(table[i][k]=='K')
	      Wcheck=1;
	  }	 
	  /*Arriba*/
	  for(k=j;k<12;k++){
	     if(table[i][k]!='q'&&table[i][k]!='.'&&table[i][k]!='K')
	      break;
	     else if(table[i][k]=='K')
	      Wcheck=1;
	  }
	  /*Abajo Derecha*/
	  for(k=i,n=j;k<12&&n<12;k++,n++){
	    if(table[k][n]!='q'&&table[k][n]!='.'&&table[k][n]!='K')
	      break;
	    else if(table[k][n]=='K')
	      Wcheck=1;
	   }
	   /*Abajo Izquierda*/
	   for(k=i,n=j;n<12&&k>=0;k--,n++){
	     if(table[k][n]!='q'&&table[k][n]!='.'&&table[k][n]!='K')
		break;
	     else if(table[k][n]=='K')
		Wcheck=1;
	   }
	   /*Arriba Derecha*/
	   for(k=i,n=j;k<12&&n>=0;k++,n--){
	      if(table[k][n]!='q'&&table[k][n]!='.'&&table[k][n]!='K')
		 break;
	      else if(table[k][n]=='K')
		 Wcheck=1;
	   }
	   /*Arriba Izquierda*/
	   for(k=i,n=j;k>=0&&n>=0;k--,n--){
	      if(table[k][n]!='q'&&table[k][n]!='.'&&table[k][n]!='K')
		  break;
	      else if(table[k][n]=='K')
		  Wcheck=1;
	      }		  
	  break;
	default:
	  break;
      }
    }
  }
  if(!process)
    return 0;
  else{
    if(Wcheck)
      printf("Game #%d: white king is in check.\n",count);
    else if(Bcheck)
      printf("Game #%d: black king is in check.\n",count);
    else
      printf("Game #%d: no king is in check.\n",count);
    count++;
    goto start;
    } 
}