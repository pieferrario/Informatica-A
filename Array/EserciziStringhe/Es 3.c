/*Scrivere un programma che chieda di inserire una sequenza di caratteri, fino allo spazio, riconosca se i caratteri
inseriti sono cifre pari o dispari o se sono altro, visualizzi le tre sequenze divise per tipo. 
Memorizzo le pari in un array, le dispari in un secondo array e tutto il resto in un terzo, controllando le dimensioni
*/
#include<stdio.h>
#include<string.h>
#define len 10
int main (){
	char a, pari[len], dispari[len], altri[len];
	int i=0, j=0, k=0, l=0, l_p, l_d, l_a;
	printf("Inserire una sequenza di caratteri:\n");
	do{
		scanf("%c", &a);
		fflush(stdin);
		if(a>=48 && a<=57){
			if(a%2==0){
				pari[j]=a;
				j++;
			}
			else{
				dispari[k]=a;
				k++;		
			}
		}
		else{
			altri[l]=a;
			l++;
		}
	} while (a!=' ' && strlen(pari)<len && strlen(dispari)<len && strlen(altri)<len);
	pari[j] = '\0';
    dispari[k] = '\0';
    altri[l] = '\0';
	printf("\nLa stringa pari e: %s\nLa stringa dispari e: %s\nLa stringa rimanente e: %s", pari,dispari, altri);
return 0;
}
