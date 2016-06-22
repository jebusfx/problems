#include <stdio.h>
#include <math.h>
#include <string.h>
#include <map>
#define MAXNODOS	1000

using namespace std;

typedef struct arbol{
	int clave[MAXNODOS];
	int izq[MAXNODOS];
	int der[MAXNODOS];
	int nivel[MAXNODOS];	
	int nodos;
}Arbol;

map<int,int> hijopadre;
int arbolInOrden[MAXNODOS];
int elementosInOrden;
int NIVELMAX;

void calculaResultado(Arbol arb){
	int i,j,nivel,ancho,mayorAncho=1,menorNivel=1;
	int niveles[NIVELMAX+1];
	memset(niveles,0,sizeof(niveles));
	niveles[1] = 1;
	for(i = 0;arb.nivel[arbolInOrden[i]-1] != 1; i++){
		//printf("%d %d\n",arb.nivel[arbolInOrden[i]-1],arbolInOrden[i]);
		nivel = arb.nivel[arbolInOrden[i]-1];
		if(niveles[nivel] == 0){
			for(j = arb.nodos-1;j>=0;j--){
				if(arb.nivel[arbolInOrden[j]-1] == nivel){
					ancho = (j-i)+1;
					niveles[nivel] = ancho;
					break;
				}
			}	
		}		
	}
	for(i = 1;i<=NIVELMAX;i++){
		if(niveles[i] > mayorAncho){
			menorNivel = i;
			mayorAncho = niveles[i];
		}			
	}		
	printf("%d %d\n",menorNivel,mayorAncho);
}

void insertar_nodo(Arbol* arb, int nodo,int izq, int der){
	arb->clave[arb->nodos] = nodo;
	arb->izq[arb->nodos] = izq;
	arb->der[arb->nodos] = der;	
	arb->nivel[arb->nodos] = (hijopadre[nodo] == 0 ? 1: arb->nivel[hijopadre[nodo]-1] + 1);	
	if(arb->nivel[arb->nodos] >= NIVELMAX)
		NIVELMAX = arb->nivel[arb->nodos];
	//arb->nivel = (int)(floor(log(arb->nodos+1) / log(2)));
	arb->nodos++;
}

void orden(Arbol arb, int nodo){
	if(nodo < 0)
		return;
	orden(arb,arb.izq[nodo]-1);
	arbolInOrden[elementosInOrden] = arb.clave[nodo];
	elementosInOrden++;
	orden(arb,arb.der[nodo]-1);
}

int main(){
	Arbol arb;	
	int i,n,nodo,izq,der;
	scanf("%d",&n);	
	for(i = 0; i<n; i++){
		scanf("%d%d%d",&nodo,&izq,&der);
		hijopadre[izq] = nodo;
		hijopadre[der] = nodo;
		insertar_nodo(&arb,nodo,izq,der);
	}
	orden(arb,0);
	calculaResultado(arb);
	return 0;
}
