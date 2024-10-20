/*Scrivere una funzione che riceve in input due array di N elementi e copia nel secondo gli elementi di valore pari 
del primo senza lasciare buchi. La funzione restituisce il numero di elementi copiati.*/
#include<stdio.h>
#define N 5
int copia(int A[], int B[]){
	int i, j=0;
	for(i=0; i<N; i++){
		if(A[i]%2==0){
			B[j]=A[i];
			j++;
		}
	}
	return j;
}
int main (){
	int v[N]={1,2,4,5,6}, w[N]={0};
	int i;
	printf("Il numero di elementi copiati e %d\n", copia(v, w));
	printf("I due vettori sono:\n");
	printf("\nv: ");
	for(i=0; i<N; i++){
		printf("%3d", v[i]);
	}
	printf("\nw: ");
	for(i=0; i<N; i++){
		printf("%3d", w[i]);
	}
return 0;
}
