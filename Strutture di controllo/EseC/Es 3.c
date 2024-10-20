/*Si scriva un programma in linguaggio C che letto un numero intero positivo dallo standard input, visualizzi a terminale il quadrato
del numero stesso facendo uso soltanto di operazioni di somma.
Si osservi che il quadrato di ogni numero intero positivo N 
puo essere costruito sommando tra loro i primi N numeri dispari.
Esempio: N = 5;  N2 = 1 + 3 + 5 + 7 + 9 = 25. 
*/
#include<stdio.h>
int main (){
	int n, i, s=0;
	printf("Inserire il numero da elevare al quadrato: ");
	do{
		scanf("%d", &n);
	}
	while (n<=0);
	for (i=0; i<n; i++){
		s=s+(i+i+1); // una versione piu elegante e s=s+(2*i+1)M
	}
	printf("\n%d^2 = %d", n,s);
}

