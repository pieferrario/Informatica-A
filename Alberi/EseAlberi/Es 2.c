/*Si consideri la seguente definizione di un albero binario (binario=con due rami in ogni nodo):
	typedef struct EL { int dato; 
                                        struct EL * left, * right; } node;
	typedef node * tree;
	in cui dato assume sempre valori positivi.
Supponiamo che percorrendo un cammino dalla radice alle foglie si totalizzi un punteggio pari alla somma dei valori contenuti nei nodi percorsi.
Scrivere una funzione maxPunti che calcola il punteggio massimo che possiamo totalizzare percorrendo un cammino dalla radice alle foglie.
Vogliamo percorrere l’albero dalla radice ad una foglia totalizzando esattamente un certo punteggio:
né far meno, né sforare. Scrivere una funzione esisteCammino che dati un albero ed un intero k, dice se esiste un cammino dalla radice ad una foglia
che permette di totalizzare esattamente k punti.
*/
#include<stdio.h>
typedef struct EL{
	int dato;
	struct EL * left, * right;
} node;
typedef node * tree;
int max_punti(tree t);
int esiste_cammino(tree t, int k);
int main (){
	//Main non richiesto;
return 0;
}
int max_punti(tree t){
	if(t==NULL){
		return 0;
	}
	int S=max_punti(t->left);
	int D=max_punti(t->right);
	if(S>D){
		return S+t->dato;
	}
	else return D+t->dato;
}

int esiste_cammino(tree t, int k){
	//Caso base albero vuoto e k=0;
	if(t==NULL && k==0){
		return 1;
	}
	//Caso base negativo;
	if(t==NULL){
		return 0;
	}
	//Caso base con k<del dato;
	if(k-t->dato<0){
		return 0;
	}
	//Caso con left==NULL
	if(t->left==NULL){
		return esiste_cammino(t->right, k-t->dato);
	}
	//Caso right==NULL
	if(t->right==NULL){
		return esiste_cammino(t->left, k-t->dato);
	}
	//Passo induttivo
	return (esiste_cammino(t->left, k-t->dato) || esiste_cammino(t->right, k-t->dato));
}
