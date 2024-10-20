/*Si scriva un programma che legge una sequenza di caratteri (la sequenza termina quando viene inserito il carattere "#"),
conta il numero complessivo di lettere minuscole comprese nella sequenza e stampa questo valore. 
Per esempio, nel caso la sequenza in ingresso fosse 
			defghi123jklmaAAa002# 
	il programma dovrebbe stampare il valore 12.  
*/
#include<stdio.h>
int main (){
	char c;
	int cont=0;
	printf("Inserire la sequenza: ");
	do {
	scanf("%c", &c);
	if (c>='a'&& c<='z')
	cont++;
	}
	while (c!='#');
	printf("%d", cont);
return 0;
}

