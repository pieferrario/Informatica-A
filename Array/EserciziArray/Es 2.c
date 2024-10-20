/*Scrivere un programma in C che legge un vettore di interi di dimensione fissata, inverte il vettore e lo stampa.*/
#include<stdio.h>
#define len 5
int main (){
	int i, v[len], temp;
	printf("Inserire gli elementi nel vettore:\n");	
	for (i=0; i<len; i++){
		scanf("%d", &v[i]);
	}
	for(i=0; i<len/2; i++){
		temp=v[i];
		v[i]=v[(len-1)-i];
		v[(len-1)-i]=temp;
	}
	printf("Il vettore invertito e: ");
	for(i=0; i<len; i++){
		printf("%d ", v[i]);
	}
	return 0;
}

