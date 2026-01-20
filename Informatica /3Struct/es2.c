#include <stdio.h>
#include <stdlib.h>

int main(){

    struct Persona{
        char nome[10];
        char cognome[10];
        int eta;
    };

    struct Persona *persona1 = malloc(sizeof(struct Persona));

    if(persona1 == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    printf("Inserisci nome: ");
    scanf("%s", persona1->nome);
    printf("Inserisci cognome: ");
    scanf("%s", persona1->cognome);
    printf("Inserisci eta: ");
    scanf("%d", &persona1->eta);

    printf("%s ha %d anni \n", persona1->nome, persona1 ->eta);

    free(persona1);
}