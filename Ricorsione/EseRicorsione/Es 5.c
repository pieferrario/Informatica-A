/*Scrivere un programma C che stampi sullo standard output tutti i valori del triangolo di Tartaglia per un certo ordine N, utilizzando una funzione ricorsiva:  
	int cobin(int n, int k); 	
1								n = 0
1	1							n = 1
1	2	1						n = 2
1	3	3	1					n = 3
1	4	6	4	1				n = 4
1	5	10	10	5	1			n = 5
1	6	15	20	15	6	1		n = 6
*/
#include<stdio.h>
int cobin(int n, int k){
	if(n<0 || k<0 || n<k){
		printf("Errore\n");
		return 0;
	}
	//Caso base: ci si trova agli estremi
	if(k==0 || k==n){
		return 1;
	}
	//Passo induttivo: ogni numero e la somma di quelli con n-1, k-1, k;
	return cobin(n-1, k)+cobin(n-1, k-1);
}
int main (){
	int n, k, N;
	printf("Inserire l'indice N: ");
	scanf("%d", &N);
	for (n=0; n<N; n++){
		for(k=0; k<=n; k++){
			printf("%5d", cobin(n,k));
		}
		printf("\n");
	}
return 0;
}