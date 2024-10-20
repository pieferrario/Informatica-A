/*Scrivere un programma C, completo delle opportune dichiarazioni di variabili, in grado di acquisire in ingresso dall'utente un valore intero positivo num. 
Il programma deve stampare a video tutti i fattori primi di num. 
*/
#include<stdio.h> 
int main (){
	int num, i=2, cont;
	printf("Inserire il numero di cui si vuole sapere la scomposizione in fattori primi: ");
	scanf("%d", &num);
	printf("La scomposizione in fattori primi di %d e ", num); 
	if (num==1){
		printf("1");
	}
	while(num!=1){
		cont=0;
		while(num%i==0){
			cont++;
			num=num/i;			
		}
		printf("%d^%d ", i, cont);
		i++;
}
	return 0;
}

