/*Dato un numero positivo Q, scrivere la sua rappresentazione in binario naturale, indicando anche il minimo numero di bit utilizzato.
Il programma dovra esibire un comportamento come nell'esempio seguente: 
	Input: 19 in decimale 
	Output: con 5 bit  =  10011 in binario.
*/
#include<stdio.h>
int main (){
	int n, pot=2, cont=1;
	do{
	printf("Inserire un intero positivo da convertire in binario: ");
	scanf("%d", &n);}
	while (n<0);
	//Calcolo il numero di bit cercando la potenza di 2 tale che n<pot;
	while (n>=pot){
		pot=2*pot;
		cont++;
	}
	printf("Per rappresentare %d in binario sono necessari %d bit\n", n, cont);
	//Per convertire il numero calcolo potenza 2^(cont-1)esima e verifico se essa sia < di n. In tal caso, assegno valore 1, dimezzo pot e sottraggo n-pot;
	printf("La conversione in binario e: ");
	while(cont>0){
		pot=pot/2;
		if(pot<=n){
			printf("1");
		n=n-pot;
		}
		else{
			printf("0");
		}
		cont--;
	}
return 0;
}

