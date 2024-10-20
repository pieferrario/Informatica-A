/*Scrivere una funzione che riceve in input una matrice di interi di dimensione N*N e un punto cosi definito
	typedef struct {int x; int y;} punto
	La funzione deve restituire il numero di multipli dell'elemento della matrice di cui sono state fornite le coordinate.
*/
#include<stdio.h>
#define N 3
typedef struct{
	int x;
	int y;
} Punto;
int n_multipli(int A[N][N], Punto a){
	int i, j, cont=0;
	if (A[a.x][a.y] == 0) {
        printf("Non si puo calcolare i multipli di 0.\n");
        return 0;
    }
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(A[i][j]%A[a.x][a.y]==0){
				cont++;
			}
		}
	}
	return cont;
}
int main (){
	int i, j;
	int m[N][N];
	Punto p;
	printf("Riempire la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("Inserire le coordinate dell'elemento:\n");
	printf("x=");
	scanf("%d", &p.x);
	printf("y=");
	scanf("%d", &p.y);
    if (p.x < 0 || p.x >= N || p.y < 0 || p.y >= N) {
    printf("Coordinate fuori dai limiti della matrice.\n");
    return 1; // Esce con codice di errore
}
	
	printf("La matrice inserita e:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	printf("Le coordinate di p sono: (%d; %d)\n", p.x, p.y);
	printf("I multipli di p in m sono: %d", n_multipli(m,p));
return 0;
}
