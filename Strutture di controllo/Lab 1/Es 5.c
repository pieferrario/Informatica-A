/*Si realizzi un programma che legga da tastiera un valore intero N, compreso tra 1 e 10, e stampi a video un "quadrato di asterischi" di lato N.

Esempio con N=5

*****
*****
*****
*****
*****

Si realizzi una variante del programma per visualizzare solo i lati del quadrato*/
#include<stdio.h>
int main (){
	int i, j, n;
	do{
	printf("Inserire la dimensione del lato: ");
	scanf("%d", &n);
	}
	while(n<1||n>10);
	printf("Quadrato di asterischi (pieno)\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
		printf("* ");
		printf("\n");
	}
	printf("\nQuadrato di asterischi (vuoto)\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==0 || i==n-1){
				printf("* ");
				}
			else{
				if(j==0 || j==n-1){
					printf("* ");
				}
				else{
					printf("  ");
				}
			}
		}
		printf("\n");
	}
return 0;
}

