/*Esercizio tde 16/11/2007:
Le matrici quadrate N x N possono essere navigate in diversi modi. Due modi tradizionali sono il nested loop e il merge scan. 
Il nested loop è la navigazione riga per riga (o colonna per colonna), come esemplificato sotto (nella matrice i numeri rappresentano l’ordine di navigazione).

1  2  3  4  5  6  7  8  
9 10 11 12 13 14 15 16  
17 18 19 20 21 22 23 24  
25 26 27 28 29 30 31 32  
33 34 35 36 37 38 39 40  
41 42 43 44 45 46 47 48  
49 50 51 52 53 54 55 56  
57 58 59 60 61 62 63 64

a) Si scriva una funzione che riceve in input due matrici quadrate A e B e un intero k. A e B sono matrici N x N e k è compreso tra 1 e NxN (non serve verificare,
k è garantito essere compreso tra 1 e NxN). La funzione deve attraversare, secondo l'ordine del nested loop per righe, le prime k posizioni sia di A che di B e restituire
il numero di interi uguali che si trovano nella stessa posizione in A e in B. (2 punti).
int quantiUgualiConNestedLoop(int A[][N], int B[][N], int k)

Il metodo merge scan invece è quello che si muove lungo le diagonali partendo dal punto più in alto a sinistra, come esemplificato sotto (nella matrice i numeri rappresentano l'ordine di esplorazione).

1   2   4   7  11  16  22  29  
3   5   8  12  17  23  30  37  
6   9  13  18  24  31  38  44  
10 14  19  25  32  39  45  50  
15 20  26  33  40  46  51  55  
21 27  34  41  47  52  56  59  
28 35  42  48  53  57  60  62  
36 43  49  54  58  61  63  64

b) Si scriva una funzione che riceve in input due matrici quadrate A e B e un intero k. A e B sono matrici N x N e k è compreso tra 1 e NxN (non serve verificare, 
k è garantito essere compreso tra 1 e NxN). 
La funzione deve attraversare, secondo l'ordine del merge scan, le prime k posizioni sia di A che di B e restituire il numero di interi uguali che si trovano nella stessa
posizione in A e in B. (2 punti).
int quantiUgualiConMergeScan(int A[][N], int B[][N], int k)
*/
#include<stdio.h>
#define N 3
int NestedLoop(int A[N][N], int B[N][N], int k){
	int i, j;
	int cont=0, cont_k=0;
	for(i=0; i<N && cont_k<k; i++){
		for(j=0; j<N && cont_k<k; j++){
			if(A[i][j]==B[i][j]){
				cont++;
				}
				cont_k++;
			}
		}
	return cont;
}
int MergeScan(int A[N][N], int B[N][N], int k){
	int i, j, q, r;
	int cont=0, cont_k=0;
	//Sviluppo navigazione su diagonale q
	for(q=0; q<N && cont_k<k;q++){
		i=0; 
		//j=q mi permette di muovermi sulle colonne per iniziare dall'elemento in riga 0 della diag q;
		j=q;
		//Gestisco spostamenti su ogni diagonale tramite r: aumento contatore, aumento riga e torno indietro di una colonna;
		for(r=0; r<q+1 && cont_k<k; r++){
			if(A[i][j]==B[i][j]){
				cont++;
			}
				cont_k++;
				i++;
				j--;
		}
	}
	for(q=1; q<N && cont_k<k-1; q++){
		//Inizializzo il primo elemento della seconda meta di matrice
		i=q;
		j=N-1;
		//Gestisco spostamento in diagonale: aumento riga, riduco colonna;
		for(r=N-1; r>=1 && cont_k<k-1; r--){
			if(A[i][j]==B[i][j]){
				cont++;
			}
			cont_k++;
		}
		i++;
		j--;
	}
	return cont;	
}
int main (){
	int m[N][N], n[N][N];
	int k;
	int i, j;
	printf("Riempire la matrice m:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("Riempire la matrice n:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &n[i][j]);
		}
	}
	do{
	printf("Inserire l'intero k: ");
	scanf("%d", &k);
	} while (k<1||k>N*N);
	printf("Stampo la matrice m:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	printf("\nStampo la matrice n:\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", n[i][j]);
		}
		printf("\n");
	}
	printf("\nIl valore di k e: %d\n", k);
	printf("\nTramite Nested Loop sono stati trovati %d interi in posizione uguale nelle due matrici", NestedLoop(m, n, k));
	printf("\nTramite Merge Scan sono stati trovati %d interi in posizione uguale nelle due matrici", MergeScan(m,n,k));
return 0;
}
