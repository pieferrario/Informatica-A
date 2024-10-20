/*Si codifichi un programma C che legge dallo standard input una sequenza (di lunghezza arbitraria) di interi positivi terminata dal valore 0 e, 
al termine della sequenza, visualizza su standard output un messaggio che indica quante coppie di numeri consecutivi che siano diversi, 
pari e il cui prodotto sia un quadrato perfetto sono contenute nella sequenza. Ecco un esempio:
	2  50  13  16  8  7  8  2  18  6  6  16  4  1  25 0
	Le coppie di numeri cercati sono 4 (2 50, 8 2, 2 18, 16 4)
Si noti che un numero puo anche appartenere a due coppie. Nella soluzione si utilizzi la funzione:
	int dppqp(int a,  int b); Restituisce 1 se i parametri sono diversi, pari, e il 
				loro prodotto e un quadrato perfetto, 0 altrimenti
La funzione dichiarata qui sopra puo essere ad esempio definita come segue:
int dppqp (int a, int b) {
  int x = 2, p = a*b;
  if ( a%2 || b%2 || a==b ) // Se uno dei parametri e dispari o sono uguali: -> 0
    return 0;
  while ( x*x < p )       // Prova i quadrati di tutti i numeri pari iniziando
    x += 2;              // da 2 e fino a raggiungere o superare a*b
  return x*x == p;      // Se l'ultimo quadrato supera p: -> 0, altrimenti: -> 1
}
*/
#include<stdio.h>
int verifica(int a, int b){
	int x=2, p=a*b, flag=1;
	if(a==b || a%2==1 || b%2==1){
		return 0;
	}
	else{
		while(x*x<p){
			x+=2;
		}
		if(x*x>p){
			flag = 0;
		}
	return flag;
	}
	}
int main (){
	int a, b=1, cont=0;
	printf("Inserire una sequenza (usare 0 come terminatore)\n");
	do{
		a=b;
		scanf("%d", &b);
		if(verifica(a, b)){
			cont++;
		}
	} while (b!=0);
	printf("Le coppie che rispettano i criteri richiesti sono: %d", cont);
return 0;
}
