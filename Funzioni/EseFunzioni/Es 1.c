/*Scrivere in C una funzione f che ha in ingresso un vettore A di interi gia caricato e restituisce, attraverso un opportuno parametro, 
un vettore di tipo che contiene gli stessi elementi del vettore di ingresso ma in ordine inverso, inoltre la funzione restituisce il prodotto di tutti gli elementi di A.*/
#include<stdio.h>
# define N 5
int f(int A[], int B[]);
int main (){
	int v[N], w[N];
	int prod, i;
	printf("Riempire il vettore:\n");
	for(i=0; i<N; i++){
		scanf("%d", &v[i]);
	}
	printf("Il prodotto degli elementi di A e: %d\n", f(v, w));
	printf("L'array invertito e: ");
	for(i=0; i<N; i++){
		printf("%3d", w[i]);
	}
return 0;
}
int f(int A[], int B[]){
	int i, prod=1;
	for(i=0; i<N; i++){
		B[N-1-i]=A[i];
		prod*=A[i];
	}
	return prod;
}
