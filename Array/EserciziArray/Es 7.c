/*Scrivere  un  programma  C  che  legge  da  tastiera  una  sequenza  di  numeri  reali diversi da zero
La lettura termina quando la somma dei numeri immessi e maggiore di 50, e comunque non si possono immettere piu di 100 numeri.
Dopo avere letto tutti i numeri, se l'utente ha inserito almeno  3  valori,  cercare  se  esiste  
una  coppia  di  numeri  tali  che  il  loro  rapporto  (o  il  suo inverso) sia uguale al primo numero immesso e, se esiste, stamparla.
*/
#include<stdio.h>
#define max_sum 50
#define max_num 100
int main (){
	int cont=0, i, j, flag=0;
	float sum=0, v[max_num], rapp, inv;
	printf("Riempire l'array:\n");
	do{
		do{
		scanf("%f", &v[cont]);
		} while (v[cont]==0);
		sum=sum+v[cont];
		cont++;
	} while (sum<=max_sum && cont<=max_num);
	if(cont<3){
		printf("Non sono stati inseriti abbastanza numeri");
		return 1;
	}
	else{
		for(i=0; i<cont; i++){
			for(j=1; j<cont; j++){
			rapp=v[i]/v[j];
			inv=v[j]/v[i];
				if(rapp==v[0] || inv==v[0]){
					flag=1;
					}
				if(flag) break;
				}
			if(flag) break;
			}			
		}
	if(flag)
	printf("Il rapporto o l'inverso di %f e %f vale %f\n", v[i],v[j],v[0]);
	else printf("Non sono state trovate coppie che soddisfino la richiesta.");
	return 0;
	}