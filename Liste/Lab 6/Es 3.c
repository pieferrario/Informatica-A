/*Si scriva una funzione che riceve in ingresso una lista di stringhe contenenti tre o piu caratteri
(escluso il terminatore di stringa) e modifica la lista eliminando le parole consecutive per cui le ultime due lettere della prima parola sono uguali
alle prime due della seconda. Per semplicita, si supponga non esistano tre (o piu) parole consecutive con questa proprieta.
Ad esempio, la lista:
casa -> sale -> postino -> rame -> meta -> sasso -> osteria -> salvia -> notare -> renna
diventa
postino -> sasso -> osteria -> salvia*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct EL {
	char info[100];
	struct EL * prox;
} ElemLista;

typedef ElemLista * Lista;

Lista InsInFondoStringa(Lista lista,char elem[] );
void VisualizzaListaStringhe(Lista lista );
Lista costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int confronta_stringhe(char str1[], char str2[]);
Lista lista_pulita(Lista lista);



int main(){
	Lista lis;
	lis=costruisci();
	VisualizzaListaStringhe(lis);

	//TODO: invocazione funzione
	lis=lista_pulita(lis);
    printf("Lista dopo pulizia\n");
	VisualizzaListaStringhe(lis);


	return 0;
}


//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
int confronta_stringhe(char str1[], char str2[]){
	
		if(str1[strlen(str1)-2]==str2[0] && str1[strlen(str1)-1]==str2[1]){
			return 1;	//Se uguali restitiusce vero;			
		}
		//Se le due lettere non sono uguali, restituisce falso.
		return 0;
	}
Lista lista_pulita(Lista lista){
	if(lista==NULL||lista->prox==NULL){
		return lista;
	}
	Lista lista_prec=NULL; //lo sfrutto per memorizzare la testa della lista
	Lista lista_curr=lista; //eseguo il controllo su questo
	while(lista_curr!=NULL && lista_curr->prox!=NULL){
		Lista lista_succ=lista_curr->prox; //Inizializzo il nodo successivo a quello da controllare;
		if(confronta_stringhe(lista_curr->info, lista_succ->info)){ // Se le stringhe sono uguali, scalo di due;
			if(lista_prec==NULL){ //Cioe se mi trovo sul primo nodo
				lista=lista_succ->prox; //Ri-inizializzo la testa al terzo nodo;
				free(lista_curr);
				free(lista_succ);
				lista_curr=lista;
			}
			else{
				lista_prec->prox=lista_succ->prox; //Collego il nodo precedente a quello due posizioni dopo;
				free(lista_curr);
				free(lista_succ);
				lista_curr=lista_prec->prox;
			}
		}
		else{ //se le due stringhe sono diverse, scalo tutto di uno;
			lista_prec=lista_curr;
			lista_curr=lista_succ;
		}
	}
	return lista; //restituisco lista, cioe la testa
}
	
Lista costruisci(){
	Lista lis=NULL;
	lis=InsInFondoStringa(lis,"casa");lis=InsInFondoStringa(lis,"sale");lis=InsInFondoStringa(lis,"postino");
	lis=InsInFondoStringa(lis,"rame");lis=InsInFondoStringa(lis,"meta");lis=InsInFondoStringa(lis,"sasso");
	lis=InsInFondoStringa(lis,"osteria");lis=InsInFondoStringa(lis,"salvia");lis=InsInFondoStringa(lis,"notare");
	lis=InsInFondoStringa(lis,"renna");
	
	return lis;
}


Lista InsInFondoStringa(Lista lista,char elem[]) {
    Lista punt;
    if(lista==NULL) { punt = malloc( sizeof(ElemLista) );
                     punt->prox = NULL; strcpy(punt->info,elem); return  punt;
    }else{lista->prox = InsInFondoStringa(lista->prox,elem); return lista;}
}


void VisualizzaListaStringhe(Lista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %s ---> ", lista->info); 
	VisualizzaListaStringhe( lista->prox );}
}