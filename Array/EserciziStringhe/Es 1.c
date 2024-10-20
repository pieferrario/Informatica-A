/*Scrivere un programma C che legge due stringhe da tastiera, 
le concatena in un'unica stringa e stampa la stringa cosi generata*/
#include<stdio.h>
#define n 100
int main (){
char str1[n], str2[n], str_t[2*n];
int i, j;
printf("Inserire la prima stringa: ");
scanf("%s", str1);
printf("Inserire la seconda stringa: ");
scanf("%s", str2);
for(i=0; str1[i]!='\0';i++){
	str_t[i]=str1[i];
}
for(j=0; str2[j]!='\0';j++){
	str_t[i+j]=str2[j];
}
str_t[i+j]='\0';
printf("La concatenazione di %s e %s genera: %s", str1, str2, str_t);
return 0;
}