/*Scrivere un programma che acquisisca una sequenza di 10 numeri interi ed un indice X tra 0 e 9. 
Il programma dovra stampare la somma dei numeri in posizioni minori di X e il prodotto dei numeri in posizioni successive a X.
Questo laboratorio fatelo con gli array*/
#include<stdio.h>
#define n 10
int main (){
	int x, v[n], i, somma=0, prodotto=1;
	do{
	printf("Inserire un indice x: ");
	scanf("%d", &x);
	} while (x<0 || x>9);
	printf("Riempire il vettore:\n");
	for(i=0; i<n; i++){
		printf("%d) ", i+1);
		scanf("%d", &v[i]);
	}
	for(i=0; i<n; i++){
		if(i<x){
			somma+=v[i];
		}
		else {
			prodotto*=v[i];
			}
	}
	printf("Dato l'indice %d, si ha:\nSomma=%d\nProdotto=%d", x, somma, prodotto);
return 0;
}
