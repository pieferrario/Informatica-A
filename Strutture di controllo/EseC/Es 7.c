/*Scrivere un programma C, in grado di acquisire in ingresso dall'utente un valore intero num e una sequenza di interi che termina con uno 0 (zero). 
Il programma deve stampare a video il numero di valori pari nella sequenza che sono divisori di num. 
0 viene considerato come valore sentinella*/
#include<stdio.h>
int main (){
	int n, div, count=0;
	printf("Inserire il numero da studiare:\n");
	scanf("%d", &n);
	printf("Inserire la sequenza di possibili divisori:\n");
	do{
		scanf("%d", &div);
		if(div!=0 && n%div==0 && div%2==0){
		count++;
		}
	}
	while (div!=0);
	printf("I divisori pari di %d della sequenza inserita sono: %d", n, count);
	return 0;
}
