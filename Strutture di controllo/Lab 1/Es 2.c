/*Scrivere un programma per il calcolo delle tabelline. Il programma riceve dall'utente due numeri.
Il primo corrisponde al numero di cui e necessario calcolare la tabellina mentre il secondo indica la lunghezza della tabellina richiesta.
Es: 2, 10 produce come risultato: 2 4 6 8 10 12 14 16 18 20
Es: 3, 8 produce come risultato: 3 6 9 12 15 18 21 24
Accettare solamente numeri positivi: se l'utente inserisce un numero negativo mostrare un messaggio di errore e richiedere un altro numero*/
#include<stdio.h>
int main (){
	int n, lung, i, prod;
	do{
		printf("Inserire numero: ");
		scanf("%d", &n);
		if(n<0)
			printf("Numero non valido. Riprovare\n");
	}
	while(n<0);
	do{
		printf("Inserire lunghezza: ");
		scanf("%d", &lung);
		if(lung<0)
			printf("Numero non valido. Riprovare\n");
	}
	while(lung<0);
	printf("La tabellina di %d di lunghezza %d e\n", n, lung);
	for (i=0; i<lung; i++){
		prod=n*(i+1);
		printf("%d ", prod);
	}
	return 0;
}

