/*Si scriva un programma in linguaggio C che riceve dallo standard input due caratteri alfabetici, 
li converte in maiuscolo e stampa a video ordinatamente tutti i caratteri dell'alfabeto fra essi  compresi, 
estremi inclusi.
Esempio: dati 'g' e 'M' stampa a video la sequenza: GHIJKLM.
*/
#include<stdio.h>
int main (){
	char a, b, temp;
	printf("Inserire primo carattere: ");
	scanf("%c", &a);
	fflush(stdin);
	//Se a e minuscolo, lo rendo maiuscolo
	if (a>='a'&& a<='z'){
		a=a-32;
	}
	printf("Inserire secondo carattere: ");
	scanf("%c", &b);
	//Se b e minuscolo lo rendo maiuscolo;
	if(b>='a'&&b<='z'){
		b=b-32;
	}
	//Se a e dopo b, li riordino
	if(a>b){
		temp=a;
		a=b;
		b=temp;	
	}
	//Stampo la porzione compresa
	printf("La porzione di alfabeto compresa tra i due caratteri e: ");
	while (a<=b){
		printf("%c ", a);
		a++;
		}
	return 0;
}

