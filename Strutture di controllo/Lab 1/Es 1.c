/*Scrivere un programma in linguaggio C che, 
letti due caratteri minuscoli dallo standard input,
stabilisce quale dei due viene prima e quale dopo in ordine alfabetico e stampi l'intera porzione di alfabeto tra i due.
*/
#include<stdio.h>
int main (){
char a, b;
do{
printf("Inserire il primo carattere: ");
scanf("%c", &a);
fflush(stdin);
}
while (a<'a'||a>'z');
do{
printf("Inserire il secondo carattere: ");
scanf("%c", &b);
fflush(stdin);
}
while (b<'a'|| b>'z');
if(a<b){
	printf("%c viene prima di %c. \n", a,b);
	while (a<=b){
		printf("%c ", a);
		a++;
	}
}
else{
	printf("%c viene prima di %c\n", b, a);
	while (b<=a){
		printf("%c ", b);
		b++;
	}
}
return 0;
}

