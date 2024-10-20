/*Scrivere un programma che chiede due numeri all’utente e ne stampa a video tutti i divisori comuni*/
#include<stdio.h>
int main (){
	int n1, n2, i, temp;
	printf("Inserire il primo numero: ");
	scanf("%d", &n1);
	printf("Inserire il secondo numero: ");
	scanf("%d", &n2);
	if(n1>n2){
		temp=n1;
		n1=n2;
		n2=temp;
	}
	printf("Lista dei divisori comuni: ");
	for (i=0; i<n1; i++){
		if(n1%(i+1)==0 && n2%(i+1)==0){
			printf("%d ", i+1);
		}
	}
	return 0;
}

