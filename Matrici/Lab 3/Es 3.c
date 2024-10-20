/*Scrivere un programma che, partendo da una matrice di interi M, un intero h ed un intero k, restituisce il numero di 
sottomatrici di M di dimensione h x h contenenti esattamente k valori uguali ad 1.*/
#include <stdio.h>
#define N 4
int main(){
	int M[N][N]={1,2,0,1,0,3,0,2,0,3,1,2,1,1,2,4};
	int h, k, cont1=0, contsott=0;
	int i, j, x, y;
	printf("Stampo matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", M[i][j]);
		}
		printf("\n");
	}
	printf("Inserire dimensione delle sottomatrici: ");
	do{
		scanf("%d", &h);
	} while (h<1 || h>N);
	printf("Inserire quantita k: ");
	do{
		scanf("%d", &k);
	} while (k<0 || k>N*N);
	//Scorro la matrice M
	for(i=0; i<N-h+1; i++){
		for(j=0; j<N-h+1; j++){
			//Scorro le sottomatrici
			//Inizializzo ad ogni ciclo il contatore di 1
			cont1=0;
			for(x=0; x<h; x++){
				for(y=0; y<h; y++){
					if(M[i+x][j+y]==1){
						cont1++;
					}
				}
			//Se trovo k volte 1 nella sottomatrice, aumento di uno contsott
			if(cont1==k){
				contsott++;
			}
			}
		}
	}
	printf("Data la matrice M, esistono %d sottomatrici %dx%d tali che 1 sia contenuto esattamente %d volte\n", contsott, h,h,k);
return 0;
	}
