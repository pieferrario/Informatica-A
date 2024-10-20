/*Si consideri una lista di conti correnti bancari così definita
typedef struct c {​​​​​​​​ char c;
struct c * next; }​​​​​​​​ Cifra;
typedef Cifra * NumTelefono;

xtypedef struct con {​​​​​​​​ char nome[1000];
char IBAN[1000];
NumTelefono numero;
struct con * next; }​​​​​​​​ Correntista;

typedef Correntista * ListaConti;

Si noti che ogni nodo contiene un nome e un numero costruito come una lista di caratteri (esempio di IBAN IT02L1234512345123456789012).

Con l’avvento dell’unione bancaria europea arrivano correntisti dall’estero e urge uniformare la gestione dei contatti telefonici
- Se il numero inizia con il carattere '+' resta inalterato
- Se inizia con due zeri, li sostituisce con un '+'
- Se inizia con un solo zero o con una cifra diversa da zero ('1','2', ... '9') vi aggiunge i caratteri ‘+’, ‘3’ e ‘9’ all'inizio

OUTPUT ATTESO:
Alessandro IBAN: IT020000000000000 Numero:333333333
Marco IBAN: IT020000000000000 Numero:+3956789
Giacomo IBAN: IT020000000000000 Numero:003956565656
Giovanni IBAN: IT020000000000000 Numero:03456678
Matteo IBAN: IT020000000000000 Numero:4444444

Alessandro IBAN: IT020000000000000 Numero:+39333333333
Marco IBAN: IT020000000000000 Numero:+3956789
Giacomo IBAN: IT020000000000000 Numero:+3956565656
Giovanni IBAN: IT020000000000000 Numero:+3903456678
Matteo IBAN: IT020000000000000 Numero:+394444444*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct c { char c;
                   struct c * next; } Cifra;

typedef Cifra * NumTelefono;

typedef struct con { char nome[1000];
                     char IBAN[1000]; 
					 NumTelefono numero;
					 struct con * next; } Correntista;

typedef Correntista * ListaConti;

NumTelefono InsInTestaCifra( NumTelefono lista, char elem );
NumTelefono InsInFondoCifra( NumTelefono lista,char elem );
ListaConti costruisciListaConti();
NumTelefono costruisciNumero(char * telefono);
ListaConti InsInFondoCorrentista( ListaConti lista, char * nome, char * IBAN, char * telefono );
void Stampa_conti(ListaConti lista);
void Visualizza_conti(ListaConti lista);
NumTelefono Cancella( NumTelefono num, char elem );
NumTelefono Correggi_numero(NumTelefono num);
ListaConti Correggi_conti(ListaConti lista);

int main(){
    ListaConti conti;
	conti=costruisciListaConti();
	// TODO stampa contenuto conti
	Visualizza_conti(conti);
	// TODO correggi i conti
	conti=Correggi_conti(conti);
	// TODO stampa contenuto conti corretti
	printf("\nDopo la correzione\n");
	Visualizza_conti(conti);
}
ListaConti costruisciListaConti(){
    ListaConti lis=NULL;
	int i=0;
	char nomi[5][20]={"Alessandro","Marco","Giacomo","Giovanni","Matteo"};
	char IBAN[5][20]={"IT020000000000000","IT020000000000000","IT020000000000000","IT020000000000000","IT020000000000000"};
	char telefoni[5][20]={"333333333","+3956789","003956565656","03456678","4444444"};
	
	for(i=0;i<5;i++)
	    lis=InsInFondoCorrentista(lis,nomi[i],IBAN[i],telefoni[i]);
		
	return lis;
}

void Stampa_conti(ListaConti lista){
	if(lista==NULL){
		printf("---|\n");
	}
	else{
		printf("\n%s ", lista->nome);
		printf("IBAN: %s ", lista->IBAN);
		NumTelefono temp = lista->numero; // Usa un puntatore temporaneo
        while(temp != NULL){
            printf("%c", temp->c);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Visualizza_conti(ListaConti lista){
	while(lista!=NULL){
		Stampa_conti(lista);
		lista=lista-> next;
	}
}
NumTelefono Correggi_numero(NumTelefono num){
	if(num==NULL){
		return NULL;		
	}
	if(num->c=='+'){
		return num;
	}
	//Caso 00...
	if(num->c=='0' && num->next->c=='0'){
		num=InsInTestaCifra(num->next->next, '+'); //Inserisco il + in testa;
		num=Cancella(num, '0'); //Cancello il primo zero
		num=Cancella(num,'0'); //Cancello il secondo
	return num;
	}
	//Caso 0 oppure !0
	if(num->c=='0' && num->next->c!='0' || num->c !='0'){
		num=InsInTestaCifra(num, '9');
		num=InsInTestaCifra(num, '3');
		num=InsInTestaCifra(num, '+');
		return num;		
	}
}

NumTelefono Cancella( NumTelefono num, char elem ) {
    NumTelefono puntTemp;
	if( num!=NULL)
	    if(num->c == elem ) {
		    puntTemp = num->next;
			free( num );
			return puntTemp; // per cancellare tutte le istanze: return Cancella(PuntTemp, Elem);
        }
		else
		    num->next = Cancella( num->next, elem );
		return num;
}

ListaConti Correggi_conti(ListaConti lista){
	ListaConti temp=lista;
	while(temp!=NULL){
		temp->numero=Correggi_numero(temp->numero);
		temp=temp->next;
	}
	return lista;
}

NumTelefono InsInTestaCifra ( NumTelefono lista, char elem ) {
    NumTelefono punt;
	punt = (NumTelefono) malloc(sizeof(Cifra));
	punt->c = elem; punt->next = lista;
	return punt;
}


NumTelefono InsInFondoCifra( NumTelefono lista,char elem ) {
	NumTelefono punt;
	if( lista==NULL ) {
		punt = (NumTelefono)malloc( sizeof(Cifra) );
		punt->next = NULL; punt->c = elem;
		return punt;
	} else { 
		lista->next = InsInFondoCifra( lista->next, elem );
		return lista;
	}
}


NumTelefono costruisciNumero(char * telefono){
	int i;
	NumTelefono lis=NULL;
	for(i=0;telefono[i]!='\0';i++)
		lis=InsInFondoCifra(lis,telefono[i]);
	return lis;
}


ListaConti InsInFondoCorrentista( ListaConti lista, char * nome, char * IBAN, char * telefono ) {
	ListaConti punt;
	if( lista==NULL ) {
		punt = (ListaConti)malloc( sizeof(Correntista) );
		punt->next = NULL;
		strcpy(punt->nome, nome);
		strcpy(punt->IBAN, IBAN);
		punt->numero=costruisciNumero(telefono);
		return punt;
	} else {
		lista->next = InsInFondoCorrentista( lista->next, nome, IBAN, telefono );
		return lista;
	}
}
