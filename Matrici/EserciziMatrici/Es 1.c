/*Scrivere un programma che chiede all'utente di riempire una matrice, la stampa, cerca, se esiste, la prima posizione in cui appare lo 0,
l'ultima posizione in cui appare lo 0 e la posizione mediana in cui appare lo 0 e dice in che posizione sono state trovate. 
*/
#include<stdio.h>
#define n 3
int main (){
	int i, j, mat[n][n];
	int trov=0, cont=0, cont2=0;
	printf("Riempire la matrice:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\nLa matrice inserita e:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(trov==0 && mat[i][j]==0){
				trov=1;
				printf("Il primo 0 e in posizione: (%d; %d)\n", i+1, j+1);
			}
		}
	}
	trov=0;
	for(i=n-1; i>=0; i--){
		for(j=n-1; j>=0; j--){
			if(trov==0 && mat[i][j]==0){
				trov=1;
				printf("L'ultimo 0 e in posizione (%d, %d)\n", i+1, j+1);
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(mat[i][j]==0){
				cont++;
			}
		}
	}
	if(cont%2==0){
		cont=cont/2;
	}
	else cont=cont/2+1;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(mat[i][j]==0){
				cont2++;
				if(cont2==cont){
					printf("Lo 0 in posizione mediana e in posizione (%d, %d)\n", i+1, j+1);
				}
			}
		}
	}
return 0;
}
