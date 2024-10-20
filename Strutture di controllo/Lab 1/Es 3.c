/*Scrivere un programma che stampi la tavola pitagorica 10x10.*/
#include<stdio.h>
#define len 10
int main (){
	int i, j, prod;
	printf("Tavola pitagorica 10x10\n\n");
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			prod=(i+1)*(j+1);
			printf("%d ", prod);
		}
		printf("\n");
	}
return 0;
}

