/*Si scriva un programma (senza funzioni oltre al main) che partendo da una matrice M di interi (di dimensione NxN) e un vettore v di interi di dimensione N 
stampa la somma degli elementi di M che appaiono in posizioni
- riga corrispondente ad una posizione all'interno di v
- colonna corrispondente al valore contenuto nella cella di v

Per esempio, se v vale [4 7 2 4 1 8 1 1] richiede di sommare il quarto elemento della prima riga, il settimo della seconda, il secondo della terza, il quarto della quarta,
il primo della quinta, l'ottavo delle sesta, il primo della settima e il primo dell'ottava.  

Quindi partendo da 
la matrice  M                  e il vettore v               stampera il seguente valore
1 4 6 8 9 3 2 6                 4 7 2 4 1 8 1 1             8+1+7+5+2+9+3+1=36
4 7 2 4 1 8 1 1
5 7 3 9 1 2 0 3
3 7 7 5 5 3 8 0
2 1 5 5 7 3 5 7
2 4 9 3 7 5 8 9
3 5 7 8 9 5 7 8
1 2 6 4 8 9 9 0 */
#include <stdio.h>
#define N 8

int main(){
	int i,j,k, somma=0;
	int M[N][N]={1,4,6,8,9,3,2,6,
	              4,7,2,4,1,8,1,1,
				  5,7,3,9,1,2,0,3,
				  3,7,7,5,5,3,8,0,
				  2,1,5,5,7,3,5,7,
				  2,4,9,3,7,5,8,9,
				  3,5,7,8,9,5,7,8,
				  1,2,6,4,8,9,9,0};
	int v[]={4,7,2,4,1,8,1,1};			  
	printf("Stampo matrice e array\n");
	printf("M\n");
	for(i=0;i<N;i++){
		for(k=0;k<N;k++){
		printf("%3d ",M[i][k]);
		}
		printf("\n");
	}
	printf("v\n");
	for(i=0;i<N;i++){
		printf("%d ",v[i]);
	}
	printf("\n");

	/*SCRIVERE QUI LE PARTI MANCANTI DEL MAIN*/
	for(i=0; i<N;i++){
			somma+=M[i][v[i]-1];
	}
	printf("La somma secondo i criteri richiesti vale: %d", somma);
	return 0;
}