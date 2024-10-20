/*Scrivere un programma che generi un numero intero casuale e chieda all'utente di indovinarlo. 
Ad ogni tentativo fallito da parte dell'utente di indovinare il numero il programma indica se il numero da indovinare 
e maggiore o minore rispetto a quello appena inserito.
Per generare un numero casuale e necessario chiamare una volta la funzione srand(time(0)) 
per inizializzare il generatore di numeri casuali ed in seguito, per ogni numero casuale, la funzione rand() come di seguito. 
Es. r = rand()
N.B. Si noti che la funzione rand() restituisce un numero casuale tra zero e la costante  RAND_MAX (costante molto grande). 
Si puo usare il solito operatore % per limitare questo range (L'uso della funzione time(..) necessita della libreria time.h. 
Le funzioni srand(..) e rand(..) sono invece parte di stdlib.h).
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUM 100

int main() {
    int tentativo, risultato;
    srand(time(0));
    risultato = rand() % MAX_NUM;
    printf("Indovina il numero (tra 0 e %d): ", MAX_NUM);
    do {
        scanf("%d", &tentativo);
        if (tentativo > risultato) {
            printf("Il numero inserito e maggiore di quello da indovinare. Riprova: ");
        } else if (tentativo < risultato) {
            printf("Il numero inserito e minore di quello da indovinare. Riprova: ");
        }
    } while (tentativo != risultato);

    printf("Complimenti! Il numero da indovinare e proprio: %d\n", tentativo);
    return 0;
}