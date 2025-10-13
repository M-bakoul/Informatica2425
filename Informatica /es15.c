/*
 Alloca un array dinamico di n interi. Chiedi all’utente l’indice 
 di un elemento da rimuovere. Sposta gli elementi successivi indietro e
 ridimensiona l’array con realloc. 
 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quanti elementi vuoi inserire? ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Errore di allocazione\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    int idx;
    printf("Inserisci l'indice dell'elemento da rimuovere (0-%d): ", n-1);
    scanf("%d", &idx);

    if(idx < 0 || idx >= n){
        printf("Indice non valido!\n");
        free(arr);
        return 1;
    }

    for(int i = idx; i < n - 1; i++){
        arr[i] = arr[i+1];
    }

    n--;
    int *temp = (int*) realloc(arr, n * sizeof(int));
    if(temp == NULL && n > 0){
        printf("Errore di riallocazione\n");
        free(arr);
        return 1;
    }
    arr = temp;

    printf("Array aggiornato: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
