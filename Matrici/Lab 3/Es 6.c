/*Si scriva un programma che costruisce una matrice di caratteri generati casualmente e stampa il carattere presente piu volte nella matrice.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5  // Dimensione della matrice

int main() {
    char M[N][N], car='A', max_car;
    int i, j;
    int cont=0, max=0;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            M[i][j] = 'A' + (rand() % 26);
        }
    }
    printf("Stampo matrice\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    for(car='A'; car<='Z'; car++){
		cont=0;
    	for(i=0; i<N; i++){
    		for(j=0; j<N; j++){
    			if(M[i][j]==car){
    				cont++;
				}
			}	
		}
		if(cont>max){
		max_car=car;
		max=cont;
		}
	}
	printf("Il carattere con maggiore ricorrenza e %c con %d ricorrenze", max_car, max);
    return 0;
}
