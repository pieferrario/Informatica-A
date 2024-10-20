/*Scrivere un programma che acquisisce una sequenza di caratteri terminata dal carattere 'invio' e stabilisce se la sequenza 
e palindroma oppure no (per esempio, "ada" e palindroma perche si legge allo stesso modo sia da destra sia da sinistra)*/
#include<stdio.h>
#include<string.h>
#define n 100
int main (){
	char stringa[n];
	int i, lung, cont=0, flag=1;
	printf("Inserire la stringa da verificare: ");
	scanf("%s", stringa);
	lung=strlen(stringa)-1;
	for(i=0; i<lung/2; i++){
		if(stringa[i]!=stringa[lung-i]){
			flag=0;
		}
	}
	if(flag){
		printf("\nLa sequenza %s e palindroma\n", stringa);
	}
	else printf("\nLa sequenza %s non e palindroma\n", stringa);
return 0;
}
