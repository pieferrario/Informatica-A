/*Scrivere un programma in C che legge un vettore di interi di dimensione fissata e ne stampa la somma*/
#include<stdio.h>
#define len 5
int main (){
	int i, n, v[len], somma=0;
	printf("Inserire i valori nell'array:\n");
	for (i=0; i<len; i++){
		scanf("%d", &v[i]);
		somma+=v[i];
	}
	printf("La somma vale: %d", somma);
return 0;
}

