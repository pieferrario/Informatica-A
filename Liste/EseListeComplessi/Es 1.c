/*Sia data una lista concatenata semplice non ordinata di interi senza valori duplicati. La struttura è:
	typedef struct Elem { int    dato;
		struct Elem * next;  } Nodo;
	typedef Nodo * Lista;
La lista rappresenta un insieme di numeri. 
Una funzione incrocia() riceve come parametri: la lista, un vettore dinamico di interi (anch’esso senza duplicati, allocato dal programma chiamante) e
la lunghezza di tale vettore dinamico. La funzione rimuove dalla lista originaria (deallocandoli) tutti i valori contenuti nel vettore (se presenti) 
e aggiunge in coda tutti i valori contenuti nel vettore e non nella lista originaria.
Si definisca opportunamente il prototipo della funzione incrocia() e si descriva sinteticamente (ma in modo preciso) come opera un algoritmo che la implementa. 
In particolare, si badi a evitare che un valore presente nella lista e non nel vettore sia prima aggiunto e poi rimosso (o viceversa)
Si codifichi poi in C la funzione secondo l’algoritmo precedentemente dettagliato
*/
#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct El{
	int info;
	struct El * prox;
} Nodo;
typedef Nodo * Lista;
Lista InsInFondo( Lista lista, int elem ) {
    Lista punt;
	if( lista==NULL ) {
	    punt = malloc( sizeof(Nodo) );
		punt->prox = NULL;
		punt->info = elem;
		return punt;
	} else { 
	    lista->prox = InsInFondo( lista->prox, elem);
		return lista;
	}
}
int Controlla_presente (Lista lista, int elem){
	if(lista==NULL){
		return 0;
	}
	while(lista!=NULL){
		if (lista->info==elem){
			return 1;
		}
		else{
			lista=lista->prox;
		}
	}
	return 0;
}
Lista Rimuovi_nodo(Lista lista, int elem){
	Lista temp;
	if(lista!=NULL){
		if(lista->info==elem){
			temp=lista->prox;
			free(lista);
			return temp;
		}
		else{
			lista->prox=Rimuovi_nodo(lista->prox, elem);
			return lista;
		}
	}
}

Lista Incrocia(Lista lis, int * v, int n){
	int i;
	if(n==0){
		return lis;
	}
	else{
		if(Controlla_presente(lis, v[0])){
			lis=Rimuovi_nodo(lis, v[0]);
		}
		else
			lis=InsInFondo(lis, v[0]);
	}
	return Incrocia(lis, &v[1], n-1);
}
int main (){

return 0;
}
