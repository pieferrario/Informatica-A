/*Si considerino i seguenti tipi di dato atti a rappresentare i prodotti di un supermercato:
typedef struct { int giorno, mese, anno; } data
typedef struct ELP {
    char nome[50];
    data giorno_scadenza;
    struct ELP * next;
} NodoP;
typedef NodoP * ListaP;
typedef struct ELS {
     ListaP prodotti;
     struct ELS * next;
} NodoS;
typedef NodoS * ListaS;
Un supermercato è rappresentato da una lista di scaffali (ListaS), ed ogni scaffale (NodoS) contiene a sua volta una lista di prodotti (ListaP). 
Un prodotto (NodoP) è caratterizzato da un nome e da un giorno di scadenza.

Si scriva una funzione eliminaScaduti che riceve in ingresso una lista di scaffali ed una data G rappresentante un giorno dell’anno e che modifica la lista 
in ingresso eliminando dagli scaffali tutti i prodotti il cui giorno di scadenza è antecedente al giorno G in ingresso (se una scaffale resta vuoto lo si lasci pure come lista vuota).

Per risolvere l'esercizio si sviluppi e si invochi la funzione ausiliaria
int primaDi(Data d1, Data d2)
che restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {int giorno, mese, anno;} Data;
typedef struct ELP {
    char nome[50];
    Data giorno_scadenza;
    struct ELP * next;
} NodoP;
typedef NodoP * ListaP;
typedef struct ELS {
    ListaP prodotti;
    struct ELS * next;
} NodoS;
typedef NodoS * ListaS;


/// Funzioni implementate
ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno);
ListaS costruisci();
void stampaData(Data d);
void stampaProdotto(NodoP* prodotto);
void stampaProdotti(ListaP prodotti);
void stampaScaffale(NodoS* scaffale);
void stampaScaffali(ListaS scaffali);
/// -------------------------


/// INSERIRE QUI PROTOTIPI E IMPLEMENTAZIONI DELLE FUNZIONI RICHIESTE
// TODO
int primaDi (Data d1, Data d2);
ListaP Cancella(ListaP lis, char elem[]);
ListaS eliminaScaduti(ListaS lis, Data G);
/// -------------------------------------------------------------------
/// MAIN ED ALTRE FUNZIONI
int main(){
    ListaS scaffali = costruisci();
    Data G = {5, 9, 2022};
    printf("Data di scadenza: "); stampaData(G); printf("\n\n");
    printf("Prima della rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);


    /// INSERIRE QUI LE CHIAMATE A FUNZIONE
    // TODO
    /// -----------------------------------

	scaffali=eliminaScaduti(scaffali, G);
    printf("Dopo la rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);
    return 0;
}

int primaDi (Data d1, Data d2){
	if (d1.anno < d2.anno) return 1;
    if (d1.anno > d2.anno) return 0;

    if (d1.mese < d2.mese) return 1;
    if (d1.mese > d2.mese) return 0;

    if (d1.giorno < d2.giorno) return 1;
    
    return 0;
}

ListaP Cancella(ListaP lis, char elem[50]){
    ListaP puntTemp;
	if( lis!=NULL)
	    if( strcmp(lis->nome, elem)==0 ) {
		    puntTemp = lis->next;
			free(lis);
			return puntTemp; // per cancellare tutte le istanze: return Cancella(PuntTemp, Elem);
        }
		else
		    lis->next = Cancella( lis->next, elem );
		return lis;
}

ListaS eliminaScaduti(ListaS lis, Data G){
	ListaS curr_s=lis;
	if(lis==NULL){
		return NULL;
	}
	while(curr_s!=NULL){
		ListaP curr_p=curr_s->prodotti, prec_p=NULL;
		while(curr_p!=NULL){
			if(primaDi(curr_p->giorno_scadenza, G)){
				if(prec_p==NULL){
					curr_s->prodotti=Cancella(curr_p, curr_p->nome);
					curr_p=curr_s->prodotti;
				}
				else{
					curr_p=Cancella(curr_p,curr_p->nome);
					prec_p->next=curr_p;
				}
			}
			else{
				prec_p=curr_p;
				curr_p=curr_p->next;
			}
		}
		curr_s=curr_s->next;		
		}
	return lis;
}

ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno){
    if(prodotti == NULL){
        prodotti = (ListaP) malloc(sizeof(NodoP));
        Data scad = {giorno, mese, anno}; strcpy(prodotti->nome, nome); prodotti->giorno_scadenza = scad; prodotti->next = NULL;
        return prodotti;
    } else { prodotti->next = aggiungiProdotto(prodotti->next, nome, giorno, mese, anno); return prodotti;}
}
ListaS costruisci(){
    ListaS scaffali = NULL;
    scaffali = (ListaS) malloc(sizeof(NodoS));scaffali->prodotti = NULL; scaffali->next = NULL;
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Pasta", 14, 7, 2027);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Riso", 8, 11, 2020);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Farro", 9, 3, 2029);
    scaffali->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->prodotti = NULL; scaffali->next->next = NULL;
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Biscotti", 4, 6, 2020);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Cereali", 2, 7, 2025);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Toast", 1, 3, 2018);
    scaffali->next->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->next->prodotti = NULL; scaffali->next->next->next = NULL;
	scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "More", 7, 9, 2016);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Lamponi", 25, 12, 2017);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Ribes", 18, 5, 2010);
    return scaffali;
}
void stampaData(Data d){ printf("%d/%d/%d", d.giorno, d.mese, d.anno); }
void stampaProdotto(NodoP* prodotto){printf(" ~ %s in scadenza il ", prodotto->nome);stampaData(prodotto->giorno_scadenza);}
void stampaProdotti(ListaP prodotti){
    if(prodotti == NULL){ printf(" * \n"); return; }
    stampaProdotto(prodotti); printf("\n"); stampaProdotti(prodotti->next);
}
void stampaScaffale(NodoS* scaffale){printf("+ - - -\n"); stampaProdotti(scaffale->prodotti);}
void stampaScaffali(ListaS scaffali){
    if(scaffali == NULL){ printf("+ _ _ _\n\n"); return; }
    stampaScaffale(scaffali);stampaScaffali(scaffali->next);
}

