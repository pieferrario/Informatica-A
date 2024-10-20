/*Si scriva un programma che legge una sequenza di interi positivi (la sequenza termina quando viene inserito il valore -1),
conta il numero complessivo dei numeri che sono multipli di 3, di 5 oppure di 7 compresi nella sequenza e stampa questo valore.
Per esempio, nel caso la sequenza in ingresso fosse "4 8 12 15 14 8", il programma dovrebbe stampare il valore 3. 
*/
#include<stdio.h>
int main (){
	int n, count=0;
	printf("Inserire la sequenza: ");
	do{
		scanf("%d", &n);
		if(n%3==0 || n%5==0 || n%7==0){
			count++;
		}	
	}
	while(n!=-1);
	printf("I multipli di 3, 5, 7 della sequenza sono: %d", count); 
return 0;
}

