/*Scrivere un programma che riceva in ingresso dall'utente un vettore di 5 caratteri tutti minuscoli.
Il programma dica all'utente se le lettere contenute nel vettore sono in ordine alfabetico.*/
#include<stdio.h>
#define n 5
int main (){
	char v[n];
	int i, flag=1;
	printf("Inserire caratteri: ");
	for(i=0; i<n; i++){
		do{
		printf("%d) ", i+1);
		scanf("%c", &v[i]);
		fflush(stdin);
		}
		while(v[i]<97 || v[i]>122);
	}
	for(i=0; i<n-1; i++){
		if(v[i+1]<=v[i]){
			flag=0;
		}
		if(flag==0) break;
	}
	if(flag) printf("I caratteri sono in ordine alfabetico");
	else printf("I caratteri NON sono in ordine alfabetico");
return 0;
}
