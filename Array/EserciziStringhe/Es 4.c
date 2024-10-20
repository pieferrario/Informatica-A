/*Si codifichi un programma C che legge due stringhe che rappresentano due parole e stampa un valore intero, da interpretarsi come valore di verita, 
che indica se le parole sono anagrammi, cioe se e possibile ottenere l'una dall'altra tramite permutazione delle loro lettere.
Ad esempio le parole POLENTA e PENTOLA sono anagrammi. Si presti attenzione al fatto che parole come TAPPO e PATTO non sono anagrammi, 
anche se ogni lettera dell'una e contenuta nell'altra.*/
#include<stdio.h>
#include<string.h>
#define n 100
int main (){
	char str1[n], str2[n];
	int lung, i, j, cont1=0, cont2=0, flag=1;
	printf("Inserire la prima parola: ");
	scanf("%s", str1);
	printf("Inserire la seconda parola: ");
	scanf("%s", str2);
	if(strlen(str1)==strlen(str2)){
		lung=strlen(str1);
		for(i=0; i<lung; i++){
			cont1=0;
			cont2=0;
			for(j=0; j<lung; j++){
				if(str1[i]==str1[j]){
					cont1++;
				}
			}
			for(j=0; j<lung;j++){
				if(str1[i]==str2[j]){
					cont2++;
				}
			}
			if(cont1!=cont2){
				flag=0;
				break;
			}
		}
	}
	else 
		flag=0;
	if(flag) 
		printf("%d: le parole sono anagrammi", flag);
	else
		printf("%d: le parole non sono anagrammi", flag);
return 0;
}