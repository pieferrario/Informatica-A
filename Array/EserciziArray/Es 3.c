/*Scrivere un programma C che legge un vettore di lunghezza arbitraria e stampa 1 se il vettore contiene solo valori diversi, 0 altrimenti.*/
#include<stdio.h>
int main (){
	int n, i, j, flag=1;
	printf("Inserire lunghezza del vettore: ");
	scanf("%d", &n);
	int v[n];
	printf("Inserire i valori del vettore:\n");
	for(i=0; i<n; i++){
		printf("%d) ", i+1);
		scanf("%d", &v[i]);
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(v[i]==v[j]&& i!=j){
				flag=0;
			}
		}
		if(flag==0)
		break;
	}
	printf("%d", flag);
	return 0;
}

