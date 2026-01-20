/* 
  Scrivi un programma che chieda all’utente il numero di elementi n
   di un array di interi, li legga da tastiera usando malloc, calcoli
   la somma e stampi il risultato.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){
    array vett = NULL;
    int dim;
    int somma=0;

    printf("Inserisci dim: ");
    scanf("%d", &dim);

    vett = (array)malloc(dim * sizeof(int));

    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<dim; i++){
        printf("Inserisci elemento %d: ", i);
        scanf(" %d", &vett[i]);
    }

    for(int i=0; i<dim; i++){
        somma += vett[i];
    }

    printf("%d", somma);
    free(vett);
}

