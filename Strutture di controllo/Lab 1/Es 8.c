/*Un numero altamente composto e tale che qualunque numero minore di esso ha meno divisori. 
I primi numeri altamente composti sono 1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080
Scrivere un programma che stampa i primi 20 numeri altamente composti. */
#include<stdio.h>
int main (){
	int n=1, div=1, cont_num=0, cont_div=0, max=0;
	//Il ciclo va avanti finche non avro identificato 20 numeri altamente composti
	printf("Lista dei primi 20 numeri altamente composti: \n");
	while (cont_num<20){
		cont_div=0;
		while(div<=n){
			if(n%div==0){
				cont_div++;
			}
			div++;
		}
		if(cont_div>max){
			max=cont_div;
			cont_num++;
			printf("%d ", n);
		}
		div=1;
		n++;
}
return 0;
}