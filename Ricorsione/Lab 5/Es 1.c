/*Si codifichi una funzione ricorsiva
intis_power(int n, int b)
che controlla se un numero intero n e una potenza del numero intero b, restituendo 0 o 1.
Per farlo, si consideri la seguente proprieta: n e una potenza di b se e divisibile per b e inoltre n/b e a sua volta una potenza di b.
Si badi ad operare correttamente anche nei casi b=0, b=1*/
#include<stdio.h>
int is_power(int n, int b){
	//Caso b==1
	if(b==1){
		if(n==1){
			return 1;
		}
		else return 0;
	}
	//Caso base negativo: n%b!=0;
	if(n%b!=0){
		return 0;
	}
	//Caso base n/b=1
	if(n/b==1){
		return 1;
	}
	return is_power(n/b, b);
}
int main (){
	int n, b;
	printf("Inserire il primo numero: ");
	scanf("%d", &n);
	if(n<0){
		printf("Il numero inserito non è valido\n");
		return -1;
	}
	printf("Inserire il secondo numero: ");
	scanf("%d", &b);
	if(b==0){
		printf("Il numero inserito non è valido\n");
		return -1;
	}
	switch(is_power(n,b)){
		case 0: printf("%d non è una potenza di %d", n,b); break;
		case 1: printf("%d è una potenza di %d", n, b); break;
	}
return 0;
}
