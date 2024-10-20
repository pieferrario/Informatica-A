/*La funzione di libreria strlen() potrebbe essere (teoricamente) codificata in modo ricorsivo, come segue.
	int strlenRic ( const char * s ) {
	  if ( *s == '\0' ) return 0;
	  else return 1 + strlenRic( s+1 );
	}
	.anche se cio non accade mai in pratica, per ovvi motivi di efficienza.
Si chiede tuttavia di proporre una codifica ricorsiva anche per le funzioni indicate in seguito. 
Si badi a considerare bene i casi base e a progettare bene i "passi induttivi". Si tenga eventualmente presente che il codice ASCII del carattere '\0' 
(terminatore di stringa) e il numero zero.
 // Ha lo stesso stesso effetto di strcpy() in string.h : s1  riceve tutti i  caratteri 
	// contenuti in s2 (incluso il '\0')
	void strcpyRic( char *s1, char *s2 );
// Come strcmp() in string.h : restituisce 0 se le stringhe sono uguali, n<0 (n>0) se 
	// s1 precede (segue) alfabeticamente s2
	int strcmpRic( char *s1, char *s2 );


*/
#include<stdio.h>
#define N 100
int strlenRic (const char * s ) {
	  if ( *s == '\0' ) return 0;
	  else return 1 + strlenRic( s+1 );
	}
void strcpyRic(char *s1, char *s2 ){
	//Copio gli elementi puntati da *s2 in *s1;
	*s1=*s2;
	//Caso base: l'elemento appena copiato e il terminatore, dunque esco dalla funzione. Negli altri casi richiamo la funzione finche *s2 != '\0'.
	if(*s2!='\0'){
		strcpyRic(s1+1, s2+1);
	}
}
int strcmpRic(char *s1, char *s2 ){
	//Il caso base: le due parole sono identiche -> l'ultimo carattere e per entrambe il terminatore;
	if(*s1=='\0' && *s2=='\0'){
		return 0;
	}
	else{
		//Caso in cui s1 precede s2;
		if(*s1<*s2){
			return -1;
		}
		//Caso in cui s1 segue s2;
		else {
			if(*s1>*s2){
				return 1;
			}
			//Caso in cui s1=s2 allora continuo ricerca
			else{
				return strcmpRic(s1+1, s2+1);
			}
		}
	}
	
}
int main (){
return 0;
 //E richiesta la sola codifica delle funzioni;
}
