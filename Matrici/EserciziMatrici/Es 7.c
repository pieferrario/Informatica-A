/*Si scriva un programma in linguaggio C che stampi sullo standard output il contenuto di un quadrato magico di dimensione n, con n dispari. 
Un quadrato magico di ordine n contiene i primi n numeri naturali ( 1, 2, 3, .., n2 ) disposti in modo tale che la somma dei numeri su ogni riga, 
su ogni colonna e sulle due diagonali principali sia sempre la stessa.
Es: n = 3
	4 9 2       0 0 0       0 0 2       0 0 2       4 0 2       4 0 2       4 0 2       4 0 2       4 0 2       4 9 2 
	3 5 7       0 0 0       0 0 0       3 0 0       3 0 0       3 5 0       3 5 0       3 5 7       3 5 7       3 5 7
	8 1 6       0 1 0       0 1 0       0 1 0       0 1 0       0 1 0       0 1 6       0 1 6       8 1 6       8 1 6
Esiste una regola molto semplice per percorrere la matrice disponendo i numeri interi in ordine crescente. Partendo col posizionare un 1 nella posizione
centrale sull'ultima riga, si percorre la matrice incrementando di una unita il numero di riga e il numero di colonna dell'elemento attuale, avendo cura di 
considerare i bordi opposti della matrice come adiacenti. Se durante questa operazione si individua una cella vuota si scrive il numero successivo; 
altrimenti, il numero successivo, viene posizionato nella cella avente riga immediatamente superiore a quella dell'ultimo numero inserito. 
*/
#include<stdio.h>
#define N 51
int main (){
	int n, i, j, k, m[N][N]={0};
	do{
		printf("Inserire la dimensione del quadrato: ");
		scanf("%d", &n);
		if(n%2==0 || n<0){
			printf("\nIl numero inserito non va bene. Riprovare\n");
		}
	} while(n%2==0 || n<0);
	i=n-1;
	j=n/2;
	for(k=1; k<=n*n; k++){
		m[i][j]=k;
		if(m[(i+1+n)%n][(j+1+n)%n]==0){
			i=(i+1+n)%n;
			j=(j+1+n)%n;
		}
		else{
			i=(i-1)%n;
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
return 0;
}
