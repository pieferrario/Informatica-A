/*Si scriva un programma che, data una matrice M quadrata NxN di interi e due indici di posizione r e c che rappresentano, rispettivamente,
una riga e una colonna della matrice, stampa "OK" se tutti gli elementi posizionati sulla stessa riga o sulla stessa colonna dell'elemento in (r, c) 
sono minori di M[r][c], "NON OK" altrimenti.

Si completi quindi il main sottostante come da esempi riportati

1 12 0 7
4 3 5 5
6 4 3 8
7 5 2 4

con r = 2, c = 3 stampa "OK"
con r = 0, c = 2 stampa "NON OK"
con r = 1, c = 1 stampa "NON OK"*/
#include <stdio.h>
#define N 4
int main(){
    int M[N][N]={1,12,0,7,
				 4,3,5,5,
				 6,4,3,8,
				 7,5,2,4};
	int r, c, flag=1;
	int i, j;
	printf("Stampo la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", M[i][j]);
		}
		printf("\n");
	}
	printf("Inserire indice di riga: ");
	do{
		scanf("%d", &r);
	} while (r<0 || r>N-1);
	printf("Inserire indice di colonna: ");
	do{
		scanf("%d", &c);
	} while (c<0 || c>N-1);
	
	for(i=0; i<N; i++){
		if(i!=r && M[r][c]<=M[i][c] ){
			flag=0;
			break;
		}
	}
	for(j=0; j<N; j++){
		if(j!=c && M[r][c]<=M[r][j]){
			flag=0;
			break;
		}
	}
	if(flag) printf("OK");
	else printf("Non OK");
    return 0;
}