/*Partendo dal file lista.c si scriva una funzione che ricevute due liste di interi senza duplicati calcola la media degli elementi comuni tra le due liste.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct EL {
	int info;
	struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;

int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );

int Controlla_Presente (ListaDiElem lista, int elem){
	while(lista!=NULL){
		if(elem==lista->info){
			return 1;
		}
		else lista=lista->prox;
	}
	return 0;
}
float calcola_media(ListaDiElem lista1, ListaDiElem lista2) {
	int cont=0, somma=0;
	if(lista1==NULL || lista2==NULL){
		return 0;
	}
	while(lista1!=NULL){
		if(Controlla_Presente(lista2, lista1->info)){
			somma+=lista1->info;
			cont++;
		}
		lista1=lista1->prox;
	}
	if(!cont) return 0;
	return (float)somma/cont;
}

int main() {
	ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;
	lista1=crea1();
	lista2=crea2();
	VisualizzaLista(lista1);
	printf("\n\n");
	VisualizzaLista(lista2);
	printf("\n\n");

	VisualizzaLista(lista);
	printf("\n\n");

	//inserire qui il codice
	printf("La media degli elementi comuni sulle due liste e: %.2f", calcola_media(lista1, lista2));

	return 0;
}

void VisualizzaLista( ListaDiElem lista ) {
	if ( ListaVuota(lista) )
		printf(" ---| \n");
	else {
		printf(" %d ---> ",lista->info);
		VisualizzaLista(lista->prox);
	}
}

ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
	ListaDiElem punt;
	punt = (ListaDiElem) malloc(sizeof(ElemLista));
	punt->info = elem;
	punt->prox = lista;
	return  punt;
}

int ListaVuota( ListaDiElem lista ) {
	return lista == NULL;
}

ListaDiElem crea1() {
	ListaDiElem lis=NULL;
	lis=InsInTesta( lis, 2 );
	lis=InsInTesta( lis, 12 );
	lis=InsInTesta( lis, 1 );
	lis=InsInTesta( lis, 4 );
	lis=InsInTesta( lis, 8 );
	lis=InsInTesta( lis, 34 );
	lis=InsInTesta( lis, 78 );
	lis=InsInTesta( lis, 26 );
	lis=InsInTesta( lis, 33 );
	lis=InsInTesta( lis, 11 );
	lis=InsInTesta( lis, 67 );
	lis=InsInTesta( lis, 83 );
	lis=InsInTesta( lis, 92 );
	return lis;
}

ListaDiElem crea2() {
	ListaDiElem lis=NULL;
	lis=InsInTesta( lis, 2 );
	lis=InsInTesta( lis, 10 );
	lis=InsInTesta( lis, 15 );
	lis=InsInTesta( lis, 48 );
	lis=InsInTesta( lis, 82 );
	lis=InsInTesta( lis, 11 );
	lis=InsInTesta( lis, 92 );
	lis=InsInTesta( lis, 22 );
	lis=InsInTesta( lis, 36 );
	lis=InsInTesta( lis, 19 );
	lis=InsInTesta( lis, 69 );
	return lis;
}
