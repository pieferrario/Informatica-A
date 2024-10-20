/*Tra i vari modi di scandire le celle di una matrice (NxN), l'ordine diagonale serpeggiante e illustrato in figura (inizia dalla cella m[0][0]).
Si codifichi la funzione: int snakesum(int m[][N], int n)
che:
1. riceve come parametri una matrice **quadrata** m (N e una costante positiva gia definita) e un intero n;
2. se n e **valido**, considera i primi n elementi di m in **ordine diagonale serpeggiante**, altrimenti restituisce -1;
3. restituisce al chiamante la somma degli n numeri incontrati.

**Attenzione:** n e valido se compreso tra 1 e (N*(N + 1)/2), cioe consideriamo solo la "prima meta" della matrice. Con riferimento alla matrice qui a fianco:
- snakesum(m, 2) ? 5
- snakesum(m, -4) ? -1
- snakesum(m, 16) ? -1
- snakesum(m, 1) ? 1
- snakesum(m, 4) ? 12
- snakesum(m, 8) ? 22*/
#include<stdio.h>
#define N 5
int snakesum (int m[N][N], int n){
	int i, j, diag, k, cont_n=0;
	int somma=0;
	if(n<1 || n>(N*(N+1))/2){
		
		return -1;
	}
	for(diag=0; diag<N && cont_n<n; diag++){
		if(diag%2==0){
			i=diag;
			j=0;
			for(k=0;k<diag+1 && cont_n<n; k++){
				somma+=m[i][j];	
				i--;
				j++;
				cont_n++;
			}
		}
		else{
			i=0;
			j=diag;
			for(k=0; k<diag+1 && cont_n<n; k++){
				somma+=m[i][j];
				i++;
				j--;
				cont_n++;
			}
		}
	}
	return somma;
}
int main (){
	int i, j, n;
	int m[N][N]/*={1,4,1,1,3,2,1,7,5,2,5,1,4,0,1,2,3,2,9,3,1,6,8,5,8}*/;
	printf("Riempire la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("Stampo la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
	printf("Inserire l'intero n: ");
	scanf("%d", &n);
	int risultato=snakesum(m, n);
	if(risultato==-1){
		printf("Il valore di n non e valido.\nRisultato: -1");
	}
	else{
	printf("La somma dei primi %d elementi in ordine serpeggiante e: %d", n,risultato);
	}
return 0;
}
