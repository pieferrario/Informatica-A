/*Una matrice quadrata Mat di dimensioni NxN (con N costante predefinita) e diagonalmente dominante se la somma dei valori assoluti degli elementi su ciascuna riga, escluso l'elemento sulla diagonale principale, e minore del valore assoluto dell'elemento corrispondente sulla diagonale principale. Scrivere un programma che chiede all'utente di inserire i valori di una matrice e stampa <Dominante> se la matrice e diagonalmente dominante, <Non dominante> altrimenti.
Si ricorda che la funzione int abs(int n) restituisce il valore assoluto dell'intero n ricevuto come parametro.
*/
#include<stdio.h>
#include<math.h>
#define n 3
int main ()
{
    int i, j, m[n][n], diag, somma=0, flag=1;
    printf("Inserire gli elementi nella matrice:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    printf("La matrice inserita e:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j) {
                somma+=abs(m[i][j]);
            }
            else diag=abs(m[i][j]);
	        if(diag<somma) {
	            flag=0;
	        }
        }
    }
    if(flag)
    	printf("La matrice e diagonalmente dominante");
    else printf("La matrice non e diagonalmente dominante");
    return 0;
}