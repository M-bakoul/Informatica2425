#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elementi;
    int head;
    int tail;
    int lunghezza;
    int capacita;
} Coda;

Coda* creaCodaArray(int capacita) {
    Coda* coda = (Coda*)malloc(sizeof(Coda));
    coda->elementi = (int*)malloc(capacita * sizeof(int));
    coda->head = 0;
    coda->tail = -1;
    coda->lunghezza = 0;
    coda->capacita = capacita;
    return coda;
}

void enqueueArray(Coda* coda, int valore) {
    if (coda->lunghezza >= coda->capacita) {
        printf("Errore: coda piena\n");
        return;
    }
    
    coda->tail = (coda->tail + 1) % coda->capacita;
    coda->elementi[coda->tail] = valore;
    coda->lunghezza++;
}

int dequeueArray(Coda* coda) {
    if (coda->lunghezza <= 0) {
        printf("Errore: coda vuota\n");
        return -1;
    }
    
    int valore = coda->elementi[coda->head];
    coda->head = (coda->head + 1) % coda->capacita;
    coda->lunghezza--;
    
    return valore;
}

int main(){
    int dim1;
    printf("Inserisic dim: ");
    scanf("%d", dim1);
    
    Coda* coda = creaCodaArray(dim1);

}