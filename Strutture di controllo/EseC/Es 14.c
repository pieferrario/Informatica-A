/*Si scriva un programma in linguaggio C che risolva il problema seguente. Leggere una sequenza di caratteri alfanumerici dallo standard input
terminata dal carattere '#'; quindi stampare sullo standard output la media dei numeri interi corrispondenti ai caratteri numerici inseriti. 
Esempio: 
	input: 'A' 'b' 'C' '1' 'F' '4' 'G' 'T' '6' 'Y' '6' '3' 's'
	output:  media = 4
*/
#include<stdio.h>
int main (){
	char a;
	int somma=0, cont=0, num;
	float media;
	printf("Inserire una sequenza alfanumerica: \n");
	do{
		scanf("%c", &a);
		fflush(stdin);
		//Se il carattere e numerico, lo conto e lo sommo ai precedenti
		if(a>='0'&&a<='9'){
			num=a-48;
			somma=somma+num;
			cont++;
		}
	}
	while(a!='#');
	if(cont>0){
	media=(float)somma/cont;
	printf("La media dei caratteri numerici e %.2f", media);
	}
	else{ 
	printf("Non sono stati inseriti caratteri alfanumerici");
	}
}

