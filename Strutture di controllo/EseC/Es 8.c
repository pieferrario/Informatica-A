/*Si scriva un programma che legge una sequenza di caratteri (la sequenza termina quando viene inserito il carattere "#"),
conta il numero complessivo di vocali minuscole ("a", "e", "i", "o", "u") comprese nella sequenza e stampa questo valore. 
Per esempio, nel caso la sequenza in ingresso fosse 
			defghi123jklmaAAa002# 
	il programma dovrebbe stampare il valore 4.  
*/
#include<stdio.h>
int main (){
	char c;
	int count=0;
	printf("Inserire la sequenza: ");
	do{
		scanf("%c", &c);
		fflush(stdin);
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			count++;
		}
	} 
	while (c!='#');
	printf("Il numero di vocali minuscole della sequenza e: %d", count);
	return 0;
}
