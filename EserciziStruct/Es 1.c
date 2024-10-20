/*Definire tipi di dato per un PRA:
Il tipo dati Motoveicolo rappresenta i dati di un motoveicolo. Questi dati si compongono di:
targa del motoveicolo (7 lettere)
marca del motoveicolo (massimo 15 caratteri),
modello (massimo  20  caratteri),
cilindrata  (in  cc),
potenza  (in  kW), 
categoria  (massimo 16 caratteri).
Il tipo dati Proprietario  rappresenta  i  dati  di  una  persona  (il  proprietario  del motoveicolo):
nome  (massimo 30  caratteri),
cognome (massimo 40 caratteri),
codice  fiscale (16 caratteri). 
Il tipo dati VocePRA  rappresenta  una  singola  voce  nel  registro  automobilistico;  una  voce  si compone  di  2  elementi: 
i  dati  del  proprietario  del motoveicolo  ed  i  dati  del motoveicolo stesso. 
Il tipo dati PRA rappresenta un tipo adatto a contenere i dati di un PRA. Questo tipo di dati e un elenco di voci del PRA
(si suppone che un PRA non possa contenere piu di 10.000 elementi), piu un contatore che dice quante voci sono effettivamente presenti nel PRA. 
Scrivere un programma che estrae l'automobilista con l'auto con cilindrata maggiore
Scrivere un programma che estrae l'automobilista con la somma delle cilindrate delle sue auto maggiore
*/
#include<stdio.h>
#include<string.h>
int main (){
	typedef struct{
		char targa[7];
		char marca [15];
		char modello[20];
		int cilindrata;
		float potenza;
		char categoria[16];
	} Dati_motoveicolo;
	typedef struct{
		char nome[30];
		char cognome[40];
		char cf[16];
	} Dati_proprietario;
	typedef struct{
		Dati_motoveicolo motoveicolo;
		Dati_proprietario proprietario;
	}VocePRA;
	typedef struct{
		VocePRA elementi[10000];
		int n_elem;
	}PRA;
	PRA p;
	int maxcil=0, i, j;
	Dati_proprietario prop;
	for(i=0; i<p.n_elem; i++){
		if(p.elementi[i].motoveicolo.cilindrata>maxcil){
			maxcil=p.elementi[i].motoveicolo.cilindrata;
			prop=p.elementi[i].proprietario;
		}
	}
	int somma=0, max_somma=0;
	for(i=0; i<p.n_elem; i++){
		somma=0;
		for(j=0; j<p.n_elem; j++){	
			if(strcmp(p.elementi[i].proprietario.cf,p.elementi[j].proprietario.cf)==0){
				somma+=p.elementi[j].motoveicolo.cilindrata;
			}
		}
		if(somma>max_somma){
			max_somma=somma;
			prop=p.elementi[i].proprietario;
		}
	}
return 0;
}
