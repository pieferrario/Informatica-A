/*Si scriva un programma in linguaggio C che letto un numero intero positivo dallo standard input,
visualizzi a terminale il cubo del numero stesso facendo uso soltanto di operazioni di somma.
*/
#include<stdio.h>
int main (){
	int i, n, quad=0, cubo=0;
		printf("Inserire il numero da elevare al cubo: ");
	do{
		scanf("%d", &n);
	}
	while (n<=0);
	for (i=0; i<n; i++){
		quad=quad+(i+i+1); // una versione piu elegante e s=s+(2*i+1)M
	}
	for (i=0; i<n; i++){
		cubo=cubo+quad;
	}
	printf("%d^3 = %d", n, cubo);
}