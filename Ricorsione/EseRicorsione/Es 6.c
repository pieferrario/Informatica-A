/*Le funzioni pila(n) e torre(n) sono definite (per n>0) come segue:
pila(n) = n^(n-1)^(n-2)^... fino a n=1. Esempi: pila(1)=1, pila(2)=2, pila(3)=3^2=9; pila(4)=4^9=262144
torre(n) = n^n^n^... n compare n volte: torre(1)=1, torre(2)=2^2=4, torre(3)=3^(3^3)=7.625597484987; torre(4)=4^(4^(4^4))=1.34078079299425970995892843137e+154
N.B.: l'associativita e dall'alto al basso: pila(4) = 4^(3^2) = 4^9, torre(3) = 3^(3^3) = 3^27 [e non (4^3)^2 e (3^3)^3]
Si diano opportune definizioni ricorsive di pila(n) e torre(n), indicando chiaramente e i casi base i passi induttivi. 
Se si ricorre a funzioni ausiliarie, si indichi chiaramente di quali funzioni si tratta.
Si codifichino in C le due funzioni. Si apprezza e si consiglia l'introduzione di funzioni di supporto
*/
#include<stdio.h>
int calcola_potenza(int base, int exp){
	//Caso base n=1
	if(exp>0){
		return base*calcola_potenza(base, exp-1);
	}
	return 1;
}
int pila (int n){
	//Caso base: pila(1)=1
	if(n==1){
		return 1;
	}
	//Caso induttivo: pila(n)=n^n-1...
	return calcola_potenza(n, pila(n-1));
}
//Creo la funzione torre_eff per l'algoritmo ricorsivo.
int torre_eff(int n, int x){
	//Caso base: torre(1)=1
	if(x==1){
		return n;
	}
	return calcola_potenza(n, torre_eff(n,x-1));	
}
//La funzione torre(n) e quella che riceve in input n.
int torre(int n){
	return torre_eff(n,n);
}
int main (){
	printf("\nPila(1)=%d\nTorre(1)=%d", pila(1), torre(1));
	printf("\nPila(2)=%d\nTorre(2)=%d", pila(2), torre(2));
	printf("\nPila(3)=%d\nTorre(3)=%d", pila(3), torre(3));	
return 0;
}
