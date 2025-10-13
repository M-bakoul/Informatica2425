/*
 Alloca un array dinamico di interi. Chiedi all’utente di inserire 
 valori finché non inserisce 0. Ad ogni inserimento usa realloc.
 Alla fine ordina l’array in ordine crescente e stampa i valori.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main() {
    array vett = NULL;
    int dim = 0;
    int val;

    printf("Inserisci numeri (0 per terminare):\n");

    while(1) {
        printf("Numero: ");
        scanf("%d", &val);

        if(val == 0) break;  // termina l'inserimento

        dim++;  // aumenta la dimensione

        array temp = (array) realloc(vett, dim * sizeof(int));
        if(temp == NULL) {
            printf("Errore di riallocazione\n");
            free(vett);
            return 1;
        }

        vett = temp;
        vett[dim - 1] = val;  // inserisci il nuovo valore in fondo
    }

    if(dim == 0) {
        printf("Nessun valore inserito.\n");
        return 0;
    }

    // Ordinamento crescente (bubble sort)
    for(int i = 0; i < dim - 1; i++) {
        for(int j = 0; j < dim - i - 1; j++) {
            if(vett[j] > vett[j + 1]) {
                int temp = vett[j];
                vett[j] = vett[j + 1];
                vett[j + 1] = temp;
            }
        }
    }

    // Stampa array ordinato
    printf("\nArray ordinato: ");
    for(int i = 0; i < dim; i++) {
        printf("%d ", vett[i]);
    }
    printf("\n");

    free(vett);
    return 0;
}
