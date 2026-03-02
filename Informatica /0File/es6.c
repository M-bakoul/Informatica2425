/*Crea un programma che permetta di salvare i dati 
di alcuni studenti (Nome, Cognome, Media Voti)*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Persona{
    char nome[30];
    char cognome[30];
    int eta;
}Persona;

int main() {
    FILE *file = NULL;
    Persona persona;

    file = fopen("dati.txt", "w");
    if(file == NULL){
        printf("Errore di apertura file");
        return 1;
    }

    printf("Insersci nome: ");
    fgets(persona.nome, 30, stdin);
    printf("Insersci cognome: ");
    fgets(persona.cognome, 30, stdin);
    printf("Insersci eta: ");
    scanf("%d", &persona.eta);

    fputs(persona.nome, file);
    fputs(persona.cognome, file);
    fprintf(file, "%d", persona.eta);

    fclose(file);
    return 0;
}