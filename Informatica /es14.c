/*
 Leggi n interi in un array dinamico arr. Poi crea un nuovo array copy 
 usando malloc e copia tutti gli elementi di arr in copy. Stampa copy.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){
    array vett= NULL;
    array copy= NULL;
    int dim;

    printf("Inserisci dim: ");
    scanf("%d", &dim);

    vett=(array)malloc(dim* sizeof(int));
    copy=(array)malloc(dim* sizeof(int));

    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    if(copy==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i = 0; i<dim; i++){
        printf("Inserisci elemento %d: ", i);
        scanf("%d", &vett[i]);
    }

    for(int i=0; i<dim; i++){
        copy[i] = vett[i];
    }

    for(int i=0; i<dim; i++){
        printf("%i", copy[i]);
    }

    
    
    free(vett);
    free(copy);
    
}
