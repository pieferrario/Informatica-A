/*Si scriva un programma che costruisce una matrice di interi e stampa il massimo K 
per cui e vero che la matrice contiene almeno un quadrato KxK di caselle di valore identico.*/
#include <stdio.h>
#define N 6

int main(){
    int M[N][N]={1,12,0,7,8,8,
	             4,3,5,5,5,4,
				 3,8,5,5,5,4,
				 6,9,5,5,5,9,
				 0,1,2,3,4,4,
				 6,7,8,9,4,4};
	int k, cont=0, max=0;
	int i, j, h;
	printf("Stampo matrice\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%4d", M[i][j]);
		}
		printf("\n");
	}
	//Scorro le sottomatrici di lato k
	for(k=1; k<=N-k; k++){
				
	}
    return 0;
}