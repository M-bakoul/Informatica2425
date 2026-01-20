/* Visualizzare le squadre il cui allenatore presenta più di
10 titoli e un punteggio della squadra superiore a 30*/


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nomeAllenatore[30];
    char cognomeAllenatore[30];
    int titoli;
}mister;

typedef struct{
    char nome[30];
    char colore[30];
    int punteggio;
    mister mister;
}squadra;


void InserisciSquadra(squadra* squadre, int * dim){
    squadra s1;

    printf("Inserisci nome squadra: ");
    fgets(s1.nome, 30, stdin);
    printf("Inserisci colore squadra: ");
    fgets(s1.colore, 30, stdin);
    printf("Inserisci punteggio della squadra: ");
    scanf("%d", &s1.punteggio);
    getchar();

    printf("Inserisci nome mister: ");
    fgets(s1.mister.nomeAllenatore, 30, stdin);
    printf("Inserisci cognome mister: ");
    fgets(s1.mister.cognomeAllenatore, 30, stdin);
    printf("Inserisci titoli del mister: ");
    scanf("%d", &s1.mister.titoli);
    getchar();

    squadre[*dim] = s1;
    (*dim)++;
}


void PepGuardiola(squadra* squadre, int dim){
    for(int i=0; i<dim; i++){
        if(squadre[i].mister.titoli > 10 && squadre[i].punteggio > 30){
            printf("\nSquadra %s, punteggio: %d, mister con titoli: %d", squadre[i].nome, squadre[i].punteggio, squadre[i].mister.titoli);
        }
    }
}


int main(){
    int scelta;
    int dim = 1;
    squadra* squadre = (squadra*)malloc(dim * sizeof(squadra));

    if(squadre == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    do {
        printf("\n--- ALLENATORI ---\n");
        printf("1. Inserisci squadra\n");
        printf("2. Stampa mister vincenti\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar(); // pulisci buffer input

        switch (scelta) {
            case 1:
                if (dim < 10) {
                    InserisciSquadra(squadre, &dim);
                } else {
                    printf("Hai superato 10 squadre \n");
                }
                break;
            case 2:
                PepGuardiola(squadre, dim);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 0);
}