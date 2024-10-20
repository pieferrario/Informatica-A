/*Considerata una matrice A di N x M interi, definiamo claque una sottomatrice 2 x 2 in cui la somma algebrica dei valori di una diagonale 
sia pari a quella dell'altra diagonale. In figura sono evidenziate le claque. 
Si scriva un programma che acquisisce una matrice N x M stampa il numero di claque della matrice.
*/
#include<stdio.h>
#define M 4
#define N 5
int main (){
	int m[M][N], i, j, cont=0;
	printf("Inserire gli elementi della matrice\n");
	for(i=0; i<M;i++){
		for(j=0; j<N; j++){
			printf("(%d, %d) ", i+1, j+1);
			scanf("%d", &m[i][j]);
		}
	}
	printf("Stampo matrice\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(m[i][j]+m[i+1][j+1]==m[i][j+1]+m[i+1][j]){
				cont++;
			}
		}
	}
	printf("Sono state trovate %d claque", cont);
return 0;
}
