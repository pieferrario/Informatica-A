/*Scrivere un programma che acquisisca una sequenza di 10 numeri interi ed un indice X tra 0 e 9. 
Il programma dovra stampare la somma dei numeri in posizioni minori di X e il prodotto dei numeri in posizioni successive a X.
*/
#include<stdio.h>
#define len 10
int main (){
	int n, x, cont, i, somma=0, prod=1;
	printf("Inserire l'indice: ");
	scanf("%d", &x);
	printf("Inserire la sequenza:\n");
	for(i=0; i<len; i++){
		scanf("%d", &n);
		if(i<x){
		somma+=n;
		}
		else{
			prod*=n;
		}
	}
	printf("La somma dei numeri in posizione minore di %d vale: %d \n Il prodotto dei numeri in posizione maggiore di %d vale: %d", x, somma, x, prod);
		
	};
	


