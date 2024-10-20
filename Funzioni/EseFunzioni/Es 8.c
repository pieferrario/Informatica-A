/*I risultati della finale olimpica di nuoto della staffetta 4x100 stile libero sono rappresentati mediante una matrice di dimensioni 4x8.
Ogni cella rappresenta il risultato di un singolo frazionista tramite la seguente struttura:
	typedef struct { int min,sec,cent;} tempo;
	typedef struct {char nome[15],cognome[15],nazionalita[15];
			   tempo t; } frazione;
La matrice e dichiarata in questo modo:
	typedef frazione risultato[4][8];
I risultati sono disposti nella matrice secondo la corsia (e.g. corsia 1 nella prima colonna) 
Scrivere una funzione che riceve in ingresso la matrice che contiene il risultato e restituisce il numero della corsia vincente.
	int corsiaVincente(risultato ris); 
Scrivere una funzione che riceve in ingresso la matrice che contiene il risultato e una variabile che contiene il record mondiale di staffetta e che restituisce 1 se il record mondiale e stato battuto, 0 altrimenti.
	int recordBattuto(risultato ris, tempo record); 
*/
#include<stdio.h>
#define N 15
typedef struct{
	int min;
	int sec;
	int cent;
} tempo;
typedef struct{
	char nome[N];
	char cognome[N];
	char nazionalita[N];
	tempo t;
} frazione;
typedef frazione risultato[4][8];
int convertitempo (tempo t){
	int tempo_conv=60*100*t.min+100*t.sec+t.cent;
	return tempo_conv;
}
int calcolatempo(risultato ris, int j){
	int i;
	int tempo_corsia=0;
	for(i=0; i<4; i++){
		tempo_corsia+=convertitempo(ris[i][j].t);
	}
	return tempo_corsia;
}
int corsiavincente (risultato ris){
	int i, best=calcolatempo(ris, 0), time=0, n_corsia=0;
	for(i=0; i<8; i++){
		 time=calcolatempo(ris, i);
		if(time<best){
			n_corsia=i;
		}
	}
	return n_corsia+1;
}
int recordbattuto(risultato ris, tempo record){
	int i, record_conv=convertitempo(record);
	int migliore_gara=corsiavincente(ris)-1;
	if(calcolatempo(ris, migliore_gara)<record_conv){
		return 1;
	}
	else return 0;
}
int main(){
	return 0;
}