#include<stdio.h>
#define N 3

int main (){
    int i, j, m[N][N], cont, max=0;

    // Input dei valori nella matrice
    printf("Inserire i valori nella matrice:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("La matrice inserita e:\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", m[i][j]);  // Stampa ogni elemento della riga
        }
        printf("\n");  // Nuova riga dopo ogni riga della matrice
    }

    // Sequenza orizzontale
    for(i=0; i<N; i++){
        cont = 1;  // Il contatore inizia da 1 perche conta anche il primo elemento
        for(j=1; j<N; j++){
            if(m[i][j] == m[i][j-1]){
                cont++;
            } else {
                cont = 1;
            }
            if(cont > max){
                max = cont;
            }
        }
    }

    // Sequenza verticale
    for(j=0; j<N; j++){
        cont = 1;  // Il contatore inizia da 1 perche conta anche il primo elemento
        for(i=1; i<N; i++){
            if(m[i][j] == m[i-1][j]){
                cont++;
            } else {
                cont = 1;
            }
            if(cont > max){
                max = cont;
            }
        }
    }

    // Sequenza diagonale principale (da sinistra a destra)
    for(i=0; i<N; i++){
        cont = 1;
        for(j=1; j<N-i; j++){
            if(m[i+j][j] == m[i+j-1][j-1]){
                cont++;
            } else {
                cont = 1;
            }
            if(cont > max){
                max = cont;
            }
        }
    }

    // Sequenza diagonale antidiagonale (da destra a sinistra)
    for(i=0; i<N; i++){
        cont = 1;
        for(j=1; j<N-i; j++){
            if(m[j][i+j] == m[j-1][i+j-1]){
                cont++;
            } else {
                cont = 1;
            }
            if(cont > max){
                max = cont;
            }
        }
    }

    // Stampa della sequenza piu lunga trovata
    printf("La sequenza di numeri uguali consecutivi piu lunga e lunga: %d\n", max);

    return 0;
}
