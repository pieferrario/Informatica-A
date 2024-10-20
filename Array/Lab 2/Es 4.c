/*Scrivere un programma che costruisce un array A di 50 interi e un B di 5 interi e stampa 1 se esiste in A una sequenza di 5 elementi che sono
esattamente gli elementi di B anche in un ordine differente*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define n 5
int main ()
{
    int a[N], b[n], i,j,k, cont=0, flag[n];
    srand(time(NULL));
    for(i=0; i<N; i++) {
        a[i]=rand()%7;
    }
    for(i=0; i<n; i++) {
        b[i]=rand()%7;
    }
    // Stampa i due vettori
    printf("Array A:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Array B:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    //Utilizzo N-n+1 cosi da poter considerare l'esatto numero di sottosequenze possibili di lunghezza n;
    for (i = 0; i < N - n + 1; i++) {
        cont = 0; // Inizializza cont a 0 all'inizio di ogni sottosequenza
        int flag[n];
        for (j = 0; j < n; j++) {
            flag[j] = 0;
        }
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (flag[k] == 0 && a[i + j] == b[k]) {
                    flag[k] = 1;
                    cont++;
                    break;
                }
            }
        }
        if (cont == n) {
            printf("Sequenza trovata a partire da %d\n", i);
            break;
        }
    }

    if (cont != n) {
        printf("Sequenza non trovata\n");
    }

    return 0;
}