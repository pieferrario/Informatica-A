/*Due liste di interi si dicono equipotenti se sono di uguale lunghezza e, confrontando i valori in posizioni corrispondenti, risulta che i valori della prima lista maggiori dei corrispondenti valori nella seconda sono esattamente in numero uguale ai valori della seconda lista maggiori dei corrispondenti valori nella prima.
Data la lista definita come:    
	typedef struct EL { int valore; struct EL * next; } Nodo;
	typedef Nodo * Lista;
si descriva un algoritmo e si proponga una codifica per la funzione di prototipo  
	int equipotenti ( Lista L1, Lista L2 );
	che restituisce 1 se le liste sono equipotenti, 0 altrimenti.

*/
#include<stdio.h>
typedef struct El{
	int info;
	struct El * prox;
} Nodo;
typedef Nodo * Lista;
int controlla_equipotenti(Lista lista1, Lista lista2){
	int cont_maggiori=0, cont_minori=0;
	//avvio un ciclo che scorre su entrambe le liste;
	while (lista1 != NULL && lista2!=NULL){
		//se trovo in lista1 un elemento maggiore, aumento il cont;
		if(lista1->info>lista2->info){
			cont_maggiori++;
		}
		//se trovo in lista 1 un elemento minore, aumento il cont;
		if(lista1->info < lista2->info){
			cont_minori++;
		}
		//faccio avanzare entrambe le liste al nodo successivo;
		lista1=lista1->prox; 
		lista2=lista2->prox;
	}
	return (lista1==lista2)&&(cont_minori==cont_maggiori); //restituisce 1 solo se le due liste sono uguali e rispettano la definizione di equipotenti
}
int main(){
	//Non e richiesto il main
	return 0;
}