/*Partendo dal file lista.c si scriva una funzione che ricevute due liste di interi (senza ripetizioni) restituisce una lista contenente tutti e 
soli gli elementi divisibili per 3 delle due liste (senza ripetizioni).*/
#include<stdio.h>
#include<stdlib.h>


typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;


int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );
int Controlla_Presente(ListaDiElem lista, int elem){
	while(lista!=NULL){
		if(elem==lista->info){
			return 1;
		}
		else{
			lista=lista->prox;
		}
	}
	return 0;
}
ListaDiElem Multipli3(ListaDiElem lista1, ListaDiElem lista2){
	ListaDiElem lis=NULL;
	//Caso base: le liste sono vuote, restituisco NULL;
	if(lista1==NULL && lista2==NULL){
		return NULL;
	}
	//In maniera iterativa:
	while (lista1!=NULL){
		if((lista1->info)%3==0 && Controlla_Presente(lis, lista1->info)==0){
			lis=InsInTesta(lis, lista1->info);
		}
		lista1=lista1->prox;
	}
	while(lista2!=NULL){
		if(lista2->info%3==0 && Controlla_Presente(lis, lista2->info)==0){
			lis=InsInTesta(lis, lista2->info);
		}
		lista2=lista2->prox;
	}
	return lis;
}

int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;     
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    lista=Multipli3(lista1, lista2);
    VisualizzaLista(lista);
    printf("\n\n");
    
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
