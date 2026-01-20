/* 
 Alloca dinamicamente un array di dimensione n inserita dall’utente.
 Calcola e stampa il massimo e il minimo.
 */



#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){
    array vett= NULL;
    int dim;

    
    printf("Inserisci dim: ");
    scanf("%d", &dim);

    vett = (array)malloc(dim * sizeof(int));
    
    if(vett == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<dim; i++){
        printf("Inserisci elemento %d: ", i);
        scanf("%d", &vett[i]);
    }

    int max=vett[0];
    int min=vett[0];
    
    for(int i=0; i<dim; i++){
        if (max < vett[i]){
            max= vett[i];
        }
        if (min> vett[i]){
            min = vett[i];
        }
    }

    printf("il min: %d, il max: %d ", min, max);


    free(vett);


}
