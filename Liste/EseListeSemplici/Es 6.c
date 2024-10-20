/*Si progetti e codifichi una funzione C che riceve in ingresso una lista definita
	typedef struct Node { int numero;
	struct Node * next; } Nodo;
	typedef Nodo * Lista;
La funzione deve verificare se l'andamento della lista e monotono crescente, cioe se ogni elemento e strettamente superiore al suo predecessore.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct El{
	int info;
	struct El *prox;
	} Elem;
typedef Elem * Lista;
int verifica_monotonia(Lista lista){
	//Caso base: lista vuota
	if(lista==NULL){
		return 1;
	}
	//Caso base lista non vuota
	if(lista->prox==NULL){
		return 1;
	}
	if(lista->info<lista->prox->info){
		return verifica_monotonia(lista->prox);
	}
	else return 0;
}
Lista InsInTesta (Lista lista, int elem){
	Lista punt;
	punt=malloc(sizeof(Elem));
	punt->info=elem;
	punt->prox=lista;
	return punt;	
}
Lista crea_lista1(){
	Lista lista=NULL;
	lista=InsInTesta(lista, 10);
	lista=InsInTesta(lista, 9);
	lista=InsInTesta(lista, 8);
	lista=InsInTesta(lista, 7);
	lista=InsInTesta(lista, 6);
	lista=InsInTesta(lista, 5);
	lista=InsInTesta(lista, 4);
	lista=InsInTesta(lista, 3);
	lista=InsInTesta(lista, 2);
	lista=InsInTesta(lista, 1);
	return lista;
}
Lista crea_lista2(){
	Lista lista=NULL;
	lista=InsInTesta(lista, 10);
	lista=InsInTesta(lista, 9);
	lista=InsInTesta(lista, 8);
	lista=InsInTesta(lista, 7);
	lista=InsInTesta(lista, 5);
	lista=InsInTesta(lista, 6);
	lista=InsInTesta(lista, 4);
	lista=InsInTesta(lista, 3);
	lista=InsInTesta(lista, 2);
	lista=InsInTesta(lista, 1);
	return lista;
}

int main (){
	Lista lista1=crea_lista1();
	Lista lista2=crea_lista2();
	switch(verifica_monotonia(lista1)){
		case 0: printf("La lista 1 non e monotona\n");
			break;
		case 1: printf("La lista 1 e monotona\n");
			break;
	}
	switch(verifica_monotonia(lista2)){
		case 0: printf("La lista 2 non e monotona\n");
			break;
		case 1: printf("La lista 2 e monotona\n");
			break;
	}
return 0;
}