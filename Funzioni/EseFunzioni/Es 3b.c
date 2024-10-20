#include<stdio.h>
#define N 5

typedef struct {
    int w[N];
    int cont;
} Array_con_cont;

Array_con_cont f(int A[N]) {
    Array_con_cont a;
    int i;
    a.cont = 0;
    for (i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            a.w[a.cont] = A[i];
            a.cont++;
        }
    }
    return a;
}

int main() {
    int i;
    int v[N] = {1, 2, 4, 5, 6};
    Array_con_cont risultato = f(v);
    printf("I numeri copiati sono: %d\n", risultato.cont);
    printf("I vettori sono:\n");
    printf("v: ");
    for (i = 0; i < N; i++) {
        printf("%3d", v[i]);
    }
    printf("\nw: ");
    for (i = 0; i < N; i++) {
        printf("%3d", risultato.w[i]);
    }
    printf("\n");
    return 0;
}