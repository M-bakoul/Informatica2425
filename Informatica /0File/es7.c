#include <stdio.h>
#include <string.h>

typedef struct Persona {
    char nome[30];
    char cognome[30];
    int eta;
} Persona;


void crea_persona(Persona *p) {
    printf("Inserisci nome: ");
    fgets(p->nome, 30, stdin);

    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("Inserisci cognome: ");
    fgets(p->cognome, 30, stdin);
    p->cognome[strcspn(p->cognome, "\n")] = 0;

    printf("Inserisci eta: ");
    scanf("%d", &(p->eta));

    while (getchar() != '\n'); 
}


void salva_dati_bin(Persona p) {
    FILE* fl = fopen("dati.bin", "wb");
    if (fl == NULL) {
        printf("Errore di apertura file\n");
        return;
    }

    fwrite(&p, sizeof(Persona), 1, fl);
    fclose(fl);
    printf("\n--- Studente salvato in binario ---\n");
}


void leggi_file_bin() {
    Persona letto;
    FILE* fl = fopen("dati.bin", "rb");
    if (fl == NULL) return;

    if (fread(&letto, sizeof(Persona), 1, fl) == 1) {
        printf("Persona caricata: %s %s, Eta: %d\n", letto.nome, letto.cognome, letto.eta);
    }
    fclose(fl);
}


int main() {
    Persona p1;
    
    crea_persona(&p1);    
    salva_dati_bin(p1);   
    leggi_file_bin();

    return 0;
}