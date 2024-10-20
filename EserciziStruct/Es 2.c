#include <stdio.h>
#define N 10
#define MAX_ETA 20

int main() {
    typedef struct {
        float peso, altezza;
        int eta;
    } Caratteristiche;

    Caratteristiche caratt[N], temp;
    int i, j;

    // Acquisizione dei dati
    for(i = 0; i < N; i++) {
        printf("Acquisizione dati persona %d", i + 1);
        printf("\nPeso: ");
        scanf("%f", &caratt[i].peso);
        printf("\nAltezza: ");
        scanf("%f", &caratt[i].altezza);
        printf("\nEta: ");
        scanf("%d", &caratt[i].eta);
    }

    // Stampo le informazioni relative alle persone di eta inferiore a 20
    printf("Stampo le informazioni relative alle persone di eta inferiore a 20\n");
    for(i = 0; i < N; i++) {
        if(caratt[i].eta <= MAX_ETA) {
            printf("\nPersona in posizione: %d\n", i + 1);
            printf("\nPeso: %.2f", caratt[i].peso);
            printf("\nAltezza: %.2f", caratt[i].altezza);
            printf("\nEta: %d", caratt[i].eta);
        }
    }

    // Versione con vettore ordinato
    for(i = 0; i < N - 1; i++) {
        for(j = 0; j < N - 1 - i; j++) {
            if(caratt[j].eta > caratt[j + 1].eta) {
                temp = caratt[j];
                caratt[j] = caratt[j + 1];
                caratt[j + 1] = temp;
            }
        }
    }

    // Stampo informazioni ordinate per eta crescente
    printf("Stampo informazioni ordinate per eta crescente:\n");
    for(i = 0; i < N; i++) {
        if(caratt[i].eta <= MAX_ETA) {
            printf("\nPersona in posizione: %d\n", i + 1);
            printf("\nPeso: %.2f", caratt[i].peso);
            printf("\nAltezza: %.2f", caratt[i].altezza);
            printf("\nEta: %d", caratt[i].eta);
        }
    }
    return 0;
}
