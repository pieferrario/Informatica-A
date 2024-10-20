/*Scrivere un programma che genera una matrice 3x3 inserendo dei numeri progressivi in ogni cella, la stampa e poi la trasforma in una matrice 
triangolare superiore avente come elementi le somme degli elementi simmetrici rispetto alla diagonale principale*/
#include<stdio.h>
#define N 3
int main (){
	int i, j, n=1, m[N][N];
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			m[i][j]=n;
			n++;
		}		
	}
	printf("Stampo matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i!=j && i<j){
				m[i][j]=m[i][j]+m[j][i];
				m[j][i]=0;				
			}	
		}
	}
	printf("Stampo matrice modificata:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
return 0;
}
