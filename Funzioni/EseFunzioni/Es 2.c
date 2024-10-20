/*Definire un nuovo tipo di dato chiamato VT vettore di 10 int. Scrivere in C la funzione ft che:
ha in ingresso un vettore A di tipo VT gia caricato e restituisce, attraverso un opportuno parametro, una struct con 2 campi a e b di tipo int 
che contengono rispettivamente la somma degli elementi di A di posto pari e quella degli elementi di A di posto dispari;
restituisce la sommatoria di tutti gli elementi di A.
*/
#include<stdio.h>
#define N 10
typedef int VT[N];
typedef struct {
	int a;
	int b;
} Elementi;
int ft(VT A, Elementi *s);
int main (){
	VT v={2,-4,8,9,12,1,6,-9,5,13};
	Elementi s;
	int i;
	printf("La somma degli elementi del vettore e: %d", ft(v, &s));
	printf("\nLa somma degli elementi in posizione pari e: %d", s.a);
	printf("\nLa somma degli elementi in posizione dispari e: %d", s.b);
return 0;
}
int ft(VT A, Elementi *s){
	int i, somma=0;
	s->a=0, s->b=0;
	for(i=0; i<N; i++){
		if(i%2==0){
			s->a+=A[i];
		}
		else {
			s->b+=A[i];
		}
		somma+=A[i];
	}
	return somma;
}