/*Scrivere un programma che dato un numero N>0 di valori da inserire da tastiera, stampi a video il massimo
della sequenza inserita e la posizione in cui tale valore e stato inserito. 
Supponiamo, per semplicita, che non ci siano duplicati
Esempio: N=5 sequenza: 3, 2, 9, 5, 1 
	Max=9 Pos=3
*/
#include<stdio.h>
int main (){
	int n=0, i, max, pos;
	printf("Inserire la dimensione del vettore: ");
	do{
	scanf("%d", &n);}
	while (n<=0);
	int v[n];
	for (i=0; i<n; i++){
		printf("Inserire elemento n.%d ", i+1);
		scanf("%d", &v[i]);
	}
	/*for (i=0; i<n; i++){
		printf("%d ", &v[i]);
	}*/
	max=v[0];
	pos=0;
	for (i=1; i<n; i++){
		if(v[i]>max){
			max=v[i];
			pos=i;
		}
	}
	printf("\n\nIl valore massimo della sequenza e %d e si trova in posizione %d", max, pos+1);
return 0;
}

