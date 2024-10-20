/*Si realizzi un programma in linguaggio C che, data una matrice NxM di interi, trovi l'elemento per cui la media degli elementi ad esso adiacenti sia massima.
Si stampino le coordinate di tale elemento ed il suo valore.
Si considerino come adiacenti a ciascun elemento i quattro elementi nelle quattro direzioni cardinali. 
Si tratti inoltre l'ultima colonna come adiacente alla prima, e l'ultima riga come adiacente alla prima. 
Si supponga che N ed M possano variare tra 1 e 100. I valori di N ed M, cosi come i valori degli elementi della matrice, 
vengono acquisiti da tastiera.
*/
#include<stdio.h>
int main (){
	int m[100][100], N, M;
	int sopra, sotto, dx, sx;
	int i, j, riga, colonna;
	float media=0, max=0;
	printf("Inserire le dimensioni della matrice:\n");
	do{
	printf("Righe: ");
	scanf("%d", &N);
	} while (N<1 || N>100);
	do{
		printf("Colonne: ");
		scanf("%d", &M);
	} while (M<1 || M>100);
	printf("Riempire la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			printf("%d, %d. ", i,j);
			scanf("%d", &m[i][j]);		
		}
	}
	printf("La matrice inserita e:\n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
	//Controllo media:
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			sopra=m[(i-1+N)%N][j];
			sotto=m[(i+1+N)%N][j];
			dx=m[i][(j+1+M)%M];
			sx=m[i][(j-1+M)%M];
			media=(float)(sopra+sotto+dx+sx)/4;
			if(media>max){
				max=media;
				riga=i;
				colonna=j;
			}
		}
	}
	printf("\nL'elemento ricercato e: m[%d][%d]=%d\n", riga, colonna, m[riga][colonna]);
return 0;
}
