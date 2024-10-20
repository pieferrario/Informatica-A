/*Scrivere un programma C che:
Legge una sequenza di numeri interi e quei numeri compresi tra 0 e 1023 vengono memorizzati in un vettore di nome V.
La lettura termina quando nel vettore sono stati inseriti 10 numeri
Per ogni numero in V il programma esegue la conversione in binario, memorizza i resti ottenuti in un vettore 
R opportunamente dimensionato e stampa il contenuto di R
*/
#include<stdio.h>
#define n 5
#define bit 10
int main (){
	int i, j, v[n], r[bit];
	printf("Inserire %d valori nell'array compresi tra 0 e 1023\n", n);
	for(i=0; i<n; i++){
	do{
		printf("%d) ", i+1);
		scanf("%d", &v[i]);
	}
	while (v[i]<0 || v[i]>1023);
	}
	for(i=0; i<n; i++){
		printf("Il numero %d converito in binario e: ", v[i]);
		for(j=bit-1; j>=0; j--){
			r[j]=v[i]%2;
			v[i]=v[i]/2;
		}
			for(j=0; j<bit; j++)
			printf("%d", r[j]);
			printf("\n");
	}
return 0;
}