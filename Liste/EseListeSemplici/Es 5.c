/*Sia data una struttura dati dinamica di tipo lista semplicemente concatenata. Ogni nodo della lista contiene un numero intero come valore.
Si scriva la funzione che, dato un vettore di N numeri interi, restituisce la lista contenente gli N elementi del vettore; 
l'elemento di indice 0 va in testa alla lista, ecc.
Si scriva la funzione che stampa a terminale i valori contenuti nella lista in ordine inverso rispetto a quello della lista stessa (leggendoli dalla lista, non dal vettore).
*/
#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct nodo{
	int valore;
	struct nodo * prox;
} nodo;
typedef nodo * lista;
lista copia_array(int v[], int n){
	lista lis;
	//Caso base: l'array ha 0 elementi, la lista e vuota;
	if(n==0){
		return NULL;
	}
	//Passo induttivo:
	lis=malloc(sizeof(nodo)); // alloco memoria nello heap per un nodo
	lis->valore=v[0]; //associo ad ogni nodo il valore di v[0], opportunamente ritagliato tramite la chiamata ricorsiva (che segue)
	lis->prox=copia_array(&v[1], n-1); //uso &v[1] per salvare l'indirizzo della seconda cella di ogni vettore chiamato;
	return lis;
}
void stampa_inv(lista lis){
	//Caso base: lista vuota
	if(lis==NULL){
		return;
	}
	//Passo induttivo
	stampa_inv(lis->prox);
	printf(" %d ", lis->valore);
}
int main (){
	int v[N]={1,2,3,4,5,6,7,8,9,10};
	stampa_inv(copia_array(v, N));
	
return 0;
}
