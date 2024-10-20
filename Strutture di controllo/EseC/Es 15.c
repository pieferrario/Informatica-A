/*Dato un carattere in ingresso, trasformarlo in un altro carattere, che si trova OFFSET posizioni piu in la nell'alfabeto
L'alfabeto considerato e:
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
L'alfabeto e ciclico: dopo la 'z' c'e la 'A'
Per esempio, con OFFSET = 4
il carattere 'a' diventa 'e'
la lettera 'X' diventa 'b'
la lettera 'x' diventa 'B'
La complessita del programma sta tutta nel fatto che nella codifica ASCII le sequenze 'A'..'Z' e 'a'..'z' (viene prima la sequenza di caratteri maiuscoli)
non sono consecutive, ma c'e di mezzo un altro insieme di caratteri, per cui occorre spezzare il programma in 2 if.
*/
#include<stdio.h>
int main (){
	int offset;
	char a,b;
	printf("Inserire il carattere da trasformare: ");
	scanf("%c", &a);
	fflush(stdin);
	if((a<'a'||a>'z')&&(a<'A'||a>'Z')){
		printf("Il carattere inserito non e valido");
		return 1;
	}
	printf("Inserire OFFSET: ");
	scanf("%d", &offset);
		//Prevengo i casi in cui offset mi faccia fare piu cicli di alfabeto usando la funzione modulo;
		offset=offset%52; 
	if(a>='A'&& a<='Z'){
		b=a+offset;
		if(b>'Z'){
			b='a'+(b-'Z'-1); // il compilatore scatta ad 'a' e aggiunge la differenza tra offset e b-z
		}
	}
	if (a>='a' && a<='z'){
		b=a+offset;
		if(b>'z'){
			b='A'+(b-'z'-1);
		}
	}
	printf("Il carattere %c modificato con OFFSET = %d e: %c", a, offset, b);
return 0;
}

