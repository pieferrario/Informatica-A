/*Scrivere un programma che richiede all'utente di riempire una matrice 3 x 3 di interi, la stampa, sostituisce nella matrice ogni numero pari con la sua meta e,
infine, stampa la matrice cosi modificata.*/
#include<stdio.h>
#define N 3
int main (){
	int m[N][N];
	int i, j;
	printf("Riempire la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("La matrice inserita e:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(m[i][j]%2==0){
				m[i][j]=m[i][j]/2;
			}
		}
	}
	printf("La matrice modificata e:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
return 0;
}
