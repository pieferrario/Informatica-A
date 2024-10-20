/*Si definisce Triangolare un numero costituito dalla somma dei primi N numeri interi positivi per un certo N.
Ad esempio: per Q = 10 si ha Q =1+2+3+4, da cui N = 4.
Scrivere un programma C che stabilisca se un numero intero positivo Q, letto dallo standard input, e un numero triangolare o meno,
utilizzando soltanto operazioni tra numeri interi. In caso affermativo stampare a video il numero inserito e il massimo degli addendi che lo compongono.
*/
#include<stdio.h>
int main (){
	int n, i, s=0;
	printf("Inserire il numero da controllare: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		s=s+i;
	if (s==n){
		printf("%d e triangolare ed e la somma dei primi %d interi", n, i);
		break;
	}
	if(s>n){
		printf("Il numero non e triangolare");
		break;
	}
	}
	return 0;
}