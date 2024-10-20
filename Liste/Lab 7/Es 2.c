/*Scrivere una funzione "pulisci" che, data una lista i cui elementi sono liste di interi, elimina tutte le sottoliste che contengono valori ripetuti.
Si consiglia di utilizzare funzioni ausiliarie per inserimenti e cancellazioni e distruzioni di liste, come illustrato a lezione e nella dispensa.
Scrivere le funzioni necessarie per svolgere l'esercizio subito dopo il main e prima delle funzioni fornite.
Output atteso:
Lista (ogni elemento in una riga)
5 ---> 4 ---> 1 ---> 5 ---> 2 ---> 7 ---> ---|
1 ---> 6 ---> 9 ---> 1 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
1 ---> 5 ---> 1 ---> 1 ---> 2 ---> 8 ---> 9 ---> 0 ---> ---|
1 ---> 3 ---> 2 ---> 4 ---> 0 ---> 9 ---> 8 ---> 6 ---> ---|
1 ---> 2 ---> 9 ---> 8 ---> 4 ---> 0 ---> 9 ---> 0 ---> ---|
1 ---> 8 ---> 7 ---> 8 ---> 3 ---> ---|
1 ---> 3 ---> 4 ---> 2 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
7 ---> 8 ---> 9 ---> ---|
Lista dopo pulizia
1 ---> 3 ---> 2 ---> 4 ---> 0 ---> 9 ---> 8 ---> 6 ---> ---|
1 ---> 3 ---> 4 ---> 2 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
7 ---> 8 ---> 9 ---> ---|*/
#include<stdio.h>
#include<stdlib.h>

typedef struct EL {
	int info;
	struct EL * prox;
} ElemLista;
typedef ElemLista * SottoLista;

typedef struct ELL {
	SottoLista lista;
	struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int controlla_duplicati (SottoLista lista);
int scorri_lista (SottoLista lista, int n);
ListaDiListe Cancella( ListaDiListe lis, SottoLista elem );
ListaDiListe pulisci (ListaDiListe lis);

int main(){
	ListaDiListe lis;
	lis=costruisci();
	printf("Lista (ogni elemento in una riga)\n");
	VisualizzaListaDiListe(lis);


	//TODO: invocazione funzione
	lis=pulisci(lis);	
    printf("Lista dopo pulizia\n");
	VisualizzaListaDiListe(lis);


	return 0;
}
//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
int scorri_lista (SottoLista lista, int n){
	if(lista==NULL){
		return 0;
	}
	lista=lista->prox;
	while(lista != NULL){
		if(lista->info==n){
			return 1;
		}
		lista=lista->prox;
	}
	return 0;
}
int controlla_duplicati(SottoLista lista){
	if(lista==NULL){
		return 0;
	}
	while (lista!=NULL){
		if (scorri_lista(lista, lista->info)){
			return 1;
		}
		lista=lista->prox;
	}
	return 0;
}
ListaDiListe Cancella( ListaDiListe lis, SottoLista elem ) {
    ListaDiListe puntTemp;
	if( lis!=NULL)
	    if( lis->lista == elem ) {
		    puntTemp = lis->prox;
			free( lis );
			return puntTemp; // per cancellare tutte le istanze: return Cancella(PuntTemp, Elem);
        }
		else
		    lis->prox = Cancella( lis->prox, elem );
	return lis;
}

ListaDiListe pulisci(ListaDiListe lis) {
    ListaDiListe prec = NULL, curr = lis;
    while (curr != NULL) {
        if (controlla_duplicati(curr->lista)) {
            if (prec == NULL) {
                // Se il primo elemento deve essere cancellato, aggiorna la testa della lista
                lis = Cancella(curr, curr->lista);
                curr = lis;  // Riposiziona il cursore sulla nuova testa della lista
            } else {
                prec->prox = Cancella(curr, curr->lista);
                curr = prec->prox;
            }
        } else {
            prec = curr;
            curr = curr->prox;
        }
    }
    return lis;
}
ListaDiListe costruisci(){
	int M[8][10]={5,4,1,5,2,7,-1,-1,-1,-1,1,6,9,1,5,7,9,0,-1,-1,1,5,1,1,2,8,9,0,-1,-1,
				  1,3,2,4,0,9,8,6,-1,-1,1,2,9,8,4,0,9,0,-1,-1,1,8,7,8,3,-1,-1,-1,-1,-1,
				  1,3,4,2,5,7,9,0,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1};
	int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
	for(i=0;i<8;i++){
		temp=NULL;for(k=0;k<10;k++)if(M[i][k]!=-1)temp=InsInFondoInt(temp,M[i][k]);
		ris=InsInFondoLista(ris,temp);}
	return ris;
}


SottoLista InsInFondoInt(SottoLista lista,int elem ) {
    SottoLista punt;
    if(lista==NULL) { punt = malloc( sizeof(ElemLista) );
                     punt->prox = NULL; punt->info = elem; return  punt;
    }else{lista->prox = InsInFondoInt(lista->prox,elem); return lista;}
}


ListaDiListe InsInFondoLista(ListaDiListe lista,SottoLista lis ) {
   ListaDiListe punt;
   if(lista==NULL) { punt = malloc( sizeof(NodoLista) );
                     punt->prox=NULL; punt->lista=lis; return  punt;
   }else{lista->prox = InsInFondoLista(lista->prox,lis); return lista;}
}


void VisualizzaListaInt(SottoLista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %d ---> ", lista->info); VisualizzaListaInt( lista->prox );}
}
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox);}
}
