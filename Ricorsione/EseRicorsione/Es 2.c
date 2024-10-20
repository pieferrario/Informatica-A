/*Calcolo del massimo di un vettore con procedimento ricorsivo.
Si pensi di assegnare il primo elemento dell'array come massimo e confrontarlo con tutti gli altri cambiando il valore del massimo se questo e minore della cella corrente del vettore.
Detta N la lunghezza del vettore "array"  
Se N = 1           (caso base)
max = array[0]
Se N >= 2         (passo induttivo)
il massimo del vettore di N elementi (max) sara uguale al risultato del confronto  
tra array[0] e il massimo degli elementi del sotto-vettore che che va da array[1] a array[N] (lungo N-1). 
*/
#include<stdio.h>
#define N 10
int trova_max(int *v, int n){
	int max;
	if(n==1){
		return v[0];
	}
	if(n>=2){
		max=trova_max(&v[1], n-1);
		if(v[0]>max){
			return v[0];
		}
		else {
		return max;
		}
	}
		
	}
int main (){
	int v[N]={2, 3, 9, 2, 13, 4, 34, 2, 9, 5};
	for (int i=0; i<N; i++){
	printf("%d ", v[i]);
	}
	printf("\n\nIl massimo del vettore inserito e: %d", trova_max(v, N));

return 0;
}
