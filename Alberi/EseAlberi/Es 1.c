/*Sia data la seguente struttura per la memorizzazione di alberi binari etichettati con numeri interi: 
	typedef struct nodo { 
		int info; 
		struct nodo *left, *right; 
	} NODO; 
	typedef NODO *tree; 
	Si devono scrivere due funzioni ricorsive 
	int sommaNodi(tree t); 
	int cercaMax(tree t); 
	delle quali, sommaNodi somma i valori delle etichette nell'albero, mentre cercaMax cerca il valore dell'etichetta massima dell'albero.
*/
#include<stdio.h>
typedef struct nodo{
	int info;
	struct nodo *left, *right;
}NODO;
typedef NODO *tree;
int SommaNodi(tree t);
int CercaMax(tree t);
int Max(int a, int b);
int Max_di_3(int a, int b, int c);
int main (){
	//Main da creare
return 0;
}
int SommaNodi(tree t){
	if(t==NULL){
		return 0;
	}
	return t->info+SommaNodi(t->left)+SommaNodi(t->right);
}
int Max(int a, int b){
	if(a>b){
		return a;
	}
	else return b;
}

int Max_di_3(int a, int b, int c){
	return Max(a, Max(b,c));
}

int CercaMax(tree t){
	//Caso base: albero nullo
	if(t==NULL){
		return 0;
	}
	//Caso base foglia
	if(t->left==NULL && t->right==NULL){
		return t->info;
	}
	if(t->left==NULL){
		return Max(CercaMax(t->right), t->info);
	}
	if(t->right==NULL){
		return Max(CercaMax(t->left), t->info);
	}
	return Max_di_3(CercaMax(t->left), CercaMax(t->right), t->info);
}