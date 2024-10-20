/*Scrivere un programma C che legge da tastiera una sequenza di 100 numeri interi.
Dopo avere letto tutti i numeri cercare le coppie di  numeri tali che il primo sia il doppio dell'altro.

Esempio
	1 5 6 10 3 4 7 0 2 
	stampa
	6 3 / 10 5 / 4 2 / 2 1
*/
#include<stdio.h>
#define n 9
int main (){
	int i, j, v[n];
	printf("Riempire il vettore:\n");
	for(i=0; i<n; i++){
		printf("%d) ", i+1);
		scanf("%d", &v[i]);
	}
	printf("Le coppie di numeri tali che uno sia il doppio dell'altro sono:\n");
	for(i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(v[i]==2*v[j] && i!=j){
				printf("%d %d / ", v[i], v[j]);
			}
		}
	}
return 0;
}

