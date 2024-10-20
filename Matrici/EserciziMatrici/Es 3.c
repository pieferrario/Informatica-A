/*Scrivere un programma che chiede all'utente di inserire una matrice 20x30, poi (dopo aver terminato la fase di inserimento) copia gli elementi 
dispari in una seconda matrice 20x30 senza lasciare buchi, se non in fondo. 
Gli elementi in fondo (i "buchi") siano messi a zero.
*/
#include<stdio.h>
#define m 2
#define n 3
int main (){
	int mat[m][n], mat2[m][n];
	int i, j, k=0, r=0;
	printf("Inserire i valori nella matrice\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
			if(mat[i][j]%2==1){
				mat2[r][k]=mat[i][j];
				k++;
				if (k==n){
					k=0;
					r++;
				}
			}
		}
	}
	for(i=r; i<m; i++){
		for(j=k; j<n; j++){
			mat2[i][j]=0;
		}
	}
	printf("La prima matrice e:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\nLa seconda matrice e:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf(" %d ", mat2[i][j]);
		}
		printf("\n");
	}
return 0;
}
