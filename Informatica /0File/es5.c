#include <stdio.h>

int main() {
    FILE *sorgente = fopen("sorgente.txt", "r");
    FILE *destinazione = fopen("copia.txt", "w");

   
    if (sorgente == NULL || destinazione == NULL) {
        printf("Errore nell'apertura dei file!\n");
        return 1;
    }

    int ch; 
    
    while ((ch = fgetc(sorgente)) != EOF) {
        fputc(ch, destinazione); 
    }

    printf("Copia completata con successo.\n");

    fclose(sorgente);
    fclose(destinazione);

    return 0;
}