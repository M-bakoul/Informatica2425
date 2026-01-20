/* 
registrare le informazioni di alcuni libri titolo, autore, anno di pubblicazione
array libri
caricare l'array
pubblicare
rimuovere un libro

cercare un libro in base al titolo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char titolo[30];
    char autore[30];
    int annoPubblicazione;
}Libro;

void caricaLibro(Libro* array, int* dim){
    Libro nuovoLibro;
    printf("Inserisci titolo del libro: ");
    fgets(nuovoLibro.titolo, 30+1, stdin);
    printf("Inserisci autore del libro: ");
    fgets(nuovoLibro.autore, 30+1, stdin);
    printf("Inserisci anno di pubblicazione: ");
    scanf("%d", &nuovoLibro.annoPubblicazione);

    array[*dim] = nuovoLibro;
    (*dim)++;

}

void rimuoviLibro(Libro* array, int dim){
    int indice;
    printf("Inserisci il libro da rimuovere (con indice): ");
    scanf("%d", &indice);

    if(indice>dim){
        printf("Errore.");
        return 1;
    }


    for(int i=indice; i<dim; i++){
        array[i] = array[i+1];
    }
    dim -= 1;
}

void cercaLibro(Libro* array, int dim){
    char s1[30];
    printf("Inserisci titolo per cercare il libro: ");
    fgets(s1, 30+1, stdin);

    for(int i=0; i<dim; i++){
        if(s1 == array[i].titolo){
            printf("Libro trovato (indice: %d): %s, %s, %d", i+1, array[i].titolo, array[i].autore, array[i].annoPubblicazione);
        }
    }
}

void visualizzaLibri(Libro* array, int dim){
    for(int i=0; i<dim; i++){
        printf("Libro indice %d: titolo: %s autore: %s anno di pubblicazione: %d \n", i+1, array[i].titolo , array[i].autore, array[i].annoPubblicazione);
    }
}


int main(){
    Libro* array = (Libro*)malloc(10 * sizeof(Libro));
    int dim=0, scelta;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Carica un libro  \n");
        printf("2. Rimuovi un libro\n");
        printf("3. Cerca un libro\n");
        printf("4. Visualizza tutti i libri\n");


        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                if (dim < 10) {
                    caricaLibro(array, &dim);
                } else {
                    printf("Hai superato 10 squadre \n");
                }
                break;
            case 2:
                rimuoviLibro(array, dim);
                break;
            case 3:
                cercaLibro(array, dim);
                break;
            case 4:
                visualizzaLibri(array, dim);
                break;
            default:
                break;
        }
    } while (scelta != 0);

}
