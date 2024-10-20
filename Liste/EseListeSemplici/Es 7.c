/*Si progetti e codifichi una funzione C che riceve in ingresso una lista definita
	typedef struct Node { int numero;
	                                     struct Node * next; } Nodo;
	typedef Nodo * Lista;
	che contiene solo valori positivi.
Definiamo picchi della lista quei valori che sono preceduti e seguiti nella lista da valori piu piccoli della loro meta. Il primo e l'ultimo elemento della lista non possono essere picchi.
Ad esempio nella lista
	4 9 12 36 16 23 87 34 18 64 33 
	36 e 87 sono picchi (perche 36/2=18, 18>12 e 18>16 e 87/2=43,5, 43,5>23 e 43,5>34)   
Si progetti e codifichi una funzione C che riceve in ingresso una lista definita come sopra e restituisce il numero di picchi che la lista contiene.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct El{
	int info;
	struct El * prox;
} Nodo;
typedef Nodo * Lista;
int conta_picchi(Lista lista){
	int cont=0;
	//Caso base: lista vuota, ultimo e penultimo elemento:
	if(lista==NULL || lista->prox==NULL || lista->prox->prox==NULL){
		return cont;
	}
	Lista nodo_prec=lista;
	Lista nodo_esaminato=lista->prox;
	Lista nodo_succ=lista->prox->prox;
	
	if((float)(nodo_esaminato->info)/2>(float)(nodo_prec->info) && (float)(nodo_esaminato->info)/2>(float)(nodo_succ->info)){
		return 1+conta_picchi(nodo_esaminato);
	}
	else return conta_picchi(nodo_esaminato);
}
Lista InsInTesta(Lista lista, int elem){
	Lista punt;
	punt=malloc(sizeof(Nodo));
	punt->info=elem;
	punt->prox=lista;
	return punt;
}
Lista crea_lista(){
	Lista lis=NULL;
	lis=InsInTesta(lis, 33);
	lis=InsInTesta(lis, 64);
	lis=InsInTesta(lis, 18);
	lis=InsInTesta(lis, 34);
	lis=InsInTesta(lis, 87);
	lis=InsInTesta(lis, 23);
	lis=InsInTesta(lis, 16);
	lis=InsInTesta(lis, 36);
	lis=InsInTesta(lis, 12);
	lis=InsInTesta(lis, 9);
	lis=InsInTesta(lis, 4);
	return lis;
}
int main (){
	Lista lista1=crea_lista();
	printf("Il numero di picchi in lista e: %d", conta_picchi(lista1));
return 0;
}
