/*Si consideri la seguente definizione di un albero binario (binario=con due rami in ogni nodo):
	typedef struct EL { int dato; 
                                        struct EL * left, * right; } node;
	typedef node * tree;
Scrivere una funzione che riceve il puntatore alla radice di un albero e lo scandisce interamente costruendo una lista tale che ogni nodo della lista punti ad una diversa foglia dell’albero.
La funzione deve restituire al chiamante il puntatore alla lista creata.
	typedef struct ELLista { tree foglia; 
                                                struct ELLista * next; } nodeLista;
	typedef nodeLista * Lista;
Si noti che esistono diversi modi di visitare l’albero che originano diverse liste come risultato.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct EL {
	int dato;
	struct EL * left, * right;
} Node;
typedef Node * tree;
typedef struct ELLista{
	tree foglia;
	struct ELLista * next;
} NodeLista;
typedef NodeLista * Lista;
Lista InsInFondo( Lista lista, tree elem ) {
    Lista punt;
	if( lista==NULL ) {
	    punt = malloc( sizeof(NodeLista) );
		punt->next = NULL;
		punt->foglia = elem;
		return punt;
	} else {
	    lista->next = InsInFondo( lista->next, elem );
		return lista; 
	}
}
Lista punta_foglie(tree t);
Lista punta_fogle_aux(tree t, Lista lis);
int main (){
	//Main non richiesto
return 0;
}
Lista punta_foglie_aux (tree t, Lista lis){
	if(t==NULL){
		return NULL;
	}
	lis=InsInFondo(lis, t);
	
	if(t->left==NULL && t->right==NULL){
		return lis;
	}
	if(t->left==NULL){
		return punta_foglie_aux (t->right, lis);
	}
	if(t->right==NULL){
		return punta_foglie_aux(t->left, lis);
	}
	lis=punta_foglie_aux(t->left, lis);
	lis=punta_foglie_aux(t->right, lis);
	return lis;
}
Lista punta_foglie (tree t){ //Per rispettare la consegna punta_foglie riceve solo un albero.
	return punta_foglie_aux(t, NULL);
}
