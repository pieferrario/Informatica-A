/*Si scriva un programma che acquisisce una matrice quadrata NxN (con N costante predefinita con l'struzione #define N .) di interi positivi M ed un array 
A di dimensione N. La funzione restituisce 1 se almeno uno degli elementi di A e divisore di tutti gli elementi di una qualsiasi riga di M.
*/
#include<stdio.h>
#define n 3
int main (){
	int m[n][n], a[n], cont=0, flag=0;
	int i, j;
	printf("Inserire i valori nella matrice M:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("Riempire l'array A:\n");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Matrice:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
         	printf("%4d",m[i][j]);
      }
      printf("\n");
   }
	printf("Array:\n");
   for(i=0;i<n;i++){
      printf("%d ",a[i]);
   }
	for(i=0; i<n; i++){
		cont=0;
		for(j=0; j<n; j++){
			if(m[i][j]%a[i]==0){
				cont++;
				if(cont==n){
					printf("La riga %d contiene tutti multipli di %d", i+1, a[i]);
					return 1;
				}
			}
		}
	}
return 0;
}
