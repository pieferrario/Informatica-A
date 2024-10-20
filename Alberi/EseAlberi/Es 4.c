/*Un albero binario si dice isobato se tutti i cammini dalla radice alle foglie hanno la stessa lunghezza
Data la seguente definizione di albero
	typedef struct EL    {	int dato;
				struct EL *left;
				struct EL *right;   } Node;
	typedef Node *tree;
	codificare una funzione che riceve in input un albero e restituisce 1 se l’albero è isobato, 0 altrimenti. 
*/
#include<stdio.h>
typedef struct EL{
	int dato;
	struct EL *left, *right;
}Node;
typedef Node * tree;
int depth(tree t);
int verifica_isobato(tree t);
int main (){

return 0;
}
int depth(tree t){
	int D, S;
	//Caso base: albero vuoto
	if(t==NULL){
		return 0;
	}
	//Inizializzo D e S;
	S=depth(t->left);
	D=depth(t->right);
	if(S>D){
		return S+1;
	}
	else{
	return D+1;
	}
}
int verifica_isobato(tree t){
	//Caso base: l'albero è vuoto
	if (t==NULL){
		return 1;
	}
	//Caso base: si ha una foglia
	if(t->left==NULL && t->right==NULL){
		return 1;
	}
	//Sfrutto depth e controllo che a dx e sx si abbia lo stesso risultato
	if(depth(t->left)==depth(t->right)){
		return verifica_isobato(t->left) && verifica_isobato(t->right); //verifico lo stesso fatto sui rami successivi. Uso && perché devono valere entrambi;
	}
	else return 0;
}