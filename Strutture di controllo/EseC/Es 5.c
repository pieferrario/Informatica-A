/*Scrivere i primi 30 elementi di una serie cosi definita: 
i primi tre elementi valgono 1,i successivi (i>=4) valgono la somma degli elementi i-1 e i-3 
1 1 1 2 3 4 6 9 13 19 28 41 60 */
#include<stdio.h>
#define n 30
int main (){
int i, elem1=1, elem2=1, elem3=1, elem4;
printf("La sequenza e: \n 1 1 1 ");
for (i=4; i<n; i++){
	elem4=elem1+elem3;
	printf("%d ", elem4);
	elem1=elem2;
	elem2=elem3;
	elem3=elem4;
}
return 0;
}

