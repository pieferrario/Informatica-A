/*Si scriva un frammento di codice legga da input le coord x e y di una struct punto cosi definita:
typedef struct { float x; float y; } Punto; 
si sviluppino ed invochino in un main le seguenti funzioni
.	void stampaPunto(Punto p) che effettui la stessa STAMPA di un punto passato come parametro
.	Punto acquisisciPunto() che crea un punto dopo aver chiesto le coordinate all'utente. 
.	float calcolaNorma(Punto p) che restituisce la distanza del punto dall'origine
.	float calcolaDistanza(Punto p1, Punto p2) che calcola la distanza tra il punto p1 e p2

Si scriva infine una funzione "lunghezza" che riceve un vettore di punti e restituisce la lunghezza della linea spezzata composta dai punti nel vettore 
(nell'ordine in cui sono nel vettore). La funzione avra prototipo:
float lunghezza(Punto linea[])*/
#include<stdio.h>
#include<math.h>
#define N 5
typedef struct {
	float x;
	float y;
} Punto;
void stampa_punto(Punto p){
	printf(" (%.2f, %.2f) ", p.x,p.y);
}
Punto acquisisci_punto(){
	Punto p;
	printf("x: ");
	scanf("%f", &p.x);
	printf("y: ");
	scanf("%f", &p.y);
	return p;
}
float calcola_norma(Punto p){
	float norma=sqrt(p.x*p.x+p.y*p.y);
	return norma;	
}
float calcola_distanza (Punto p, Punto q){
	float distanza=sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
	return distanza;
}
float calcola_lunghezza(Punto linea[N]){
	int i;
	float lunghezza=0;
	for(i=0; i<N-1; i++){
		lunghezza+=calcola_distanza(linea[i], linea[i+1]);
	}
	return lunghezza;	
}
int main (){
	Punto p, q, linea[N];
	printf("Inserire coordinate del punto:\n");
	p=acquisisci_punto();
	printf("Il punto inserito e: ");
	stampa_punto(p);
	printf("\nLa norma di p vale: %.2f\n",calcola_norma(p));
	printf("Inserire coordinate del punto:\n");
	q=acquisisci_punto();
	printf("Il punto inserito e: ");
	stampa_punto(q);
	printf("\nLa norma di q vale: %.2f\n", calcola_norma(q));
	printf("\nLa distanza tra p e q vale: %.2f", calcola_distanza(p,q));
	printf("\nRiempire l'array\n");
	for(int i=0; i<N; i++){
		linea[i]=acquisisci_punto();
	}
	printf("Il vettore inserito e: ");
	for(int i=0; i<N; i++){
		stampa_punto(linea[i]);		
	}
	printf("\nLa lunghezza della linea spezzata e: %.2f", calcola_lunghezza(linea));
return 0;
}
