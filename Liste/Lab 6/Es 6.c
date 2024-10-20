/*Si consideri il punto nel piano cartesiano, individuato dalle coordinate intere x, y e da una lettera (ad esempio, A(5,2)). 
Si chiede di definire un'opportuna struttura dati ed il relativo tipo punto_t che lo rappresenti. 
Si chiede poi di definire una nuova struttura dati che permetta di rappresentare un poligono come una lista di punti. 
Scrivere quindi un programma, che facendo uso della rappresentazione di poligono introdotta: 
	1) acquisisca i vertici di un poligono, 
	2) calcoli il perimetro del poligono, 
	3) stampi a video il valore del perimetro calcolato.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	int x;
	int y;
} punto_t;
typedef struct elem{
	punto_t info;
	struct elem * prox;
} nodo;
typedef nodo * Lista;
Lista crealista(int n){ //Creo una funzione che riceve in input il numero di vertici
	Lista testa, aux;
	testa=malloc(sizeof(nodo)); //Alloco memoria nell'heap
	aux=testa; //Sfrutto aux per creare la lista
	for(int i=0; i<n; i++){
		printf("Inserire coordinate del vertice: ");
		printf("\nx: ");
		scanf("%d", &aux->info.x);
		printf("\ny: ");
		scanf("%d", &aux->info.y);
		if(i<n-1){ //avanzo fino al penultimo nodo;
			aux->prox = malloc(sizeof(nodo)); //creo un'area di memoria per il nodo seguente;
			aux=aux->prox;
		}
	}
	aux->prox=testa; //L'ultimo nodo deve essere la testa dellla lista;
	return testa; //Restituisco l'indirizzo della testa della lista
}
float calcola_perimetro(Lista polig){
	Lista ausil=polig;
	float perimetro=0, lung_lato;
	int x1, x2, y1, y2;
	do{
		x1=polig->info.x;
		y1=polig->info.y;
		x2=polig->prox->info.x;
		y2=polig->prox->info.y;
		lung_lato=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
		perimetro+=lung_lato;
		ausil=ausil->prox;
	}while (ausil!=polig);	
	return perimetro;
}

int main (){
	int n_vert;
	float ris;
	Lista poligono;
	do{
	printf("Inserire il numero di vertici del poligono: ");
	scanf("%d", &n_vert);
	} while (n_vert<3);
	poligono=crealista(n_vert);
	ris=calcola_perimetro(poligono);
	printf("Il perimetro del poligono inserito vale: %.2f", ris);
	return 0;	
}