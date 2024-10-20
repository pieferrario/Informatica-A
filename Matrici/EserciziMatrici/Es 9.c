/*Si scriva un programma che chiede all'utente di riempire una matrice NxN (con N costante globale predefinita), 
un intero len (che deve essere un intero positivo maggiore di 1) e stampa OK se in m e presente almeno una sequenza orizzontale, 
verticale o diagonale, di lunghezza len, di elementi che crescono o diminuiscono linearmente (cioe in cui la differenza tra due elementi successivi e costante). 
Esempi di sequenze lineari:
	1 2 3 4 (lunghezza 4, differenza costante 1)                	4 3 2 1 (lunghezza 4, differenza constante -1) 	
	5 5 5 5 5 5 5 (lunghezza 7, differenza costante 0)
Sono ammesse anche sequenze di lunghezza 1 (che e considerata sempre lineare)
*/
#include<stdio.h>
#define N 5
int main (){
	int len, i, j, m[N][N], diff=0, newdiff=0, cont=0;
	do{
		printf("Inserire lunghezza della sequenza da trovare: ");
		scanf("%d", &len);
	} while (len<1 || len>N);
	printf("Riempire la matrice:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("(%d,%d) ", i, j);
			scanf("%d", &m[i][j]);
		}
	}
	printf("La matrice inserita e:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}

	//Sequenza orizzontale
	for(i=0; i<N-len; i++){
			diff=m[i][0]-m[i][1];
			cont=1;
		for(j=1; j<len; j++){
			newdiff=m[i][j-1]-m[i][j];
			if(diff==newdiff){
				cont++;
				}
			else{
				diff=newdiff;
				cont=1;
			}
			if(cont==len-1){
				printf("Trovata sequenza orizzontale di lunghezza %d\n", len);
				return 1;
			}	
		}
	}
	//Sequenza verticale
	for(i=0; i<N-len; i++){
		diff=m[0][i]-m[1][i];
		cont=1;
		for(j=1; j<len; j++){
			newdiff=m[j-1][i]-m[j][i];
			if(diff==newdiff){
				cont++;
			}
			else{
				diff=newdiff;
				cont=1;
			}
			if(cont==len-1){
				printf("Trovata sequenza verticale di lunghezza %d\n", len);
				return 1;
			}
		}
	}
	//Sequenza diagonale superiore (con diag magg)
	for(i=1; i<N-len; i++){
		diff=m[i-1][0]-m[i][1];
		cont=1;
		for(j=1; j<len; j++){
			newdiff=m[i-1][j-1+i]-m[i][j+i];
			if(diff==newdiff){
				cont++;
			}
			else{
				diff=newdiff;
				cont=1;
			}
			if(cont==len-1){
				printf("Trovata sequenza diagonale superiore di lunghezza %d\n", len);
				return 1;
			}
		}
	}
	//Sequenza diagonale inferiore (senza diag magg)
	for(j=1; i<N-len; i++){
		diff=m[1][j-1]-m[2][j];
		cont=1;
		for(i=2; i<len;i++){
			newdiff=m[i-j+1][j-1]-m[i+j][j];
			if(diff==newdiff){
				cont++;
			}
			else{
				diff=newdiff;
				cont=1;
			}
			if(cont==len-1){
				printf("Trovata sequenza diagonale inferiore di lunghezza %d\n", len);
				return 1;
			}
		}
	}
	printf("Non e stata trovata alcuna sequenza\n");
return 0;
	}