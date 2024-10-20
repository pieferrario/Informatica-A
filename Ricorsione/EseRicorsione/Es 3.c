/*Si progetti la funzione ricorsiva che svolge il compito seguente. Siano dati due vettori V1 e V2, di dimensione N1 e N2, rispettivamente (con 1<=N2<=N1).
La funzione restituisce il valore 1 in uscita se tutti gli elementi del vettore V2 si trovano nel vettore V1 nell'ordine inverso rispetto a quello in cui essi figurano in V2,
ma non necessariamente in posizioni immediatamente consecutive; altrimenti (ovvero se questo non si verifica), la funzione restituisce valore 0.
*/
#include<stdio.h>
#define N1 10
#define N2 5
int controlla_vett(int v[N1], int w[N2], int iniz, int fine){
	//Caso base positivo: v2 e vuoto e v1 no;
	if(fine<0){
		return 1;
	}
	//Caso base negativo: v1 e vuoto e v2 no;
	if(iniz>N1-1){
		return 0;
	}
	//Passo induttivo
	if(v[iniz]==w[fine]){
		return controlla_vett(v,w, iniz+1, fine-1);
	}
	else{
		return controlla_vett(v, w, iniz+1, fine);
	}
}
int main (){
	int v1[N1]={1, 5, 6, 4, 3, 2, 9, 8, 7, 10};
	int v2[N2]={10, 8, 2, 3, 1};
	int i;
	for(i=0; i<N1; i++){
	printf("%d ", v1[i]);
	}
	printf("\n");
	for(i=0; i<N2; i++){
		printf("%d ", v2[i]);
	}
	printf("\n");
	switch(controlla_vett(v1, v2, 0, N2-1)){
		case 0: printf("Gli elementi del vettore v2 non sono contenuti in v1 nell'ordine inverso"); break;
		case 1: printf("Gli elementi del vettore v2 sono contenuti in v1 nell'ordine inverso"); break;
	}
return 0;
}
