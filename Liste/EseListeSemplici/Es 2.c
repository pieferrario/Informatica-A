/*Trovare con una funzione ricorsiva l’elemento massimo in una lista*/
#include<stdio.h>
#include<stdlib.h>
typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;
int trova_max(ListaDiElem lista){
	//Caso base negativo: lista vuota
	if(lista==NULL){
		printf("La lista è vuota");
		return -1;
	}
	//Caso base: 
	if(lista->prox==NULL){
		return lista->info;
	}
	int max=trova_max(lista->prox);
	//Passo induttivo positivo
	if(lista->info>max){
		return lista->info;
	}
	else return max;
}

int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );

int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;     
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");

//    VisualizzaLista(lista);
//    printf("\n\n");
    
    //inserire qui il codice
    printf("\nIl massimo della lista1 è: %d", trova_max(lista1));
    printf("\nIl massimo della lista2 è: %d", trova_max(lista2));
    
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
