/* creare una struct squadra contenente le seguenti
info: nome, colore, punteggio.
caricato un massimo di 10 squadre stampare quelle
con punteggio superiore a 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
}S;

void aggiungiSquadra(S* Squadre, int* dimSquadre);
void stampaPunteggi(S* Squadre, int dimSquadre);


void puliscibuffer(){
    int c;
    while((c = getchar()) != '\n') {}
}

int main() {
    int dimSquadre = 0;
    S* Squadre = (S*)malloc(10 * sizeof(S)); 
    int scelta;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserisci nuova squadra: \n");
        printf("2. Stampa squadre: \n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                if (dimSquadre < 10) {
                    aggiungiSquadra(Squadre, &dimSquadre);
                } else {
                    printf("Hai superato 10 squadre \n");
                }
                break;
            case 2:
                stampaPunteggi(Squadre, dimSquadre);
                break;
            default:
                break;
        }
    } while (scelta != 0);

    free(Squadre);
    return 0;
}


void aggiungiSquadra(S* Squadre, int * dimSquadre){
    S Squadra0;

    printf("Inserisci nome della Squadra: ");
    fgets(Squadra0.nome, 20, stdin);
    
    printf("Inserisci colore della Squadra: ");
    fgets(Squadra0.colore, 20, stdin);
    
    printf("Inserisci punteggio della Squadra: ");
    scanf("%d", &Squadra0.punteggio);
    getchar();
    Squadre[*dimSquadre] = Squadra0;
    (*dimSquadre)++;
}

void stampaPunteggi(S* Squadre, int dimSquadre) {
    for (int i = 0; i < dimSquadre; i++) {
        if (Squadre[i].punteggio > 100) {
            printf("Squadra %s: Punteggio:%d \n", Squadre[i].nome , Squadre[i].punteggio);
        }
    }
}