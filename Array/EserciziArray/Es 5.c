/*Si scriva un programma C che all'interno del main consenta di inizializzare da tastiera un vettore di interi di lunghezza massima pari a 20. 
La lunghezza effettiva della sequenza acquisita e stabilita dall'utente (ad esempio, acquisendo da tastiera il valore di una variabile n). 
Il programma dovra stampare il vettore, scorrere il vettore e stampare gli elementi del vettore che hanno un numero pari nella posizione immediatamente precedente
alla propria. 
Per esempio, se l'utente sceglie di inserire 10 valori, avendo letto in input e memorizzato nell'array i seguenti interi: 
	1 2 3 4 5 6 7 8 9 0 
	Il programma produrra il seguente output: 
	1 2 3 4 5 6 7 8 9 0 
	3 5 7 9 
*/
#include<stdio.h>
#define max 20
int main (){
	int n, i;
	do{
	printf("Inserire lunghezza del vettore: ");
		scanf("%d", &n);
	} while (n>max || n<=0);
	int v[n];
	printf("Riempire il vettore:\n");
	for(i=0; i<n; i++){
		printf("%d) ", i+1);
		scanf("%d", &v[i]);
	}
	printf("Il vettore inserito e:\n");
	for (i=0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\nGli elementi del vettore che hanno un numero pari nella posizione immediatamente precedente sono:\n");
	for(i=1; i<n; i++){
		if(v[i-1]%2==0){
			printf("%d ", v[i]);
		}
	}
	return 0;
}

