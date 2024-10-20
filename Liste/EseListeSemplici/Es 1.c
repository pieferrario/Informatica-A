/*Si consideri una lista dinamica di interi, i cui elementi sono del tipo definito come di seguito riportato:
	typedef struct El { 
	  int dato;
	  struct El *next;
	} ELEMENTO;

Si codifichi in C la funzione somma avente il seguente prototipo:
	int somma(ELEMENTO *Testa, int M)
Tale funzione riceve come parametro la testa della lista e un intero M. Quindi, restituisce la somma dei soli valori della lista che sono multipli di M.
Se la lista e vuota, la funzione restituisce il valore -1.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct EL{
    int info;
    struct EL *prox;
} ElemLista;

typedef ElemLista* ListaDiElem;

int somma(ListaDiElem testa, int M){
    //Caso lista vuota
    if(testa == NULL){
        return -1;
    }
    //Caso base con 1 nodo
    if(testa->prox == NULL){
        //Caso in cui nodo e multiplo di M
        if(testa->info % M == 0){
            return testa->info;
        }
        //Caso in cui nodo non e multiplo di M
        return 0;
    }
    //Caso con testa->prox != null
    else{
        if(testa->info % M == 0){
            return testa->info + somma(testa->prox, M);
        }
        else{
            return somma(testa->prox, M);
        }
    }
}

int ListaVuota(ListaDiElem lista);
ListaDiElem InsInTesta(ListaDiElem lista, int elem);
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista(ListaDiElem lista);

int main() {
    int M;
    ListaDiElem lista=NULL, lista1=NULL, lista2=NULL;     
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");

    //inserire qui il codice
    printf("Inserire l'intero M: ");
    do{
        scanf("%d", &M);
    } while (M < 1);
    printf("La somma degli elementi della lista 1 multipli di %d e: %d", M, somma(lista1, M));
    printf("\nLa somma degli elementi della lista 2 multipli di %d e: %d", M, somma(lista2, M));
    
    VisualizzaLista(lista);
    printf("\n\n");
    
    return 0;
}

void VisualizzaLista(ListaDiElem lista) {
    if (ListaVuota(lista))
        printf(" ---| \n");
    else {
        printf(" %d ---> ", lista->info); 
        VisualizzaLista(lista->prox);
    }
}

ListaDiElem InsInTesta(ListaDiElem lista, int elem) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;		
    return  punt;
}

int ListaVuota(ListaDiElem lista) {
    return lista == NULL;
}

ListaDiElem crea1() {
    ListaDiElem lis = NULL;            
    lis = InsInTesta(lis, 2);
    lis = InsInTesta(lis, 12);
    lis = InsInTesta(lis, 1);
    lis = InsInTesta(lis, 4);
    lis = InsInTesta(lis, 8);
    lis = InsInTesta(lis, 34);
    lis = InsInTesta(lis, 78);
    lis = InsInTesta(lis, 26);
    lis = InsInTesta(lis, 33);
    lis = InsInTesta(lis, 11);
    lis = InsInTesta(lis, 67);
    lis = InsInTesta(lis, 83);
    lis = InsInTesta(lis, 92);
    return lis; 
}

ListaDiElem crea2() {
    ListaDiElem lis = NULL;            
    lis = InsInTesta(lis, 2);
    lis = InsInTesta(lis, 10);
    lis = InsInTesta(lis, 15);
    lis = InsInTesta(lis, 48);
    lis = InsInTesta(lis, 82);
    lis = InsInTesta(lis, 11);
    lis = InsInTesta(lis, 92);
    lis = InsInTesta(lis, 22);
    lis = InsInTesta(lis, 36);
    lis = InsInTesta(lis, 19);
    lis = InsInTesta(lis, 69);
    return lis;
}
