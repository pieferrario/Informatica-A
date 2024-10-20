/*Scrivere un programma C che legge una sequenza di numeri interi e li mette nella prima riga della matrice M. 
La lettura della sequenza termina quando alla prima riga della matrice M sono stati assegnati 
50 interi oppure quando viene letto il secondo numero intero negativo.*/
#include<stdio.h>
#define N 5
int main (){
	int i=0, m[N][N], flag=0;
	printf("Inserire i valori nella matrice:\n");
		do{
			scanf("%d", &m[0][i]);
			if(m[0][i]<0){
				flag++;
			}
			i++;
		} while (i<N && flag<2);
	for(i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf(" %d ", m[i][j]);
		}
		printf("\n");
	}
return 0;
}
