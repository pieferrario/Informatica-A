/*Scrivere un programma (senza usare array) che richiede l'inserimento di voti ottenuti in un certo numero di corsi.
Il programma chiede qual e il numero di voti da inserire. Per ciascuno, l'utente deve inserire numero di crediti e voto ottenuto (in 30imi). 
Il programma infine stampa la media pesata dei corsi e il numero totale dei crediti. Si ricorda che la media pesata, ad esempio su due voti, si calcola come:
media = (voto1*crediti1+voto2*crediti2)/(crediti1+crediti2).*/
#include<stdio.h>
int main (){
	int i, n, voto, crediti, somma_vc=0, somma_c=0;
	float media;
	printf("Inserire il numero di voti: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
	do{
	printf("\nVoto %d: ", i+1);
	scanf("%d", &voto);
	} while(voto<0 || voto>30);
	printf("\nCrediti: ");
	scanf("%d", &crediti);
	somma_vc+=voto*crediti;
	somma_c+=crediti;
	}
	media=(float)somma_vc/somma_c;
	printf("La media pesata e: %.2f \nIl numero di cfu totali e %d", media, somma_c);
	return 0;
}

