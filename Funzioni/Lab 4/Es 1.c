/*Un numero e perfetto se corrisponde alla somma dei suoi divisori, escluso se stesso (ad esempio 6 e perfetto 1+2+3 = 6)
Un numero e abbondante se e > della somma dei suoi divisori (es 15 e abbondante 1 + 3 +5 < 15), altrimenti difettivo (es 12 e difettivo, 1+2+3+4+6 > 12)
Scrivere un programma che chiede all'utente di inserire un numero positivo n (nel caso in cui il numero non e positivo ripetere inserimento) e verifica se n e perfetto,
stampando un messaggio all'utente.
Se n non e perfetto stampa un messaggio per dire se n e abbondante o difettivo.
Consiglio per la soluzione, si sviluppino le seguenti funzioni:
int sommaDivisori(int num);
int controllaSePerfetto(int num);
*/
#include<stdio.h>
int sommadivisori(int num){
	int i, somma=0;
	for(i=1; i<=num/2; i++){
		if(num%i==0){
			somma+=i;
		}
	}
	return somma;
}
int controlla_perfetto(int num){
	int i, flag=0;
	int sommadiv=sommadivisori(num);
	if(sommadiv==num){
		flag=0;
	}
	else{
		if(sommadiv<num){
			flag=1;
		}
		else{
			flag=2;
		}
	}
	return flag;
}
int main (){
	int n;
	do {
        printf("Inserire un numero positivo: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Numero non valido. ");
        }
    } while (n <= 0);
	switch(controlla_perfetto(n)){
		case 0:{
			printf("Il numero %d e perfetto", n);
			break;
		}
		case 1:{
			printf("Il numero %d e abbondante", n);
			break;
		}
		case 2:{
			printf("Il numero %d e difettivo", n);
			break;
		}
	}
return 0;
}
