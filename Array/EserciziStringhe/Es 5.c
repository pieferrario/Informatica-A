/*Definiamo il grado minimo g e il grado massimo G di una parola P rispettivamente come il minimo e il massimo numero di occorrenze delle lettere di P in P. 
Ad esempio:
ISTANBUL	?   g=1, G=1  ( tutte le lettere della parola compaiono in essa una e una sola volta )
BOSFORO	?   g=1, G=3  ( B, S, F, R compaiono una sola volta, O compare tre volte )
GALATASARAY ?   g=1, G=5  ( G, L, T, S, R, Y compaiono una sola volta, A compare cinque volte )
MARMARA ?   g=2, G=3  ( M e R compaiono due volte, A compare tre volte )
G e g valgono convenzionalmente 0 per la parola vuota (cioe per una parola priva di caratteri).
Si scriva un programma C che legge una stringa di lunghezza generica che rappresenta P, calcola G e g, e li stampa
*/
#include<stdio.h>
#include<string.h>
#define n 100
int main (){
	int len, i, j, g, G, cont=0;
	char s[n];
	printf("Inserire parola: ");
	scanf("%s", s);
	len=strlen(s);
	g=len;
	G=0;
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			if(s[i]==s[j]){
			cont++;
			}
		}
		if(cont>G){
			G=cont;
		}
		if(cont<g){
			g=cont;
		}
		cont=0;
	}
	printf("Data la parola '%s' si ha che:\ng=%d\nG=%d", s, g, G);
return 0;
}
