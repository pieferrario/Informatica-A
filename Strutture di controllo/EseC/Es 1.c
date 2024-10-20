/*Scrivere un programma in linguaggio C che, letti tre numeri interi a, b, c dallo standard input, 
stampi a terminale la sequenza dei tre numeri in ordine crescente.
Esempio: a = 10, b = 7, c = 9 deve dare in uscita 7 9 10.
*/
#include<stdio.h>
#define n 3
int main (){
	int a, b, c, temp=0;
	printf("Inserire numero 1 ");
	scanf("%d", &a);
	printf("Inserire numero 2 ");
	scanf("%d", &b);
	printf("Inserire numero 3 ");
	scanf("%d", &c);
	printf("La sequenza inserita e: %d %d %d\n", a,b,c);
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c){
		temp=a;
		a=c;
		c=temp;
	}
	if (b>c){
		temp=b;
		b=c;
		c=temp;
	}
	printf(" La sequenza ordinata e: %d %d %d", a,b, c);
return 0;
}

